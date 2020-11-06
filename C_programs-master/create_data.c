#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void get_s_from(char *str,int n){
    char buff[128];
    int c=0;
    if(strlen(str)<n)
        retun;
    for(long i=n;i<strlen(str);i++){
        str[c++]=str[i];
    }
    str[c]='\0';
}

int main(){
char name[64];
strcpy(name,argv[0]);
strcat(name,"_data.txt");
get_s_from(name,2);
FILE *file=fopen(name,"a");
for(int i=1,i<argc;i++){
    fputs(argv[i],file);
    fputs("\n",file);
}
fclose(file);
return 0;
}
