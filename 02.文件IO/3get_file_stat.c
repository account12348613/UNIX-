#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int fd;
    int accmode;
    if(argc!=2)
    {
        printf("param number err\n");
        return -1;
    }

    if((fd = fcntl(atoi(argv[1]),F_GETFL, 0))<0)
        printf("fcntl err\n");
    accmode = fd & O_ACCMODE;
    if(accmode & O_RDONLY)
        printf("read only");
    else if(accmode & O_WRONLY)
        printf("write only");
    else if(accmode & O_RDWR)
        printf("read and write");

    if(fd & O_APPEND)
        printf(", append");
    if(fd & O_NONBLOCK)
        printf(", non block");
    putchar('\n');
    return 0;
}