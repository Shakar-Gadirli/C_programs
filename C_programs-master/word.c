#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char word[128];
    fgets(word,128,stdin);
    //printf("%s\n",word);//works too.
    fputs(word,stdout);
return 0;
}
