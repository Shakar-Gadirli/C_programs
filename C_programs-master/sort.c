#include <stdio.h>

void sort(int arr[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for (int j=0;j<n-1;j++){
			if( arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
		}
	}

}

}



int main(){
	int arr[]={2,5,8,25,0,83,1};
	int num=sizeof(arr)/sizeof(int);
	sort(arr,num);

	
	for(int i=0;i<num;i++){

		printf("%d ",arr[i]);
	}
	return 0;
}
