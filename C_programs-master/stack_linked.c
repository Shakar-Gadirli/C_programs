#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node* init(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	return temp;
}

void push(struct node **stack,int data){
	struct node* temp=init(data);
	if(*stack==NULL){
		*stack=temp;
		return;
	}

	temp->link=*stack;
	*stack=temp;
}

int top(struct node** stack){
	return (*stack)->data;
}

void pop(struct node** stack){
	if (*stack==NULL){
		return;
	}
	struct node *p=*stack;
	(*stack)=(*stack)->link;
	free(p);
}

int main(){
	struct node* stack=NULL;
	push(&stack,17);
	push(&stack,18);
	push(&stack,19);
	push(&stack,20);

	while(stack!=NULL){
		printf("%d\t",stack->data);
		pop(&stack);
	}

return 0;
}
