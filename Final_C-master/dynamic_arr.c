#include<stdio.h>
#include<stdlib.h>
struct vector{
    int *buff;
    int  arr_size;
    int  start,pos;

};

struct vector* init(int size){
    struct vector* v=(struct vector*)malloc(sizeof(struct vector));
    v->buff=(int*)malloc(sizeof(int)*size);
    v->arr_size=size;
    v->start=0;
    v->pos=-1;
}

void append(struct vector* v,int data){
    if(v->pos>=v->arr_size)
        return;
    v->pos=v->pos+1;
    v->buff[v->pos]=data;
}
 
int pop(struct vector* v){
    if(v->pos<=-1)
        return -1e9;
    int res=v->buff[v->pos];
    v->pos=v->pos-1;
    return res;
}

int pop_left(struct vector* v){
    if(v->start>v->pos)
        return -1e9;
    int res=v->buff[v->start];
    v->start=v->start+1;
    return res;

}

void remove_end(struct vector* v){
    if(v->pos<v->start)
        return;
    v->pos=v->pos-1;
}

void remove_begin(struct vector* v){
    if(v->start>v->pos)
        return;
    for(int i=v->start;i<v->pos;i++){
        v->buff[i]=v->buff[i+1];
    }
    v->pos=v->pos-1;
}

void resize_arr(struct vector* v,int new_size){
        int* temp=(int*)malloc(sizeof(int*)*new_size);
        int c=0;
        if(v->pos-v->start<new_size){
            for(int i=v->start;i<=v->pos;i++){
                temp[c]=v->buff[i];
                c++;
            }
            v->arr_size=new_size;
            v->pos=c;
            v->start=0;
            free(v->buff);
            v->buff=temp;
        }
        else{
            c=-1;
            for(int i=v->start;i<new_size;i++){
                c++;
                temp[c]=v->buff[i];
                
            }
            
            
            v->pos=c;
            v->start=0;
            free(v->buff);
            v->buff=temp;
            v->arr_size=new_size;
        }

}

void print(struct vector* v){
    printf("-------------Current status-------------\n");
    printf("\nARRAY SIZE: %d ",v->arr_size);
    printf("\nNUMBER OF ELEMENTS: %d ",(v->pos)-(v->start)+1);
    printf("\nstart: %d, pos: %d  \n",v->start,v->pos);
    for(int i=v->start;i<=v->pos;i++){
            printf("%d ",v->buff[i]);
    }
    printf("\n\n");

}
void delete_index(struct vector* v,int idx){
    if(idx>v->pos || idx<v->start)
        return;
    for(int i=idx;i<v->pos;i++){
        v->buff[i]=v->buff[i+1];
        }
      v->pos=v->pos-1;  
    
}

void delete_element(struct vector* v,int data){
    int c=v->start;
    for(int i=v->start;i<v->pos;i++){
        if(v->buff[i]==data)
            break;
        c++;
    }
    
    for(int j=c;j<v->pos;j++){
        v->buff[j]=v->buff[j+1];
        }
      v->pos=v->pos-1;  
    
 }
void free_memory(struct vector* v){
    free(v->buff);
    free(v);
}

int main(){
    struct vector* v=init(5);
    append(v,1);
    append(v,7);
    append(v,3);
    append(v,4);
    append(v,12);
    print(v);
    //resize_arr(v,3);
    //print(v);
   // remove_end(v);
    //print(v);
    //remove_begin(v);
    //print(v);
    delete_index(v,2);
    print(v);
    delete_element(v,1);
    print(v);
    free_memory(v);
    return 0;
}
