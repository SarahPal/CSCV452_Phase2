/* ------------------------------------------------------------------------
    phase2.c
    University of Arizona South
    Computer Science 452
    ------------------------------------------------------------------------ */

#include <phase1.h>
#include <phase2.h>
#include <usloss.h>
#include <stdio.h>
#include <string.h>

#include "message.h"


/* ------------------------- Prototypes ----------------------------------- */
int start1 (char *);
extern int start2 (char *);

int MboxCreate(int slots, int slot_size);
int SlotCreate(void *msg_ptr, int msg_size);
int MboxSend(int mbox_id, void *msg_ptr, int msg_size);
int MboxReceive(int mbox_id, void *msg_ptr, int msg_size);
int MboxRelease(int mailboxID);
int MboxCondSend(int mailboxID, void *message, int message_size);
int MboxCondReceive(int mailboxID, void *message, int max_message_size);
int waitdevice(int type, int unit, int *status);
int getInactive();

static void check_kernel_mode(char *caller_name);
static void enable_interrupts(char *caller_name);
static void disable_interrupts(char *caller_name);


/* -------------------------- Globals ------------------------------------- */

int debugflag2 = 0;
int numMailboxes = 0;
int next_slot_id = 0;
int num_slots = 0;

/* the mail boxes */
mail_box MailBoxTable[MAXMBOX];
mail_slot Mail_Slots[MAXSLOTS];

//Define a new Process Table
proc_struct ProcTable[MAXPROC];

/* -------------------------- Functions ----------------------------------- */

/* ------------------------------------------------------------------------
    Name - start1
    Purpose - Initializes mailboxes and interrupt vector.
              Start the phase2 test process.
    Parameters - one, default arg passed by fork1, not used here.
    Returns - one to indicate normal quit.
    Side Effects - lots since it initializes the phase2 data structures.
    ----------------------------------------------------------------------- */
int start1(char *arg)
{

    int kid_pid;
    int status;
    if (DEBUG2 && debugflag2)
       console("start1(): at beginning\n");

    check_kernel_mode("start1");

    /* Disable interrupts */
    disable_interrupts("start1");

    /* Initialize the mail box table, slots, & other data structures.
    * Initialize int_vec and sys_vec, allocate mailboxes for interrupt
    * handlers.  Etc... */

  //Initialize mailboxes
    for(int i = 0; i <= MAXMBOX; i++)
    {
       MailBoxTable[i].mbox_id = i;
       MailBoxTable[i].status = INACTIVE;
       MailBoxTable[i].num_slots = -1;
    }
  //Initialze mail_slots table
    for(int i = 0; i < MAXSLOTS; i++)
    {
        Mail_Slots[i].mbox_id = -1;
        Mail_Slots[i].slot_id = -1;
        Mail_Slots[i].status = EMPTY;
        Mail_Slots[i].next_slot = NULL;
    }

    /* initialize the Process Table */
    for (int i = 1; i <= MAXPROC; i++)
    {
       ProcTable[i].status = UNUSED;
       ProcTable[i].next_proc_ptr = NULL;
    }
  //TODO: initialize int_vec
  //TODO: initialize sys_vec

  //Interrupt mailboxes.
    int IntHandMB[7];

    IntHandMB[CLOCKMB] = MboxCreate(0, sizeof(int)); //Clock MB
    IntHandMB[TERMMB] = MboxCreate(0, sizeof(int)); //Terminal 1
    IntHandMB[TERMMB + 1] = MboxCreate(0, sizeof(int)); //Terminal 2
    IntHandMB[TERMMB + 2] = MboxCreate(0, sizeof(int)); //Terminal 3
    IntHandMB[TERMMB + 3] = MboxCreate(0, sizeof(int)); //Terminal 4
    IntHandMB[DISKMB] = MboxCreate(0, sizeof(int)); //Disk 1
    IntHandMB[DISKMB + 1] = MboxCreate(0, sizeof(int)); //Disk 2


    enable_interrupts("start1");

    /* Create a process for start2, then block on a join until start2 quits */
    if (DEBUG2 && debugflag2)
       console("start1(): fork'ing start2 process\n");
    kid_pid = fork1("start2", start2, NULL, 4 * USLOSS_MIN_STACK, 1);
    if ( join(&status) != kid_pid ) {
       console("start2(): join returned something other than start2's pid\n");
    }

    return 0;
} /* start1 */


/* ------------------------------------------------------------------------
    Name - MboxCreate
    Purpose - gets a free mailbox from the table of mailboxes and initializes it
    Parameters - maximum number of slots in the mailbox and the max size of a msg
                 sent to the mailbox.
    Returns - -1 to indicate that no mailbox was created, or a value >= 0 as the
              mailbox id.
    Side Effects - initializes one element of the mail box array.
    ----------------------------------------------------------------------- */
int MboxCreate(int slots, int slot_size)
{

    check_kernel_mode("MboxCreate");
    disable_interrupts("MboxCreate");
    int next_Available = getInactive();

    if(next_Available == -1)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxCreate: max boxes reached, returning...");
        }
        return -1;
    }
    mail_box *nBox = &MailBoxTable[next_Available];

    nBox->mbox_id = next_Available++;
    nBox->num_slots = slots;
    nBox->slot_size = slot_size;
    nBox->status = ACTIVE;
    nBox->used_slots = 0;
    nBox->blocking = -1;

    if(DEBUG2 && debugflag2)
    {
        console("Created mailbox with id %d, total slots = %d, slot size = %d\n",
        nBox->mbox_id, nBox->num_slots,nBox->slot_size);
    }
    enable_interrupts("MboxCreate");
    return nBox->mbox_id;
} /* MboxCreate */

int SlotCreate(void *msg_ptr, int msg_size)
{
    check_kernel_mode("SlotCreate");
    disable_interrupts("SlotCreate");

    slot_ptr slot = &Mail_Slots[next_slot_id];
    slot->slot_id = next_slot_id++;
    slot->status = USED;
    slot->message_size = msg_size;
    num_slots++;

    memcpy(slot->message, msg_ptr, msg_size);

    if(DEBUG2 && debugflag2)
        console("SlotCreate(): Created new slot with slot ID: %d \n", slot->slot_id);
    enable_interrupts("SlotCreate");

  //console("Slot ID: %d\n", slot->slot_id);
    return slot->slot_id;

} /* SlotCreate */


/* ------------------------------------------------------------------------
    Name - MboxSend
    Purpose - Put a message into a slot for the indicated mailbox.
              Block the sending process if no slot available.
    Parameters - mailbox id, pointer to data of msg, # of bytes in msg.
    Returns - zero if successful, -1 if invalid args.
    Side Effects - none.
    ----------------------------------------------------------------------- */
int MboxSend(int mbox_id, void *msg_ptr, int msg_size)
{
    check_kernel_mode("MboxSend");
    disable_interrupts("MboxSend");
    mail_box *mbox = &(MailBoxTable[mbox_id]);

    if(DEBUG2 && debugflag2)
        console("MboxSend(): Checking for possible errors...\n");

  //Check for possible errors
    if(mbox_id < 0 || mbox_id >= MAXMBOX)
    {
        if(DEBUG2 && debugflag2)
             console("MboxSend(): Invalid Mailbox ID. Returning...\n");
        enable_interrupts("MboxSend");
        return -1;
    }

    if(MailBoxTable[mbox_id].status == INACTIVE)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxSend(): Mailbox is inactive. Returning...\n");
        }
        enable_interrupts("MboxSend");
        return -1;
    }
    if(msg_size > MAX_MESSAGE)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxSend(): Messgae sent has exceeded max length. Returning...\n");
        }
        enable_interrupts("MboxSend");
        return -1;
    }
    mail_box *nBox = &MailBoxTable[mbox_id];

    if(nBox->status == INACTIVE || msg_size < 0 || msg_size > nBox->slot_size)
    {
        if(DEBUG2 && debugflag2)
             console("MboxSend(): Invalid argument(s). Returning...\n");
        enable_interrupts("MboxSend");
        return -1;
    }

  //If the Mail slot overflows, halt usloss
    if(num_slots == MAXSLOTS)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxSend(): Mailslot has overflowed. Halting...\n");
        }
        halt(1);
    }

  //Checks if there are no unused slots in the mailbox. Increments the count
  // if there are, otherwise blocks current process
    if (mbox->used_slots < mbox->num_slots)
        mbox->used_slots += 1;

    else
    {
        if (mbox->blocking == -1)
        {
            mbox->blocking = getpid()%MAXPROC;
            ProcTable[mbox->blocking].ishead = TRUE;
        }

        else
        {
            proc_ptr temp = &ProcTable[mbox->blocking];
            while(temp->next_proc_ptr != NULL)
                temp = temp->next_proc_ptr;
            temp->next_proc_ptr = &ProcTable[getpid()%MAXPROC];
        }
        ProcTable[getpid()%MAXPROC].pid = getpid();
        ProcTable[getpid()%MAXPROC].status = SEND_BLOCK;
        block_me(SEND_BLOCK);
        mbox->used_slots += 1;
    }


  //Checks if the mailbox was closed during block
    if (mbox->mbox_id == -1)
    {
        enable_interrupts("MboxSend");
        return -3;
    }


  //Copy message into allocated slot (use memcpy or strcpy)
    int nSlot_id = SlotCreate(msg_ptr, msg_size);
    slot_ptr slot = &Mail_Slots[nSlot_id];

  //Add slot to mailbox
    if (mbox->head == NULL)
        mbox->head = slot;
    else
        mbox->end->next_slot = slot;

    mbox->end = slot;
    num_slots++;

  //Unblocks reciever if blocked while waiting for message
    if (nBox->blocking != -1)
    {
        int Found = FALSE;
        proc_ptr temp = &ProcTable[nBox->blocking];
        proc_ptr prev = &ProcTable[nBox->blocking];
        while (temp != NULL && Found == FALSE)
        {
            if (temp->status == RECEIVE_BLOCK)
            {
                if (temp == prev)
                {
                    if (temp->next_proc_ptr != NULL)
                        mbox->blocking = temp->next_proc_ptr->pid;
                    else
                        mbox->blocking = -1;
                }
                else
                    prev->next_proc_ptr = temp->next_proc_ptr;
                Found = TRUE;
                unblock_proc(temp->pid);
                temp->status = UNUSED;
            }
            prev = temp;
            temp = temp->next_proc_ptr;
        }
    }

    enable_interrupts("MboxSend");
    return 0;

} /* MboxSend */


/* ------------------------------------------------------------------------
    Name - MboxReceive
    Purpose - Get a msg from a slot of the indicated mailbox.
              Block the receiving process if no msg available.
    Parameters - mailbox id, pointer to put data of msg, max # of bytes that
                 can be received.
    Returns - actual size of msg if successful, -1 if invalid args.
    Side Effects - none.
    ----------------------------------------------------------------------- */
int MboxReceive(int mbox_id, void *msg_ptr, int msg_size)
{

    check_kernel_mode("mBoxReceive");
    disable_interrupts("MboxReceive");

    int size;
    mail_box *mbox = &(MailBoxTable[mbox_id]);

  //MailBox is inactive
    if(MailBoxTable[mbox_id].status == INACTIVE)
    {
      //Some error message
        return -1;
    }

  //Block the receiver if there are not messages in the mailbox
    if (mbox->used_slots > 0)
        mbox->used_slots += 1;

    else
    {
        if (mbox->blocking == -1)
        {
            mbox->blocking = getpid()%MAXPROC;
            ProcTable[mbox->blocking].ishead = TRUE;
        }

        else
        {
            proc_ptr temp = &ProcTable[mbox->blocking];
            while(temp->next_proc_ptr != NULL)
                temp = temp->next_proc_ptr;
            temp->next_proc_ptr = &ProcTable[getpid()%MAXPROC];
        }
        ProcTable[getpid()%MAXPROC].pid = getpid();
        ProcTable[getpid()%MAXPROC].status = RECEIVE_BLOCK;
        block_me(RECEIVE_BLOCK);
        mbox->used_slots += 1;
    }


  //If one (or more) messages are available in the mailbox, memcpy the
  //message from the slot to the receiver's buffer
  //TODO: This crap
    size = mbox->head->message_size;

    memcpy(msg_ptr, mbox->head->message, msg_size);

  //Free the mailbox slot
    slot_ptr temp = mbox->head;
    mbox->head = mbox->head->next_slot;

  //Update Mail_Slot structure
    Mail_Slots[mbox_id].mbox_id = -1;
    Mail_Slots[mbox_id].status = EMPTY;
    Mail_Slots[mbox_id].slot_id = -1;
    num_slots--;

  //Unblocks sender if blocked while waiting to send message
    if (mbox->blocking != -1)
    {
        int Found = FALSE;
        proc_ptr temp = &ProcTable[mbox->blocking];
        proc_ptr prev = &ProcTable[mbox->blocking];
        while (temp != NULL && Found == FALSE)
        {
            if (temp->status == SEND_BLOCK)
            {
                if (temp == prev)
                {
                    if (temp->next_proc_ptr != NULL)
                        mbox->blocking = (temp->next_proc_ptr)->pid;
                    else
                        mbox->blocking = -1;
                }
                else
                    prev->next_proc_ptr = temp->next_proc_ptr;
                Found = TRUE;
                unblock_proc(temp->pid);
                temp->status = UNUSED;
            }
            prev = temp;
            temp = temp->next_proc_ptr;
        }
    }

    enable_interrupts("MboxReceive");
    return size;
} /* MboxReceive */


/* ------------------------------------------------------------------------
    Name - MboxRelease
    Purpose - Releases a previously created mailbox.
    Parameters - mailbox id
    Returns -
          -3: process was zap'd while releasing the mailbox.
          -1: the mailboxID is not a mailbox that is in use.
           0: successful completion.
    Side Effects - Any process waiting on the mailbox should be zap'd
    ----------------------------------------------------------------------- */

int MboxRelease(int mailboxID)
{
    check_kernel_mode("MboxRelease");
    disable_interrupts("MboxRelease");

    mail_box *mbox = &(MailBoxTable[mailboxID]);

    if(mailboxID < 0 || mailboxID >= MAXMBOX)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxRelease(): Invalid mailboxID. Returning -1", mailboxID);
        }
        return -1;
    }

    MailBoxTable[mailboxID].mbox_id = -1;
    slot_ptr t = NULL;
    slot_ptr slot = mbox->head;

    while(slot != NULL)
    {
        slot->mbox_id = -1;
        slot->status = UNUSED;
        slot->message[0] = '\0';
        slot->message_size = -1;
        slot = slot->next_slot;
    }

    MailBoxTable[mailboxID].mbox_id = -1;
    MailBoxTable[mailboxID].status = INACTIVE;
    MailBoxTable[mailboxID].num_slots = -1;
    MailBoxTable[mailboxID].slot_size = -1;
    MailBoxTable[mailboxID].head = NULL;
    MailBoxTable[mailboxID].end = NULL;

    proc_ptr temp = &ProcTable[MailBoxTable[mailboxID].blocking];
    while(temp != NULL)
    {
        unblock_proc(temp->pid);
        temp = temp->next_proc_ptr;
    }
    MailBoxTable[mailboxID].blocking = -1;

    enable_interrupts("MboxRelease");
    return 0;
} /* MboxRelease */


/* ------------------------------------------------------------------------
    Name - MboxCondSend
    Purpose - Conditionally send a message to a mailbox
              Does not block the invoking process.
    Parameters - mailbox id, pointer to put data of msg, max # of bytes that
                 can be received.
    Returns -
          -3: process is zap'd.
          -2: mailbox full, message not sent; or no mailbox slots available in the system.
          -1: illegal values given as arguments.
           0: message sent successfully.
    Side Effects - none.
    ----------------------------------------------------------------------- */
int MboxCondSend(int mailboxID, void *message, int message_size)
{
    check_kernel_mode("MboxCondSend");
    disable_interrupts("MboxCondSend");
    mail_box *mbox = &(MailBoxTable[mailboxID]);

    if(DEBUG2 && debugflag2)
        console("MboxCondSend(): Checking for possible errors...\n");

  //Check for possible errors
    if(mailboxID < 0 || mailboxID >= MAXMBOX)
    {
        if(DEBUG2 && debugflag2)
             console("MboxCondSend(): Invalid Mailbox ID. Returning...\n");
        enable_interrupts("MboxCondSend");
        return -1;
    }

    if(MailBoxTable[mailboxID].status == INACTIVE)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxCondSend(): Mailbox is inactive. Returning...\n");
        }
        enable_interrupts("MboxCondSend");
        return -1;
    }
    if(message_size > MAX_MESSAGE)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxCondSend(): Messgae sent has exceeded max length. Returning...\n");
        }
        enable_interrupts("MboxCondSend");
        return -1;
    }
    mail_box *nBox = &MailBoxTable[mailboxID];

    if(nBox->status == INACTIVE || message_size < 0 || message_size > nBox->slot_size)
    {
        if(DEBUG2 && debugflag2)
             console("MboxCondSend(): Invalid argument(s). Returning...\n");
        enable_interrupts("MboxCondSend");
        return -1;
    }

  //If the Mail slot overflows, halt usloss
    if(num_slots == MAXSLOTS)
    {
        if(DEBUG2 && debugflag2)
        {
             console("MboxCondSend(): Mailslot has overflowed. Halting...\n");
        }
        halt(1);
    }

  //Checks if there are no unused slots in the mailbox. Increments the count
  // if there are, otherwise blocks current process
    if (mbox->used_slots < mbox->num_slots)
        mbox->used_slots += 1;

    else
    {
        if(DEBUG2 && debugflag2)
             console("MboxCondSend(): No room in mailbox. Returning...\n");
        enable_interrupts("MboxCondSend");
        return -2;
    }


  //Copy message into allocated slot (use memcpy or strcpy)
    int nSlot_id = SlotCreate(message, message_size);
    slot_ptr slot = &Mail_Slots[nSlot_id];

  //Add slot to mailbox
    if (mbox->head == NULL)
        mbox->head = slot;
    else
        mbox->end->next_slot = slot;

    mbox->end = slot;
    num_slots++;

  //Unblocks reciever if blocked while waiting for message
    if (nBox->blocking != -1)
    {
        int Found = FALSE;
        proc_ptr temp = &ProcTable[nBox->blocking];
        proc_ptr prev = &ProcTable[nBox->blocking];
        while (temp != NULL && Found == FALSE)
        {
            if (temp->status == RECEIVE_BLOCK)
            {
                if (temp == prev)
                {
                    if (temp->next_proc_ptr != NULL)
                        mbox->blocking = temp->next_proc_ptr->pid;
                    else
                        mbox->blocking = -1;
                }
                else
                    prev->next_proc_ptr = temp->next_proc_ptr;
                Found = TRUE;
                unblock_proc(temp->pid);
                temp->status = UNUSED;
            }
            prev = temp;
            temp = temp->next_proc_ptr;
        }
    }

    enable_interrupts("MboxCondSend");
    return 0;
} /* MboxCondSend */


/* ------------------------------------------------------------------------
    Name - MboxCondReceive
    Purpose - Conditionally receive a message from the mailbox.
              Does not block the invoking process.
    Parameters - mailbox id, pointer to put data of msg, max # of bytes that
                 can be received.
    Returns -
           -3: process is zap'd.
           -2: mailbox empty, no message to receive.
           -1: illegal values given as arguments; or, message sent is too large
               for receiver's buffer (no data copied in this case).
           The size of the message received.
    Side Effects - none.
    ----------------------------------------------------------------------- */
int MboxCondReceive(int mailboxID, void *message, int max_message_size)
{
    check_kernel_mode("MboxCondReceive");
    disable_interrupts("MboxCondReceive");

    enable_interrupts("MboxCondReceive");
    return 0;
} /* MboxCondReveive */


/* ------------------------------------------------------------------------
    Name - waitdevice
    Purpose - Synchronize processes with interrupt handlers.
    Parameters - the type of device, the unit, and the current status.
    Returns -
            -1: the process was zapped while waiting
             0: otherwise
    Side Effects - The appropriate device mailbox is sent a message every
                    time an interrupt is generated by the I/O deice.
    ----------------------------------------------------------------------- */
int waitdevice(int type, int unit, int *status)
{
    check_kernel_mode("waitdevice");
    disable_interrupts("waitdevice");

    enable_interrupts("waitdevice");
  //Called when a process wants to receive results of i/o operations
  //Applicable to Test 13 and test14

  //use MboxReceive on the appropriate mailbox.
    return 0;
} /* waitdevice */


//Returns id of the next inactive mailbox. Returns -1 if non exists.
int getInactive()
{
    for(int i = 0; i < MAXMBOX; i++)
    {
       if(MailBoxTable[i].status == INACTIVE)
       {
          return i;
       }
    }
    return -1;
}
/*----------------------------------------------------------------*
 * Name        : check_kernel_mode                                *
 * Purpose     : Checks the current kernel mode.                  *
 * Parameters  : name of calling function                         *
 * Returns     : nothing                                          *
 * Side Effects: halts process if in user mode                    *
 *----------------------------------------------------------------*/
static void check_kernel_mode(char *caller_name)
{
    union psr_values caller_psr;                                        /* holds the current psr values */
    if (DEBUG2 && debugflag2)
       console("    - check_kernel_mode(): called for function %s -\n", caller_name);

 /* checks if in kernel mode, halts otherwise */
    caller_psr.integer_part = psr_get();                               /* stores current psr values into structure */
    if (caller_psr.bits.cur_mode != 1)
    {
       console("        - %s(): called while not in kernel mode, by process. Halting... -\n", caller_name);
       halt(1);
    }
}/* check_kernel_mode */



/*----------------------------------------------------------------*
 * Name        : disable_interrupts                               *
 * Purpose     : Disables all interupts.                          *
 * Parameters  : name of calling function                         *
 * Returns     : nothing                                          *
 * Side Effects: disables interupts                               *
 *----------------------------------------------------------------*/
void disable_interrupts(char *caller_name)
{
    if (DEBUG2 && debugflag2)
       console("    - disable_interrupts(): interupts turned off for %s -\n", caller_name);

    psr_set( psr_get() & ~PSR_CURRENT_INT );
}/* disable_interrupts */



/*----------------------------------------------------------------*
 * Name        : enable_interrupts                                *
 * Purpose     : Enables all interupts.                           *
 * Parameters  : name of calling function                         *
 * Returns     : nothing                                          *
 * Side Effects: enables interupts                                *
 *----------------------------------------------------------------*/
void enable_interrupts(char *caller_name)
{
    if (DEBUG2 && debugflag2)
       console("    - enable_interrupts(): interupts turned on for %s -\n", caller_name);

    psr_set( psr_get() | PSR_CURRENT_INT );
}/* enable_interrupts */
