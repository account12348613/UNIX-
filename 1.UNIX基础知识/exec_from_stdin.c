#include <stdio.h>
#include <unistd.h>//getpid(),pid_t
#include <string.h>//strlen()
#include <stdlib.h>//exit()
#include <sys/wait.h>//waitpid()
#define BUFFSIZE 8192
int main()
{
    char buf[BUFFSIZE];
    pid_t pid;
    int status;

    printf("%% ");
    while(fgets(buf, BUFFSIZE, stdin) != NULL)
    {
        buf[strlen(buf) - 1] = 0;

        if((pid = fork())<0)
            printf("fork err\n");

        else if(pid == 0)
        {
            execlp(buf, buf, (char *) 0);
            printf("can't execute: %s\n",buf);
            exit(127);
        }
        if((pid = waitpid(pid, &status, 0)) < 0)
        {
            printf("wait pid err\n");
        }
        printf("%% ");
    }
    return 0;
}

/*
abc@ubuntu:~/Desktop$ ./a.out
% abc
can't execute: abc
% ls
 a.out   clion   codeblocks   exec_from_stdin.c   ipc_pipe.c  'linux study'   my_ls.c   my_socket   my_std_i2o.c   my_std_io_with_buff.c   pr_pid.c
% pwd
/home/abc/Desktop
%
*/