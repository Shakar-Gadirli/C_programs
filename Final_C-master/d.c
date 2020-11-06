#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct vector{
	int *buff;
	int buff_size;
	int start;
	int pos;
};
struct vector* init(int size){
	struct vector *v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(int*)malloc(sizeof(int)*size);
	v->buff_size=size;
	v->start=0;
	v->pos=-1;
	return v;
}
void append_to_end_2(struct vector *v, int data){
	assert(v->pos<v->buff_size-1);
	v->pos+=1;
	v->buff[v->pos]=data;
}
void append_to_end(struct vector *v, int data){
	if((v->pos+1)!=v->buff_size){//i guess it should be like this
		v->pos+=1;
		v->buff[v->pos]=data;
	}
	else{
		printf("Out of space!");
	}
}
void append_to_mid(struct vector *v, int data, int index){
	int *v2=(int*)malloc(sizeof(int)*v->buff_size);
	if(v->pos < v->buff_size - 1){
		//struct vector *v2=init(v->buff_size);
		for(int i=0; i<index; i++){
			v2[i]=v->buff[i];
		}
		v2[index]=data;
		for(int i=index+1; i<=v->pos+1; i++){
			v2[i]=v->buff[i-1];
		}
		free(v->buff);
		v->buff=v2;
		v->buff_size=v->buff_size;
		v->pos=v->pos+1;
		//free(v->buff);
	}
}
void append_to_start(struct vector *v, int data){
	int *v2=(int*)malloc(sizeof(int)*v->buff_size);
	if(v->pos < v->buff_size - 1){
		v2[0]=data;
		for(int i=0; i<=v->pos; i++){
			v2[i+1]=v->buff[i];
		}
		free(v->buff);
		v->buff=v2;
		v->pos=v->pos+1;
		v->buff_size=v->buff_size;
		v->start=0;
	}
}
int pop_from_end(struct vector *v){//returns last and deletes it
	int num = v->buff[v->pos];
	v->pos=v->pos-1;
	return num;
}
int pop_from_mid_by_index(struct vector *v, int index){
	int num;
	for(int i=0; i<=v->pos; i++){
		if(i==index){
			num=v->buff[i];
			for(int j=i; j<v->pos; j++){
				v->buff[j]=v->buff[j+1];
			}
			v->pos=v->pos-1;
			break;
		}
	}
	return num;
}
int pop_by_data(struct vector *v, int data){
	for(int i=0; i<=v->pos; i++){
		if(v->buff[i]==data){
			for(int j=i; j<v->pos; j++){
				v->buff[j]=v->buff[j+1];
			}
			v->pos=v->pos-1;
			break;
		}
	}
}
int pop_from_start(struct vector *v){
	int num = v->buff[v->start];
	for(int i=0; i<v->pos; i++){
		v->buff[i]=v->buff[i+1];
	}
	v->pos=v->pos-1;
	return num;
}
void print_vector(struct vector *v){
	for(int i=0; i<=v->pos; i++){
		printf("%d ", v->buff[i]);
	}
	printf("\n");
}
void resize_vector(struct vector *v, int new_size){
	int *new_buff=(int*)malloc(sizeof(int)*new_size);
	if(new_size > v->buff_size){
		for(int i=0; i<=v->pos; i++){
			new_buff[i]=v->buff[i];
		}
		free(v->buff);
		v->buff=new_buff;
		v->buff_size=new_size;
		v->pos=v->pos;
		v->start=0;
	}
}
void shift_to_right(struct vector *v, int n){
	int *v_new=(int*)malloc(sizeof(int)*v->buff_size);
	int c=0;
	for(int i=v->pos; i>v->pos-n; i--){
		v_new[c]=v->buff[i];
		c+=1;
	}
	for(int i=0; i<=v->pos-n; i++){
		v_new[i+n]=v->buff[i];
	}
	free(v->buff);
	v->buff=v_new;
}
//Can be written the same way as shift_to_the_right
//void shift_to_left(struct vector *v, int n){
//	return 0;
//}
int main(){
	struct vector *v=init(10);
	printf("Enter array of 5 elements: ");
	for(int i=0; i<5; i++){
		int data;
		scanf("%d", &data);
		append_to_end(v, data);
	}
	printf("With lement at the end: ");
	print_vector(v);
	append_to_mid(v, 34, 3);
	printf("With element at the mid: ");
	print_vector(v);
	append_to_start(v, 77);
	printf("With element at the beginning: ");
	print_vector(v);
	int x=pop_from_end(v);
	printf("popped num from end: %d\n", x);
	printf("With popped from end: ");
	print_vector(v);
	int y=pop_from_start(v);
	printf("popped num from start: %d\n", y);
	printf("With popped from start: ");
	print_vector(v);
//	int z=pop_from_mid_by_index(v, 2);
//	printf("popped from the mid: %d\n", z);
//	printf("With popped from the mid: ");
//	print_vector(v);
//	resize_vector(v,20);
//	printf("%d\n",v->buff_size);
//	pop_by_data(v, 8);
//	print_vector(v);
	shift_to_right(v, 2);
	print_vector(v);
	free(v->buff);
	free(v);
	return 0;
}
