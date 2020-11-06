#include<stdio.h>
#include<stdlib.h>

struct partition{
    int r,c;
    int row[128];
    int col[128];
    int p_r,p_c,sub_size_r,sub_size_c,size_r,size_c,last_r_b_sub,last_c_b_sub;
};

struct partition* init(int p_r,int p_c,int size_r,int size_c){
    struct partition* p=(struct partition*)malloc(sizeof(struct partition));
    p->r=-1;
    p->c=-1;
    p->p_r=p_r;
    p->p_c=p_c;
  //  p->sub_size_r=sub_size_r;
    //p->sub_size_c=sub_size_c;
    p->size_r=size_r;
    p->size_c=size_c;
    p->sub_size_r=size_r / p->p_r;
    p->sub_size_c=size_c / p->p_c;
    p->last_r_b_sub=0;
    p->last_c_b_sub=0;
    return p;
}

void part(struct partition* p){
   // struct partition* p=init(int p_r,int p_c, int size_r,int size_c);
    for(int i=0;i<=p->p_r;i++){
        p->r=p->r+1;            //filling row[] array with last bounds
        p->row[p->r]=p->last_r_b_sub;
        p->last_r_b_sub+=p->sub_size_r;
        
}

    for(int j=0;j<=p->p_c;j++){
        p->c=p->c+1;            //filling col[] array with last bounds
        p->col[p->c]=p->last_c_b_sub;
        p->last_c_b_sub+=p->sub_size_c;
}
    
    int mx[p->size_r][p->size_c];
    printf("Enter elements\n\n");
    for(int f=0;f<p->size_r;f++){
        for(int t=0;t<p->size_c;t++){
            scanf("%d",&mx[f][t]);
        
        }

    }
        printf("\n");
        for(int i=1;i<=p->p_c;i++){
            for(int m=1;m<=p->p_r;m++){
             for(int k=p->row[m-1];k<p->row[m];k++){
                for(int j=p->col[i-1];j<p->col[i];j++){
                   printf("%d ",mx[k][j]);
                }
               printf("\n");
            }
             printf("\n");
        }
        }
}
void put_file(struct partition* p){
    int num=(p->p_r)*(p->p_c);
    FILE *files[num];
    int mx[p->p_r][p->p_c];
    for(int k=0;k<p->p_r;k++){
        for(int m=0;m<p->p_c;m++){
            for(int i=0;i<num;i++){
                char filename[20];
                sprintf(filename,"f%d.txt",i+1);
                files[i]=fopen(filename,"a");
               // fprintf((files[i]),"%d\n",part(p));

    }
        }
    }
/*
    for(int i=0;i<num;i++){
        fprintf(files[i],"%d\n",part(p));

    }
*/
}
int  main(){    
    struct partition* p=init(2,2,4,6);
    part(p);
    put_file(p);
    return 0;
}






