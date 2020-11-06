#include <stdio.h>
#include <stdlib.h>

struct queue{
	int *buff;
	int buff_size;
	int first,last;
	int count;

};

struct queue* init(int buff_size){
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->buff=(int*)malloc(sizeof(int)*buff_size);
	q->last=q->first=0;
	q->buff_size=buff_size;
	q->count=0;
	return q;
}
void enqueue(int item){
	struct queue* q;
	if(q->last<q->buff_size)
		q->buff[q->last]=item;
		q->last=q->last+1;
}

void traverse(struct queue* q){
	if(q->first==q->last){
		printf("Empty\n");
	}
	else{
		for(int i=q->first;i<q->last;i++){
			printf("%d\t",q->buff[i]);

		}
	}


}

int dequeue(struct queue *q){
	int res=-1e9;
	if(q->first<=q->last){
		res=q->buff[q->first];
		q->first=q->first+1;
		}
	return res;
}



int main(){
	struct queue* q=init(5);
	 enqueue(23);
	 enqueue(55);
	 enqueue(77);
	 enqueue(88);
	 enqueue(99);
	 traverse(q);
	 printf("\n");
	printf("%d\t",dequeue(q));
	printf("%d\t",dequeue(q));
	printf("%d\t",dequeue(q));
	printf("%d\t",dequeue(q));

	printf("%d\t",dequeue(q));
	printf("\n");
	traverse(q);

return 0;	
}
