#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 128
int main(int argc,char *argv[]){
    
    char name_r[64],name_w[64];
    
    strcpy(name_r,argv[1]);
    strcpy(name_w,argv[2]);
    
    FILE *file_w=fopen(name_w,"a");
    FILE *file_r=fopen(name_r,"r");
    
    char buff[128];
    if(file_r==NULL){
        printf("Error in reading\n");
        exit(1);
    }

    while(fgets(buff,SIZE,file_r)){
        fputs(buff,file_w);

    }


    fclose(file_r);
    fclose(file_w);





}
