#include<stdio.h>
#include<stdlib.h>

int matrix[1024][1024];

int get_sum(int st_r,int e_r,int st_c,int e_c){
    int temp=0;
    for(int i=st_r;i<e_r;i++){
        for(int j=st_c;j<e_c;j++){
               temp+=matrix[i][j]; 


        }
    }
    return temp;
}

int max(int a,int b){
    if (a>b)
        return a;
    else
        return b;
}

int main(){
    int max_p=-1e9;
    int r,c;
    int a,b;
    scanf("%d %d",&r,&c);
    scanf("%d %d",&a,&b);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&matrix[i][j]);


        }

    }
    int temp_s=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if((i+a<=r) && (j+b<=c)){
                int temp_s=get_sum(i,i+a,j,j+b);
                max_p=max(temp_s,max_p);
                printf("Max %d\n",max_p);
            }
        }
    }

    printf("Max sum: %d",max_p);



    return 0;
}
