#include <stdio.h>
#include <unistd.h>//getuid,getgid
int main()
{
    printf("uid = %d, gid = %d\n",getuid(), getgid());
    return 0;
}
/*
abc@ubuntu:~/Desktop$ ./a.out
uid = 1000, gid = 1000
abc@ubuntu:~/Desktop$
*/