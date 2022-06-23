#include <stdio.h>

int main()
{
    int c;
    while((c = getc(stdin)) != EOF)
    {
        if(putc(c, stdout)==EOF)
            printf("output err!\n");
    }

    if(ferror(stdin))
        printf("input err!\n");

    return 0;
}