#include <stdio.h>
#include <unistd.h>//lseek(),STDIN_FILENO
int main()
{
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("can't seek\n");
    else
        printf("seek ok\n");
    return 0;
}
/*
abc@ubuntu:~/Desktop$ ./a.out
can't seek
abc@ubuntu:~/Desktop$ ./a.out < 1check_offset.c
seek ok
abc@ubuntu:~/Desktop$
 */