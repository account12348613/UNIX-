#include <stdio.h>
#include <string.h>//strerror()
#include <errno.h>//EACCES
int main(int argc, char *argv[])
{
    //output error message to stderr
    fprintf(stderr, "EACCES: %s\n",strerror(EACCES));

    errno = ENOENT;
    perror(NULL);
    return 0;
}
/*
abc@ubuntu:~/Desktop$ ./a.out
EACCES: Permission denied
./a.out: No such file or directory
*/