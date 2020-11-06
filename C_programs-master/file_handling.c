#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *file=fopen("me.txt","a");
    printf("write smth to the file:\n");
    char buff[128];
    scanf("%s",buff);
    fprintf(file,"%s",buff);
    fclose(file);




return 0;
}
