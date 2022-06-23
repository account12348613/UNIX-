#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAXLINE 8192
void sig_intr(int signo)
{
    printf("recive a signal: %d\n",signo);
}

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    if(signal(SIGINT, sig_intr) == SIG_ERR)
        perror("signal");
    while(fgets(buf, MAXLINE, stdin)!=NULL)
    {
        buf[strlen(buf)-1] = 0;
        if((pid = fork()) <0)
            perror("fork");
        else if (pid == 0)
        {
            execlp(buf, buf, (char *)0);
            perror("execlp");
            exit(127);
        }

        if((pid = waitpid(pid, &status, 0))<0)
            perror("waitpid");
        printf("%% ");
    }
    return 0;
}
/*
abc@ubuntu:~/Desktop$ ./a.out
% ls
 a.out   codeblocks          handle_signal.c  'linux study'   my_socket      my_std_io_with_buff.c   pr_pid.c
 clion   exec_from_stdin.c   ipc_pipe.c        my_ls.c        my_std_i2o.c   pr_err.c                pr_uid.c
% abc
execlp: No such file or directory
% ^Crecive a signal: 2
*/