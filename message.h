#define DEBUG2 1
#define INACTIVE 0
#define ACTIVE 1
#define EMPTY 0
#define USED 1
#define CLOCKMB 0
#define TERMMB 1
#define DISKMB 5

#define UNUSED -1


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
   /* other items as needed... */
};

struct mail_slot {
   int       mbox_id;
   int       slot_id;
   int       status;
   slot_ptr  next_slot;
   char      message[MAX_MESSAGE];
   int       message_size;
   /* other items as needed... */
};

struct proc_struct {
   proc_ptr       next_proc_ptr;
   proc_ptr       child_proc_ptr;
   proc_ptr       next_sibling_ptr;
   proc_ptr       parent_pid;
   char           name[MAXNAME];     /* process's name */
   char           start_arg[MAXARG]; /* args passed to process */
   context        state;             /* current context for process */
   short          pid;               /* process id */
   int            priority;
   int (* start_func) (char *);   /* function where process begins -- launch */
   char          *stack;
   unsigned int   stacksize;
   int            status;         /* READY, BLOCKED, QUIT, etc. */
   int            num_child;   /* The number of children the process has */
   //int            return_status;
   int            cur_startTime;
   int            CPUTime;
   int            quit_code;

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
