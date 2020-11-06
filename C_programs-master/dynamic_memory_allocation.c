#include<stdio.h>
#include<stdlib.h>

void print_arr(int *arr, int n){
	for(int i =0; i < n; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
}


int main(){
	int n;
	scanf("%d", &n);

	int *a = (int*) malloc(sizeof(int) * n);

	for(int i = 0; i < n; i++){

		int temp;
		scanf("%d", &temp);
		a[i] = temp;
	}

	print_arr(a, n);

	printf("Do you want to change the arr size\n");
	int m;
	scanf("%d", &m);

	int *buff = (int*) malloc(sizeof(int) * m);
	
	if (m > n){
		for(int i = 0; i < n; i++){
			buff[i] = a[i];
		}
		for(int i = n; i < m; i++){
			buff[i] = 0;	
		}
	}
	else{
		for(int i =0; i < m; i++){
			buff[i] = a[i];
		}
	}
	free(a);

	a = buff;

	print_arr(buff, m);

return 0;
}
