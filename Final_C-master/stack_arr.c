#include<stdio.h>
#include<stdlib.h>

struct stack{
    int *buff;
    int size;
    int top;
};

struct stack* init(int size){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->buff=(int*)malloc(sizeof(int)*size);
    s->top=-1;
    s->size=size;
    return s;
}

void push(struct stack* s,int data){
    if(s->top==s->size-1)
        return;
    s->top=s->top+1;
    s->buff[s->top]=data;
}
void pop(struct stack* s){
    if(s->top>=0)
       s->top=s->top-1;
}

int top(struct stack* s){

     int res=s->buff[s->top];
     return res;
}

void display(struct stack* s){
    if(s->top>=0){
        for(int i=s->top;i>-1;i--){
        printf("%d ",s->buff[i]);
    }
    }
    printf("\n");

}


int main(){
    struct stack* s=init(10);
    push(s,1);
    push(s,8);
    push(s,19);
    push(s,7);
    push(s,6);
    push(s,2);
    display(s);

    return 0;
}
