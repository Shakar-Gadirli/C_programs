#include <stdio.h>

int sum_of_array(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];



	}
	
	return sum;

}




int main(){

	int arr[]={1,8,8,9,5,5,7,4};
	int s=sum_of_array(arr,sizeof(arr)/sizeof(int));
	printf("Sum of array is %d",s);


	return 0;
}


