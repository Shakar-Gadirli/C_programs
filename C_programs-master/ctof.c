#include <stdio.h>
int main(){
	int fahr, cel;
	int upper,lower,step;
	lower=0;
	upper=300;
	step=20;
	cel=lower;
	while(cel<=upper){
		fahr=(9*cel/5)+32;
		printf("%d\t%d\n",cel,fahr);
		cel=cel+step;



	}




}
