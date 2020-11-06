#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct matrix{
    int row;
    char mtrx[100][50];
};

struct matrix* init(){

    struct matrix* mx=(struct matrix*)malloc(sizeof(struct matrix));
    mx->row=0;
    return mx;
}

void add(struct matrix* mx){
    char name[15];
    char sname[15];
    char phone[15];
    printf("Enter name\n");
    scanf("%s",name);
    printf("Enter surname\n");
    scanf("%s",sname);
    printf("Enter phone\n");
    scanf("%s",phone);
    
    if(strlen(name)>15 || strlen(sname)>15 || strlen(phone)>15){
        printf("Parameters should not exceed the limit of 15 character\n");
        return;}
    for(int i=mx->row;i<mx->row+1;i++){
        for(int j=0;j<strlen(name);j++){
            mx->mtrx[i][j]=name[j];
        }
        for(int m=strlen(name);m<15;m++){
            mx->mtrx[i][m]=' ';

        }
        int c1=0;
        for(int n=15;n<(strlen(sname)+15);n++){
            mx->mtrx[i][n]=sname[c1];
                c1++;
        }
        for(int l=strlen(sname)+15;l<30;l++){
            mx->mtrx[i][l]=' ';
        }
        int c2=0;
        for(int k=30;k<(30+strlen(phone));k++){
            mx->mtrx[i][k]=phone[c2];
            c2++;
        }
        for(int h=30+strlen(phone);h<45;h++){
            mx->mtrx[i][h]=' ';
        }
        printf("\n");
    }

    mx->row=mx->row+1;
}

void find(struct matrix *mx){
    char data[128];
    printf("Enter data that you are looking for\n");
    scanf("%s",data);
    char m[1][15];
    if(strlen(data)>15){
        printf("Parameters have the minimum length of 15 characters\n");
        return;
    }
    for(int x=0;x<strlen(data);x++){
        m[1][x]=data[x];
    }
    for(int y=strlen(data);y<15;y++){
        m[1][y]=' ';
    }
    
    printf("Data\n");

    for(int i=0;i<15;i++){
        printf("%c",m[1][i]);
    }
    printf("\n");

    int flag=0;
    for(int i=0;i<mx->row;i++){
        int flag1=1;
        int flag2=1;
        int flag3=1;

        for(int j=0;j<15;j++){
            if(mx->mtrx[i][j]!=m[1][j]){
                flag1=0;
            }

        }
        int c=0;
        for(int k=15;k<30;k++){
            if(mx->mtrx[i][k]!=m[1][c]){
                flag2=0;
            }
            c++;
        }
        int c2=0;
        for(int l=30;l<45;l++){
            if(mx->mtrx[i][l]!=m[1][c2]){
                    flag3=0;
            }
            c2++;
        }
    
        if(flag1==1 || flag2==1 || flag3==1){
            flag=1;
            printf("All the records connected to that data:\n");
            for(int w=0;w<45;w++){
                    printf("%c",mx->mtrx[i][w]);
            }


        }

    }
    
    if (flag==0){
        printf("Not found\n");
    }
       
}

void read_all(struct matrix *mx){
    for(int i=0;i<mx->row;i++){
        for(int j=0;j<45;j++){
                printf("%c",mx->mtrx[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct matrix* mx=init();
    add(mx);
    add(mx);
    add(mx);
    read_all(mx);
    find(mx);
    printf("\n");

    return 0;
}
