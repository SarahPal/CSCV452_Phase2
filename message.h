#define DEBUG2 1
#define INACTIVE 0
#define ACTIVE 1
#define EMPTY 0
#define USED 1
#define CLOCKMB 0
#define TERMMB 1
#define DISKMB 5

#define TRUE 1
#define FALSE 0
#define UNUSED -1
#define SEND_BLOCK 11
#define RECEIVE_BLOCK 12


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
   int           used_slots;
   int           slot_size;
   slot_ptr      head, end;
   int           blocking;

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
   proc_ptr       next_proc_ptr;
   int            status;         /* READY, BLOCKED, QUIT, etc. */
   int            ishead;
   int            pid;
   int            cur_startTime;
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
