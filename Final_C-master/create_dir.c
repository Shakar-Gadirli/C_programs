#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int main(int argc,char *argv[]){
    
    int ret;

    char name[64];

    strcpy(name,argv[1]);

    ret=mkdir(name, S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH);

    
    return 0;

}
