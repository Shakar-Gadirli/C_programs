#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
    
    char name[64];
    
    strcpy(name,argv[1]);
    FILE * file=fopen(name,"w");
//    printf("%d",argc);
    int num;//number of lines;
    printf("How many lines will you write:\n");

    scanf("%d",&num);
    num++;

    char buff[128];

    while(num--){
        fgets(buff,128,stdin);
        fputs(buff,file);
    
    }
    
    fclose(file);



    return 0;
}
