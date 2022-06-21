#include <stdio.h>
#include <dirent.h>//DIR,struct dirent,

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
        printf("input argument number error!\n");

    if((dp = opendir(argv[1])) == NULL)
        printf("open dir error!\n");

    while((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n",dirp->d_name);
    }
    closedir(dp);
    return 0;
}
/*
use case

abc@ubuntu:~/Desktop$ pwd
/home/abc/Desktop
abc@ubuntu:~/Desktop$ ./a.out /home/abc/Desktop/
clion
ipc_pipe.c
my_ls.c
.
..
my_socket
linux study
my_std_i2o.c
a.out
codeblocks
abc@ubuntu:~/Desktop$ 

*/


