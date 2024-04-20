#include <types.h>
#include <lib.h>
#include <syscall.h>

int sys_write(int fd, const_userptr_t buf, size_t len)
{
    size_t i;

    (void)fd;

    // TODO: write into files
    // VERY BASIC IMPLEMENTATION

    if (len == 0)
        return -1;

    for (i = 0; i < len; i++)
    {
        char ch = *((const char *)buf + i);
        putch(ch);
    }

    return i;
}

static void
backsp(void)
{
    putch('\b');
    putch(' ');
    putch('\b');
}

int sys_read(int fd, userptr_t buf, size_t len)
{
    size_t pos = 0;
    int ch;

    (void)fd;

    // TODO: read from files
    // VERY BASIC IMPLEMENTATION

    if (len == 0)
        return -1;

    while (1)
    {
        ch = getch();

        if (ch == '\n' || ch == '\r')
        {
            putch('\n');
            break;
        }

        /* Only allow the normal 7-bit ascii */
        if (ch >= 32 && ch < 127 && pos < len - 1)
        {
            putch(ch);
            *((char *)buf + ++pos) = ch;
            // buf[pos++] = ch;
        }
        else if ((ch == '\b' || ch == 127) && pos > 0)
        {
            /* backspace */
            backsp();
            pos--;
        }
    }

    return pos;
}