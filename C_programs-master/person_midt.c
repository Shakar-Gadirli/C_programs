#include<stdio.h>
#include<stdlib.h>
struct person{
    int health;
    int work;
};


struct person* init(int health,int work){
    struct person* p=(struct person*)malloc(sizeof(struct person));
    p->health=health;
    p->work=work;
    return p;
}

void work(struct person* p){
    if(p->health<=0){
        free(p);
    }
    else{
        p->health=p->health-5;
        p->work=p->work+3;


}
}

int main(){
    struct person* p=init(100,0);
    int i=0;
    for(int i=0;i<20;i++){
        work(p);
    }
    printf("Health: %d\t  Work:%d\n",p->health,p->work);
    
    
    return 0;
}
