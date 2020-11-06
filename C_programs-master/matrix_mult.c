#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n;
    int p,q;
    int max1[128][128];
    int max2[128][128];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&max1[m][n]);
        }
    }
    scanf("%d %d",&q,&p);
     for(int i=0;i<q;i++){
        for(int j=0;j<p;j++){
            scanf("%d",&max1[m][n]);
        }
    }
    int res[128][128];
    for(int i=0;i<m;i++){
        for(int j=0;j<p;i++){
            for(int k=0;k<n;k++){
                res[i][j]+=max1[i][n]*max2[k][j];


            }

        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){

            printf("%d",res[i][j]);

        }
        printf("\n");
    }


    return 0;
}
