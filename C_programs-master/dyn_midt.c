#include<stdio.h>
#include<stdlib.h>
struct vector{
    int *buff;
    int start,pos;
    int arr_size;
};

struct vector* init(int size){
    struct vector* v=(struct vector*)malloc(sizeof(struct vector));
    v->buff=(int*)malloc(sizeof(int)*size);
    v->arr_size=size;
    v->start=0;
    v->pos=-1;

}

void push(struct vector* v){
    if(v->pos>=v->arr_size){
        return;
    }
    for(int i=0;i<v->arr_size;i++){
        v->pos=v->pos+1;
        v->buff[v->pos]=0;
}
}

int pop(struct vector* v){
    if(v->pos<=-1)
        return -1e9;
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
    return -1e9;
}


void resize_arr(struct vector* v,int new_size){
    int* temp=(int*)malloc(sizeof(int)*new_size);
    int c=0;

    if((v->pos)-(v->start)<new_size){
            for(int i=0;i<v->arr_size;i++){  
            temp[c]=(v->buff[i])+10;
            c++;
        }
        v->pos=c;
        v->start=0;
        free(v->buff);
        v->buff=temp;
        v->arr_size=new_size;

   }
    else{   
        for(int i=0;i<new_size;i++){
            temp[c]=v->buff[i]+10;
            c++;
        }
        v->pos=c;
        v->start=0;
        free(v->buff);
        v->buff=temp;
        v->arr_size=new_size;
    
    
    }
}

void check_status(struct vector* v, int print_elements){

    printf("\n------------ Current Status Report ------------------\n\n");
    printf("Buffer Size: %d\n", v->arr_size);
    printf("First Pos: %d, Last pos: %d\n", v->start, v->pos);
    printf("Items Number: %d\n", v->pos - v->start);

    if (print_elements){
        printf("Items: ");
        for(int i = v->start; i < v->arr_size; i++){
            printf("%d ", v->buff[i]);
        }
        printf("\n");
    }
    printf("\n-----------------------------------------------------\n");

}

int main(){
    struct vector* v=init(5);
    
    push(v);
    check_status(v,1);
    //printf("%d",pop(v)); 
    int n;
    printf("Enter new size of array\n");
    scanf("%d",&n);
    
    resize_arr(v,n);
    check_status(v,1);

    return 0;
}
