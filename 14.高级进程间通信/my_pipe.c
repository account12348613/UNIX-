#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#define MAX_LINE 8192
static void sig_pipe(int signal);
int main()
{
    int n, fd[2];
    pid_t pid;
    char line[MAX_LINE];

    if(signal(SIGPIPE, sig_pipe) == SIG_ERR)
        printf("signal err\n");
    if(socketpair(AF_UNIX, SOCK_STREAM, 0, fd))
        printf("pipe err\n");

    if((pid = fork())<0)
        printf("fork err\n");
    else if(pid > 0)        //parent
    {
        close(fd[1]);   //close send pipe
        while(fgets(line, MAX_LINE, stdin) != NULL)
        {
            n = strlen(line);
            printf("parent pid = %d send: %s",getpid(), line);
            if(write(fd[0], line, n) != n)
                printf("p write err\n");

            if((n = read(fd[0], line, MAX_LINE))<0)
                printf("p read err from pipe\n");
            if(n == 0)
                printf("p child pipe closed\n");

            line[n] = 0;
            printf("output: ");
            if(fputs(line, stdout) ==EOF)
                printf("p fputs err\n");
            //raise(SIGPIPE);
        }

        raise(SIGPIPE);

        if(ferror(stdin))
            printf("p fgets err on stdin\n");
        exit(0);
    }
    else                    //child
    {
        close(fd[0]);       //close recive pipe

        if(fd[1] != STDIN_FILENO)
        {
            if(dup2(fd[1], STDIN_FILENO) != STDIN_FILENO)
                printf("c dup2 stdin err\n");
        }

        if(fd[1] != STDOUT_FILENO)
        {
            if(dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
                printf("c dup2 stdout err\n");
        }

        if(execl("./add2", "add2", NULL)<0)
            printf("c execl err\n");
    }

    return 0;
}

static void sig_pipe(int signal)
{
    printf("SIGPIPE caught pid = %d\n",getpid());
    exit(1);
}