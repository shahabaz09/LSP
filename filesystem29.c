// assignment 2 4 
// type from stat function
// aas 3 ->2


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>


int main(int argc,char * argv[])
{
    DIR * dp=NULL;
    struct dirent * entry =NULL;

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry=readdir(dp))!=NULL)
    {
        if(strcmp(argv[2],entry->d_name)==0)
        {
            printf("File is present in Directory\n");
            break;
        }

    }
    if(entry==NULL)
    {
        printf("There is no such file\n");
        return -1;
    }
    closedir(dp);
    return 0;
}