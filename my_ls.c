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
