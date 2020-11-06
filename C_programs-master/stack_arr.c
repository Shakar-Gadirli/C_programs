#include<stdio.h>
#include<stdlib.h>

struct stack{
	int top;
	int *buff;
	int buff_size;
};

struct stack* init(int buff_size){
	struct stack* s=(struct stack*)malloc(sizeof(struct stack));
	s->buff=(int*)malloc(sizeof(int)*buff_size);
	s->top=-1;
	s->buff_size=buff_size;
	return s;
}

void push(struct stack* s,int data){
	if(s->top<s->buff_size-1){
		s->top=s->top+1;
		s->buff[s->top]=data;
	}
}

void pop(struct stack* s){
	if(s->top>=0){
		s->top=s->top-1;
	}
}

int top(struct stack *s){
	return s->buff[s->top];

}
 int is_empty(struct stack* s){
	return s->top==-1;
 }

int main(){
	struct stack* s=init(5);
	push(s,7);
	push(s,8);
	push(s,9);
	push(s,10);
	push(s,11);
	
	while(s->top>=0){
		printf("%d\t",top(s));
		pop(s);

	}


return 0;
}


