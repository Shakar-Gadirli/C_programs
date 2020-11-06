#include<stdio.h>
#include<stdlib.h>

struct queue{
    int first,last;
    int *buff;
    int buff_size;
    int count;
};

struct queue* init(int size){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->buff=(int*)malloc(sizeof(int)*size);
    q->first=0;
    q->last=0;
    q->count=0;
    q->buff_size=size;
    return q;
}

void enqueue(struct queue* q,int data){
    if(q->count<(q->buff_size)){
        q->buff[q->last]=data;
        q->last=(q->last+1) % q->buff_size;
        q->count=(q->count)+1;
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

void print(struct queue* q){
   printf("\n");
  int  c=q->first;
    do{
            printf("%d ",q->buff[c]);
            c=(c+1) % q->buff_size;
   }while(c!=q->last);
    
}

void destroy_queue(struct queue* q){
    free(q->buff);
    free(q);

}

void resize(struct queue* q,int new_size){
    int* temp=(int*)malloc(sizeof(int)*new_size);
    if(q->buff_size<new_size){
           int c=0;
           int i=q->first;
           do{
            temp[c]=q->buff[i];
            c=(c+1)%new_size;
            i=(i+1)%q->buff_size;
        }while(i!=q->last);
    q->first=0;
    q->last=c;
    free(q->buff);
    q->buff=temp;
    q->buff_size=new_size;

    }
    else{
        int c=q->first;
        int j=0;
        do{ 
                temp[j]=q->buff[c];
                j=(j+1)%new_size;
                c=(c+1)%q->buff_size;
        }while(j!=0);
        
        q->first=0;
        q->last=j;
        free(q->buff);
        q->buff=temp;
        q->buff_size=new_size;

    }
}

int main(){
    struct queue* q=init(5);
    enqueue(q,9);
    enqueue(q,2);
    enqueue(q,9);
    enqueue(q,12);
    enqueue(q,13); 
    print(q);
    
    resize(q,4);
    
    
    //enqueue(q,90);
    //enqueue(q,91);
    
    print(q);
    
    destroy_queue(q);

return 0;
}
