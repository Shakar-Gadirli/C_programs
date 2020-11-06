#include <stdio.h>
#include <stdlib.h>
/*void create_arr(int *arr,int n){
	
	printf("Enter elements of array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		

	}


}
*/
/*void print_arr(int *arr,int n){
	for(int i=0;i<n;i++){		
		printf("%d",arr[i]);

	}


}
*/
struct node{
	int data;
	struct node* link;
	

};
struct node* head;

struct node *create(int data){

	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	if(head!=NULL)
		temp->link=head;
	head=temp;
	return temp;
}


void append(struct node *head,int data){
	struct node *temp=create(data);
	struct node *p=head;
	while(p->link!=NULL){
		p=p->link;

	}
	p->link=temp;


}

void arr_to_list(int *arr,int n){
	struct node* head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=arr[0];
	temp->link=NULL;
	head=temp;

	for(int i=1;i<n;i++){

	/*struct node* p=(struct node*)malloc(sizeof(struct node));
		temp->link=p;
		p->data=arr[i];
		p->link=NULL;
		temp=p;*/
		append(head,arr[i]);
		
	}




}

void traverse(){
	struct node *head;
	struct node *p=head;
	while(p!=NULL){
		printf("%d",p->data);
		p=p->link;

	}
	printf("\n");

}



int main(){
	int n;
	printf("Enter number of elements in array\n");
	scanf("%d", &n);
	int arr[n];
	for (int i=0;i<n;i++){
		scanf("%d", &arr[i]);


	}	
//create_arr(arr,n);
//	print_arr(arr,n);

	//create_arr( int *arr,int n);
//	print_arr(arr,n);
	//int a=create_arr(int *arr,int n);
//	create(int data);
//	append(struct node* head,int data);
	arr_to_list(arr,n);
	traverse();
	return 0;


}
