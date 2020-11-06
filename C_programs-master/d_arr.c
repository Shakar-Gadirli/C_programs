#include<stdio.h>
#include<stdlib.h>
struct vector{
	int *buff;
	int arr_size;
	int pos;
};

struct vector* init(int size){
	struct vector* v=malloc(sizeof(struct vector));
	v->buff=(int*)malloc(sizeof(int)*size);
	v->arr_size=size;
	v->pos=-1;
}

void push(struct vector* v,int data){
	if(v->pos>=v->arr_size)
		return;
	v->pos=v->pos+1;
	v->buff[v->pos]=data;

}

int pop(struct vector *v){
	if(v->pos<=-1)
		return -2e4;
	
	int res=v->buff[v->pos];
	v->pos=v->pos-1;
	return res;
}

int main(){
	struct vector *v=init(23);
	push(v,9);
	push(v,8);
	push(v,10);
	push(v,92);
	push(v,84);

	while(v->pos >= 0){
		printf("%d\n",pop(v));

	}

	return 0;
}

