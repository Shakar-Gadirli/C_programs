#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[]){
    int charCount=0;
    int wordCount=0;
    int lineCount=0;


    char name[20];
    strcpy(name,argv[1]);

    FILE *file=fopen(name,"r");

    if(file==NULL){

        printf("CANNOT OPEN\n");
        exit(0);
    }
    
    char buff;
    while((buff=fgetc(file))!=EOF){
        if((int)buff==32){
            wordCount++;
        }
        else if((int)buff==10){
            lineCount++;
            wordCount++;
        }
        else{
            charCount++;

        }

    }

    printf("\n");

    printf("Word count %d\n",wordCount);
    printf("Line count %d\n",lineCount);
    printf("Char Count %d\n",charCount);
    return 0;

}
