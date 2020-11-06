#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node* init(int data){
	struct node *temp=(struct node*)malloc(struct node);
	temp->link=NULL;
	temp->data=data;
	return temp;
}


void append(struct node** head,int data){	struct node* temp=init(data);
	if(*data==NULL){
		*data=temp;
		return;
	}
	struct node* p=*head;
	while(p->link!=NULL){
		p=p->link;
	}
	p->link=temp;
}

void traverse(struct node * head){
	struct node* p=head;
	while(p!=NULL){
		printf("%d\t",p->data);
		p=p->link;
	}
}

void push(struct node** head){
	struct node* temp=init(data);
	if(*head=NULL){
		*head->link=temp;
		return;
	}
	temp->link=*head;
	*head=temp;
}

void delete_node(struct node** head,int item){	
	struct node *p=*head;
	if(p->data==item){
		*head=(*head)->link;
		free(p);
		return;
	}

	while(p->link->data!=item && p->link!=NULL){
		p=p->link;
	}

	if(p->link==NULL){
		return;
	}
	struct node r_temp=p->link;
	p->link=p->link->link;
	free(p);

}

void delete_pose(struct node** head,int item){
	struct node* p=*head;
	struct node* prev=NULL;

	if(pos==0){
		*head=*head->link;
		free(p);
		return;

	}
	while(p-- && p!=NULL){
		prev=temp;
		p=p->link;
	}
	if(p==NULL)
		return;
	prev->link=p->link;
	free(p);

}


int main(){
struct node* head=NULL;
append(&head,12);
append(&head,13);
append(&head,14);
push(&head,222);
push(&head,987);

delete_node(&head,13);


return 0;
}
