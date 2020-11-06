#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node* init(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	return temp;
}

void append(struct node** head,int data){
	struct node* temp=init(data);
	if (*head==NULL){
		*head=temp;
		return;
	}
	struct node* p=*head;
	while(p->link!=NULL){
			p=p->link;
		}
		p->link=temp;
	}

void traverse(struct node *head){
	struct node* p=head;
	while(p!=NULL){
		printf("%d\t",p->data);
		p=p->link;
	}
	
	printf("\n\n");
}

void push(struct node** head,int data){
	struct node* temp=init(data);
	if(*head==NULL){
		(*head)->link=temp;
		return;
	}
	temp->link=*head;
	*head=temp;
}
void delete_node(struct node **head,int item){
	struct node *p=*head;
	if(p->data==item){
		*head=p->link;
		free(p);
		return;
	}
	while(p->link->data!=item && p->link!=NULL){
		p=p->link;

	}
	if(p->link==NULL)
		return;
	struct node* r_temp=p->link;

	p->link=p->link->link;
	free(r_temp);
}

void delete_pos(struct node **head,int pos){
	struct node *p=*head;
	struct node *prev=NULL;
	if(pos==0){
		*head=(*head)->link;
		free(p);
		return;

	}
	while(pos-- && p!=NULL){
		prev=p;
		p=p->link;
	}
	if(p==NULL)
		return;
	prev->link=p->link;
	free(p);

}

int main(){
	struct node *head=NULL;

	append(&head,23);
	append(&head,43);
	append(&head,129);
	append(&head,333);
	append(&head,111);
	traverse(head);

	delete_node(&head,43);
	traverse(head);
	delete_pos(&head,2);
	traverse(head);


return 0;
}
