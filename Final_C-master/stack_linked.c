#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* init(int data){
    struct node* stack=(struct node*)malloc(sizeof(struct node));
    stack->data=data;
    stack->next=NULL;
    return stack;
}

void push(struct node** stack,int data){
    struct node* nn=init(data);
    if(*stack==NULL){
        *stack=nn;
        return;
    }
    nn->next=*stack;
    *stack=nn;
}

int top(struct node** stack){
    int res=(*stack)->data;
    
    return res;
}

void pop(struct node** stack){
    if(*stack==NULL)
        return;
    struct node* temp=*stack;
    *stack=(*stack)->next;
    free(temp);

}

void display(struct node** stack){
    struct node* p=*stack;
    if(*stack==NULL)
        return;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

}

int main(){
    struct node* stack=NULL;
    push(&stack,8);
    push(&stack,9);
    push(&stack,10);
    push(&stack,14);
    push(&stack,19);

    display(&stack);
    pop(&stack);
    display(&stack);
    return 0;
}
