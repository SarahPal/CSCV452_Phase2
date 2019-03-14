#define DEBUG2 1
#define INACTIVE 0
#define ACTIVE 1
#define CLOCKMB 0
#define TERMMB 1
#define DISKMB 5

typedef struct mail_slot *slot_ptr;
typedef struct mailbox mail_box;
typedef struct mbox_proc *mbox_proc_ptr;

struct mailbox {
   int           mbox_id;
   //int           slot_status;
   int           num_slots;
   int           slot_size;
   /* other items as needed... */
};

struct mail_slot {
   int       mbox_id;
   int       status;
   /* other items as needed... */
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
