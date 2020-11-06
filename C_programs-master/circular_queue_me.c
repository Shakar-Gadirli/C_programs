#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *buff;
	int first,last;
	int buff_size;
	int count;
};

struct queue* init(int buff_size){
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->buff=(int*)malloc(sizeof(int)*buff_size);
	q->first=0;
	q->last=0;
	q->count=0;
	q->buff_size=buff_size;
	return q;
}

void enqueue(struct queue* q,int item){
	if(q->count<q->buff_size){
		q->buff[q->last]=item;
		q->last=(q->last+1)%q->buff_size;
		q->count=q->count+1;
	}
}

int dequeue(struct queue* q){
	int res=-1e9;
	if(q->count>0){
		 res=q->buff[q->first];
		 q->first=(q->first+1)%q->buff_size;
		 q->count=q->count-1;
	}
	return res;
}

int main(){
	struct queue *q=init(5);

	enqueue(q,12);
	enqueue(q,13);
	enqueue(q,14);
	enqueue(q,15);
	enqueue(q,16);

	do{
		printf("%d\t",dequeue(q));
	}while(q->last!=q->first);	

return 0;
}
