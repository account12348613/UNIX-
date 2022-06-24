#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
char buf1[] = "123456";
char buf2[] = "abcdef";

int main()
{
    int fd;
    if((fd= creat("file.hole", FILE_MODE))<0)
        printf("create err\n");
    if(write(fd, buf1, 6)!=6)
        printf("buf1 write err\n");
    if(lseek(fd, 10, SEEK_CUR)==-1)
        printf("lseek err\n");
    if(write(fd, buf2, 6)!=6)
        printf("buf2 write err\n");
    return 0;
}