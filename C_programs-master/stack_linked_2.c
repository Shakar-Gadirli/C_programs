#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
}

struct node* init(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	return temp;
}

void push(struct node** stack,int data){
	struct node* temp=init(data);
	if(*stack==NULL){
		*stack=temp;
		return;
	}
	temp->link=*stack;
	*stack=temp;
}	

void pop(struct node** stack){
	if(*stack==NULL){
		return;
	}
	struct node* p=*stack;
	(*stack)=(*stack)->link;
	free(p);
}

int top(struct node** stack){

	return (*stack)->data;
}
int main(){
	struct node* stack=NULL;
	push(&stack,12);
	push(&stack,13);
	push(&stack,14);
	push(&stack,15);
	push(&stack,16);

	while(stack!=NULL){
		printf("%d\t",stack->data);
		pop(&stack);

	}
return 0;


}
