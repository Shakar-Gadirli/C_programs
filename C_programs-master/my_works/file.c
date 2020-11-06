#include <stdio.h>
#include <stdlib.h>

int main(){
    char buff[128];

    FILE * file=fopen("dummy.txt","w");

    fgets(buff,128,stdin);
    fputs(buff,file);
    fclose(file);




}
