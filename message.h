#define DEBUG2 1
#define INACTIVE 0
#define ACTIVE 1
#define EMPTY 0
#define USED 1
#define CLOCKMB 0
#define TERMMB 1
#define DISKMB 5

#define UNUSED -1
#define NOT_BLOCKED 0
#define SENDBLOCK 11
#define RECEIVEBLOCK 12


typedef struct mail_slot *slot_ptr;
typedef struct mailbox mail_box;
typedef struct mbox_proc *mbox_proc_ptr;
typedef struct mail_slot mail_slot;

typedef struct proc_struct proc_struct;

typedef struct proc_struct * proc_ptr;

struct mailbox {
   int           mbox_id;
   int           status;
   int           num_slots;
   int           slot_size;
   int           slots_used;
   slot_ptr      head, end;

   /* other items as needed... */
};

struct mail_slot {
   slot_ptr  next_slot;
   int       mbox_id;
   int       slot_id;
   int       status;
   char      message[MAX_MESSAGE];
   int       message_size;
   /* other items as needed... */
};

struct proc_struct {
   short          pid;               /* process id */
   int            status;         /* READY, BLOCKED, QUIT, etc. */
   int            cur_startTime;
   int            mbox_id;
   char           message[MAX_MESSAGE];
   int            size;

   //TODO: Evaluate what is needed and what isn't
   /* other fields as needed... */
};

struct psr_bits {
    unsigned int cur_mode:1;
    unsigned int cur_int_enable:1;
    unsigned int prev_mode:1;
    unsigned int prev_int_enable:1;
    unsigned int unused:28;
};

union psr_values {
   struct psr_bits bits;
   unsigned int integer_part;
};
