#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;

};


struct node* init(int data){
    struct node* nn=(struct node*)malloc(sizeof(struct node*));
    nn->next=NULL;
    nn->data=data;
    return nn;
}
struct node* addtoempty(struct node** last,int data){
    struct node* nn=init(data);
    if((*last)!=NULL)
        return (*last);
    *last=nn;
    (*last)->next=(*last);
    return (*last);
}

struct node* addBegin(struct node** last,int data){
    struct node* nn=init(data); 
    if((*last)==NULL){
       return addtoempty(last,data);

    }
    nn->next=(*last)->next;
    (*last)->next=nn;
    return (*last);
}

struct node* addEnd(struct node** last,int data){
    struct node* nn=init(data);
    if((*last)==NULL)
        return addtoempty(last,data);
    
    nn->next=(*last)->next;
    (*last)->next=nn;
    (*last)=nn;
    return (*last);
}

struct node* add_after(struct node** last,int item,int data){
    struct node* nn=init(data);
    struct node* p=(*last)->next;
 //   struct node* prev=last;
    
    
    do{
        if(p->data==item){
                nn->next=p->next;
                p->next=nn;

                if(p==(*last))
                    *last=nn;
                return (*last);
        }
        p=p->next;


    }while(p!=(*last)->next);

    printf("Not present in the list\n");

    return (*last);
}

struct node* remove_item(struct node** last,int item){
    struct node* curr=(*last)->next;
    struct node* prev=(*last);
    do{
        if(curr->data==item){
            prev->next=curr->next;
            

            if(curr==(*last)){
                (*last)=prev;
                return (*last);

            }
        
            free(curr);
            break;
        }
            prev=curr;
            curr=curr->next;
        }while(curr!=(*last)->next);
    return (*last);
}

struct node* remove_pos(struct node** last,int pos){
    struct node* curr=(*last)->next;
    struct node* prev=(*last);

    while((pos-1)>0){
        prev=curr;
        curr=curr->next;
        pos--;
    }
    prev->next=curr->next;

    if(curr==(*last)){
        (*last)=prev;
        return (*last);
    }

    free(curr);
    return (*last);
}

void traverse(struct node** last){
    if((*last)==NULL)
        return;
    struct node* p=(*last)->next;
    do{
        printf("%d\t",p->data);
        p=p->next;
    
    }while(p!=(*last)->next);
    printf("\n");
}

int main(){
    struct node* last=NULL;
    addtoempty(&last,4);
    traverse(&last);
    addEnd(&last,5);
    addEnd(&last,6);
    addEnd(&last,7);
    addEnd(&last,8);
    traverse(&last);
    add_after(&last,6,3);
    traverse(&last);
    add_after(&last,8,9);
    traverse(&last);
    add_after(&last,5,12);
    traverse(&last);
    remove_item(&last,3);
    traverse(&last);
    remove_pos(&last,3);
    traverse(&last);

return 0;
}
