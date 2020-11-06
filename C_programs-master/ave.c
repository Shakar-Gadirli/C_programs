#include <stdio.h>
void func(float arr[],int n){
     float sum=0;
     float ave;
	for(int i=0;i<n;i++){
		sum=sum+arr[i];
	
	}

	ave=sum/n;
	for(int i=0;i<n;i++){
		if (arr[i]<=ave)
			arr[i]/=2;
		else 
			arr[i]*=2;
	
	
	}
	


}


int main(){
	int n;
	float arr[128];

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%f",&arr[i]);
	}
     func(arr,n);
      for(int i=0;i<n;i++){
	      printf("%.2f\n",arr[i]);
      }
      func(arr,n);

      
return 0;

}
