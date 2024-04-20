#include <types.h>
#include <lib.h>
#include <syscall.h>
#include <current.h>
#include <proc.h>
#include <addrspace.h>
#include <thread.h>

int sys_exit(int status)
{
    struct proc *proc = curproc; // get current process

    if (proc == NULL) // proc must not be NULL
    {
        return -1;
    }
    KASSERT(proc != NULL); // just to be sure

    proc->exit_code = status;
    as_destroy(proc->p_addrspace); // destroy proc address space
    thread_exit();                 // current thread exit
}