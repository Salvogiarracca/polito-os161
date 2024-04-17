#include <types.h>
#include <lib.h>
#include <syscall.h>

int sys_write(int fd, const_userptr_t buf, size_t len){
    int i;

    (void) fd;

    if (len == 0) {
        return -1;
    }
    
    for(i=0; i<len ; i++){
        char c = *((const char *)buf + i);
        putch(c);
    }

    return i;   
    
}