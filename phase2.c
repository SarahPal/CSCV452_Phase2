/* ------------------------------------------------------------------------
   phase2.c

   University of Arizona South
   Computer Science 452

   ------------------------------------------------------------------------ */

#include <phase1.h>
#include <phase2.h>
#include <usloss.h>

#include "message.h"

/* ------------------------- Prototypes ----------------------------------- */
int start1 (char *);
extern int start2 (char *);

int MboxCreate(int slots, int slot_size);
int MboxSend(int mbox_id, void *msg_ptr, int msg_size);
int MboxReceive(int mbox_id, void *msg_ptr, int msg_size);
int MboxRelease(int mailboxID);
int MboxCondSend(int mailboxID, void *message, int message_size);
int MboxCondReceive(int mailboxID, void *message, int max_message_size);
int waitdevice(int type, int unit, int *status);

/* -------------------------- Globals ------------------------------------- */

int debugflag2 = 0;

/* the mail boxes */
mail_box MailBoxTable[MAXMBOX];


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
   if (DEBUG2 && debugflag2)
      console("start1(): at beginning\n");

   check_kernel_mode("start1");

   /* Disable interrupts */
   disableInterrupts();

   /* Initialize the mail box table, slots, & other data structures.
    * Initialize int_vec and sys_vec, allocate mailboxes for interrupt
    * handlers.  Etc... */
   for(int i = 0; i <= MAXMBOX; i++)
   {
      MailBoxTable[i]->mbox_id = i;
      MailBoxTable[i]->slot_status = UNUSED;
   }
    
   //initialize int_vec
   //initialize sys_vec
   
   IntHandMB[CLOCKMB] = MBoxCreate(0, sizeof(int)); //Clock MB
   IntHandMB[TERMMB] = MBoxCreate(0, sizeof(int)); //Terminal 1
   IntHandMB[TERMMB + 1] = MBoxCreate(0, sizeof(int)); //Terminal 2
   IntHandMB[TERMMB + 2] = MBoxCreate(0, sizeof(int)); //Terminal 3
   IntHandMB[TERMMB + 3] = MBoxCreate(0, sizeof(int)); //Terminal 4
   IntHandMB[DISKMB] = MBoxCreate(0, sizeof(int)); //Disk 1
   IntHandMB[DISKMB + 1] = MBoxCreate(0, sizeof(int)); //Disk 2
   
   
   enableInterrupts();

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
   disableinterrupts();
   check_kernel_mode("MboxCreate");
   
   //insert debugging statements
  //find a free mailbox, then initialize it. 
} /* MboxCreate */


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
} /* waitdevice */


