//ass 4 4
// files are same or not New
// not working

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


int main(int argc,char * argv[])
{
    int fd1=0,fd2=0;
    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_RDONLY);
    struct stat obj1,obj2;
    char buffer1 [1024];
    char buffer2 [1024];
    int iret=0;


    if(fd1==-1 || fd2==-1)
    {
        printf("Unable to open file \n");
        return -1;
    }
    fstat(fd1,&obj1);
    fstat(fd2,&obj2);
    if(obj1.st_size !=obj2.st_size);
    {
        printf("Files are Different \n");
        return -1;
    }
    while((iret=read(fd1,buffer1,sizeof(buffer1)))!=0)
    {
        iret=read(fd2,buffer2,sizeof(buffer2));
        if(memcmp(buffer1,buffer2,iret)!=0)
        {
            break;
        }
    }   
    if(iret==0)
    {
        printf("Both files are identicle\n");
    }
    else
    {
        printf("Both files are different\n");
    }


    return 0;
}