#include <stdio.h>
#include <stdlib.h>

struct vector{
	int *buff;
	int arr_size;
	int pos;
	int start;

};

struct vector* init(int size){
	struct vector* v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(int *)malloc(sizeof(int)*size);
	v->arr_size=size;
	v->pos=-1;
	v->start=0;
	return v;
}
void push(struct vector *v,int data){
	if(v->pos>=v->arr_size){
		return;	
	}
	v->pos=v->pos+1;
	v->buff[v->pos]=data;
}

int pop(struct vector *v){
	if(v->pos<=-1){
		return -1e2;
	}
	int res=v->buff[v->pos];
	v->pos=v->pos-1;
	return res;
}

int pop_left(struct vector *v){
	if(v->start<=v->pos){
		int res=v->buff[v->start];
		v->start=v->start+1;
		return res;
	}
	return -1e2;

}

void resize_vector(struct vector *v,int new_size){
	if((v->pos)-(v->start) < new_size){
		int *temp_arr=(int*)malloc(sizeof(int)*new_size);
		int c=0;
		for(int i=v->start;i<=v->pos;i++){
			temp_arr[c]=v->buff[i];
			c++;
		}
		free(v->buff);
		v->buff=temp_arr;
		v->arr_size=new_size;
		v->start=0;
		v->pos=c;

	}
}

void check_status(struct vector *v,int print_elements){
	printf("-----Current status-------");
	printf("Buffer size: %d\n",v->arr_size);
	printf("First pos: %d Last pos: %d\n",v->start,v->pos);
	printf("Items number: %d\n",v->pos-v->start);

	if(print_elements){
		printf("Items\n");
		for(int i=v->start;i<=v->pos;i++){
			printf("%d\n",v->buff[i]);

		}
		printf("\n");
	printf("\n-------------------------------------------------\n");

	}

}


int main(){

	struct vector *v=init(32);
	push(v,23);
	push(v,82);
	push(v,96);
	push(v,13);


	check_status(v,1);

	int rr=pop_left(v);

	resize_vector(v,64);
	push(v,99);
	push(v,100);

	check_status(v,1);

	return 0;

}
