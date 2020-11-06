#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};


node* init(int data){
    node* nn=new node();   
    nn->data=data;
    nn->next=NULL;
    return nn;
}

void append(node** head,int data){
    node* nn=init(data);
    if(*head==NULL){
        *head=nn;
        return;
    }
    node* p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=nn;
 }

void push(node** head,int data){
    struct node* nn=init(data);
    if(*head==NULL){
        *head=nn;
        return;
    }
    nn->next=*head;
    *head=nn;
}

void insert_item_after(struct node** head,int item,int data){
    struct node* nn=init(data);    
    if(*head==NULL){
            *head=nn;
            return;
        }
    struct node* p=*head;
    while(p->data!=item){
        p=p->next;
    
        }
    nn->next=p->next;
    p->next=nn;
}
void insert_item_before(struct node** head,int item,int data){
   struct node* p=*head;
    struct node* nn=init(data);
    if(*head==NULL){
        *head=nn;
        return;
    }
    while(p->next->data!=item){
        p=p->next;
    }

    nn->next=p->next;
    p->next=nn;
}

void insert_after_pos(struct node** head,int pos,int data){
    struct node* nn=init(data);
    struct node* p=*head;
    if(pos==1){
        nn->next=*head;
        *head=nn;
        return;
    }
    while(pos-1>0){
        p=p->next;
        pos--;
    }
    nn->next=p->next;
    p->next=nn;
}

void delete_idx(struct node** head,int idx){
    struct node* prev=*head;
    struct node* p=*head;
    if(idx==0){
        *head=(*head)->next;
        free(p);
        return;
    }
   while(idx>0){
       prev=p;
       p=p->next;
       idx--;
   }
    prev->next=p->next;
    free(p);


}
void delete_item(struct node** head,int item){
    struct node* p=*head;
    struct node* prev=*head;
    if(p->data==item){
        (*head)=(*head)->next;
        free(p);
    }
    while(p->data!=item && p!=NULL){
        prev=p;
        p=p->next;
    }
    if(p==NULL)
        return;
    prev->next=p->next;
    free(p);
}
void traverse(struct node** head){
    struct node* p=*head;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");


}
int main(){
    struct node* head=NULL;
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,8);

    traverse(&head);
    push(&head,4);
    
    traverse(&head);

    delete_item(&head,8);
    traverse(&head);


  /*  

    insert_item_after(&head,8,9);
    traverse(&head);
    insert_item_before(&head,9,12);
    traverse(&head);
    */
    insert_after_pos(&head,0,20);
    traverse(&head);
   /* delete_idx(&head,0);
    traverse(&head);
    delete_item(&head,20);
    traverse(&head);
    delete_item(&head,9);
    traverse(&head);*/



}
