#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


void sort_word(char *string){
    char *temp;

    for(int i=0;i<strlen(string)-1;i++){
        for(int j=i+1;j<strlen(string);j++){
            if(string[i]>string[j]){
                char temp=string[i];
                string[i]=string[j];
                string[j]=temp;
            }
        }
    }
}


int find(char *str1, char *str2){
    int n1=strlen(str1);
    int n2=strlen(str2);
    int flag=0;
    if(n1==n2){
            sort_word(str1);
            sort_word(str2);
            int num=0;
            for(int i=0;i<n1;i++){
                if(str1[i]==str2[i]){
                    num+=1;
            }
            }
            if(num==n1){
                flag=1;
            }
            

    }
    else{
        flag=0;
    }

    return flag;
}

int main(){
        char word[20]="apple";
        char mix[64]="elppa";
        char mix2[64]="laekt";

        if(find(word,mix)!=0)
            printf("+\n");
        else
            printf("-\n");
        
      if(find(word,mix2)){
            printf("djjdjd\n");
        }
        else{
            printf("-\n");
        }
    return 0;
}
