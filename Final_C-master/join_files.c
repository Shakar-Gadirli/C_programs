#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    
    char name[20];

    strcpy(name,argv[1]);

    FILE *main=fopen(name,"a");
    
    for(int i=2;i<argc;i++){
        FILE *file=fopen(argv[i],"r");
        char buff[128];
        while(fgets(buff,128,file)){
            fputs(buff,main);
    }
        fputs("\n",main);
        fclose(file);
    }

    fclose(main);
    return 0;
}
