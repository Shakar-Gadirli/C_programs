#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc,char *argv[]){
    
    DIR *dir=opendir(".");
    struct dirent* sd;

    if(dir==NULL)
    {
        printf("Unable to open directory\n");
        exit(1);
    }
        
    while((sd=readdir(dir))!=NULL){
            printf(">> %s\n",sd->d_name);

    }
    closedir(dir);
    return 0;
}
