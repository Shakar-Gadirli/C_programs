#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int atoi2(char *num){
    int r=0;
    for(int i=0;num[i]>'0'-1 && num[i]<'9'+1;i++){
            r=r*10+(num[i]-'0');
    }
    return r;

}

int main(int argc,char* argv[]){
        
    char op[64],n1[64],n2[64];
    strcpy(op,argv[1]);
    strcpy(n1,argv[2]);
    strcpy(n2,argv[3]);
    int res;
    if(argc!=4)
        exit(1);

    if(strcmp(argv[1],"sum")==0)
        res=atoi2(n1)+atoi2(n2);
    if(strcmp(argv[1],"sub")==0)
        res=atoi2(n1)-atoi2(n2);
    if(strcmp(argv[1],"mult")==0)
        res=atoi2(n1)*atoi2(n2);
    if(strcmp(argv[1],"div")==0)
        res=atoi2(n1)/atoi2(n2);
    printf("%d\n",res);

    return 0;
}
