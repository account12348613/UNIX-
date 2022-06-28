#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, int1, int2;
    char line[20];

    while((n = read(STDIN_FILENO, line ,20))>0)
    {
        line[n] = 0;

        if(sscanf(line, "%d%d", &int1, &int2) == 2)
        {
            sprintf(line, "sun = %d\n",int1+int2);
            n = strlen(line);
            //fprintf(stdout, "c recive: %s",line);
            if(write(STDOUT_FILENO, line, n) != n)
            {
                printf("write err\n");
            }
        }
        else
        {
            if(write(STDOUT_FILENO, "invalid args\n", 13) != 13)
                printf("write error\n");
        }
        //exit(0);
    }
    return 0;
}