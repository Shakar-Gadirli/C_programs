#include <stdio.h>
#include<stdio.h>

struct node{
	char data;
	struct node* link;
};

struct node* init_stack(char data){
	struct node* stack=(struct node*)malloc(sizeof(struct node));
	stack->next=NULL;
	stack->data=data;
	return stack;
}
 void push(struct node** stack,char data){
	struct node* temp=init_stack(data);
	if(*stack=NULL){
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
	struct node* temp=*stack;
	(*stack)=(*stack)->link;
	free(temp);
}
int check(char a,char b){
	if((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'))
		return 1;
	else
		return 0;
}
int check_expression(char *exp,struct node* s){
	for(long i=0;i<strlen(exp);i++){
		if((exp[i]==')') || (exp[i]==']') || (exp[i]=='}'))
		       if(check(s->top,exp[i])){
			       pop(s);
			 }
			else{
				return 0;
			}
		if (exp[i]=='(' || '[' || '{'){
			push(s,exp[i])
		}
	}		
	 if(is_empty(s)){
	 	return 1;
	 }
	
	return 0;
}

int is_empty(struct stack *s){
	return s->top==-1


}
int main(){

return 0;
}
