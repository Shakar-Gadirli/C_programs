#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>


int main(int argc,char *argv[]){
    int ret;

    char name[64];
    strcpy(name,argv[1]);

    ret=rmdir(name);




return 0;
}
