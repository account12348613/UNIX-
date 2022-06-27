#include <fcntl.h>
#include <stdio.h>

void set_flags(int fd, int flags)
{
    int val;

    if((val = fcntl(fd, F_GETFL, 0))<0)
    {
        printf("fcntl F_GETFL err\n");
    }
    val |= flags;

    if(fcntl(fd, F_SETFL, val)<0)
        printf("fcntl F_SETFL err\n");
}
void unset_flags(int fd, int flags)
{
    int val;

    if((val = fcntl(fd, F_GETFL, 0))<0)
    {
        printf("fcntl F_GETFL err\n");
    }
    val &= ~flags;

    if(fcntl(fd, F_SETFL, val)<0)
        printf("fcntl F_SETFL err\n");
}