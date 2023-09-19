#include <stdio.h>


int main(){


	float A, G, Ra, Rg;

	scanf("%f %f %f %f", &A, &G, &Ra, &Rg);


	float contaA = Ra/A;
	float contaG = Rg/G;

	if(contaA == contaG){
		printf("G\n");
	}else if(contaA > contaG ){
		printf("A\n");
	}else{
		printf("G\n");
	}









	return 0;

}
