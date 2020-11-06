#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Write number of lines\n");
    int l;
    scanf("%d",&l);
    char buff[128];
    FILE *file=fopen("dummy.txt","w");


    while(l){
        fgets(buff,128,stdin);
        fputs(buff,file);
        l--;
    }
    fclose(file);





return 0;
}
