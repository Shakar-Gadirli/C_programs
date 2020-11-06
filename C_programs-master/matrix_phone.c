#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add(int matrix[50][50]){
    printf("Enter the name:\n");
    
    char *name,*surname;
    scanf("%s",name);
    
    printf("Enter surname\n");
    scanf("%s",surname);

    int phone[k];
    printf("Enter phone number\n");
    for(i=0;i<5;i++){
        scanf("%d",&phone[i]);
    }
        
    int status=1;
    
    for(int i=0;i<15;i++){
        for(int j=0;j<strlen(name);j++){
            strcpy(matrix[i][j],name[j]);
        }
            int n=0;
        for(int j=15;n<stlen(surname);j++){
            strcpy(matrix[i][j],surname[n]);
            n++;
        }
        int p=0;
        for(j=30;n<5;j++){
            matrix[i][j]=phone[n];
            p++;
        }

        
        printf("Enter status:");
        scanf("%d",&status);
        if(status==0)
            break;
    }

}

int main(int argc,char* argv []){
    
    int last=-1;
    int matrix[50][50];
    
    if(strcmp(argv[1],"add")==0){
        
        add(int matrix[50][50]);

    }



return 0;
}
