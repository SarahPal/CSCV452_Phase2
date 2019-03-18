int waiting = 0;

void
p1_fork(int pid)
{}

void
p1_switch(int old, int new)
{}

void
p1_quit(int pid)
{}

int check_io()
{
    if(waiting > 0)
    {
        return 1;
    }
    return 0;
}
void add_process()
{
    waiting++;
}
void release_process()
{
    waiting--;
}
