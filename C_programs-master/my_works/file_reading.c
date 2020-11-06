#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *file=fopen("dummy.txt","r");
    char buff[128];
    while(fgets(buff,128,file)){
        fputs(buff,stdout);
    
    }
    fclose(file);



return 0;
}
