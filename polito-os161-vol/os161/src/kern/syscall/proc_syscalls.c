#include <types.h>
#include <lib.h>
#include <syscall.h>
#include <current.h>
#include <proc.h>
#include <addrspace.h>
#include <thread.h>

void sys__exit(int status)
{
    struct proc *proc = curproc; // get current process

    KASSERT(proc != NULL); // just to be sure

    proc->exit_code = status; //TODO: handle status properly

    as_destroy(proc->p_addrspace); // destroy proc address space
    thread_exit();                 // current thread exit
}