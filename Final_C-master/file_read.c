#include<stdlib.h>
#include<stdio.h>
#include<string.h>
# define SIZE 128
int main(int argc, char *argv[]){
    
    char name[64];
    
    strcpy(name,argv[1]);

    FILE *file=fopen(name,"r");
    
    char buff[SIZE];
    
    while(fgets(buff,SIZE,file)){

                fputs(buff,stdout);
            
    }
    
    fclose(file);

return 0;

}

