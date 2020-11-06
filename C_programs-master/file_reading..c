#include <stdlib.h>
#include<stdio.h>

int main(){
   FILE *file=fopen("dummy.txt","r");
   if(file==NULL){
        printf("Empty file\n");
        exit(1);
   }

   /*char c;
   while((c=fgetc(file))!=NULL){
        putchar(c);


   }*/


   char buff[128];
   while(fgets(buff,128,file)){
    fputs(buff,stdout);
   }
   fclose(file);

return 0;
}
