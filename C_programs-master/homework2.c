#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* link;
};
//struct node* head=NULL;

struct node* create(int n){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->link=NULL;
	temp->data=n;
	return temp; 
}

void append(struct node **head,int data){
	struct node *temp=create(data);
	if (*head == NULL){
		(*head)=temp;
		return;
	}
	struct node *p=(*head);
	while(p->link !=NULL){
		p=p->link;
	}
	p->link=temp;
}

void traverse(struct node *head){
	struct node* p=head;
	while(p != NULL){
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");

}

void find_and_change(struct node** head,int num,int item){
	struct node* temp=(*head);
	struct node* q=(*head);
	while(temp!=NULL && q->link!=temp){
		
		if(temp->data==num && temp==(*head)){
			temp->link->data=item;
		}
		else if(temp->data==num && temp->link==NULL){
		
			q->data=item;
		
		}
		else if(temp->data==num && temp!=(*head) && temp->link != NULL){
			temp->link->data=item;
			q->data=item;
			
		}
		temp=temp->link;
		q=q->link;
	}

}



int main(){
	struct node* head=NULL;
	append(&head,1);
	append(&head,3);
	append(&head,4);
	append(&head,9);

	traverse(head);

	find_and_change(&head,4,5);
	traverse(head);

	return 0;
}

