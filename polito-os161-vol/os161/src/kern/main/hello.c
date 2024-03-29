#include <types.h>
#include <lib.h>
#include "hello.h"

void hello(const char *str){
    kprintf("Hello %s! Nice to have you here\n", str);
}