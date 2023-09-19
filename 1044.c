#include <stdio.h>



int multiplos(int a, int b){

	if (b % a == 0){

		printf("São multiplos\n");
	}else{
		printf("Não são multiplos\n");
	}


}





int main(){


	 int a, b;


	scanf("%d %d", &a, &b);

	multiplos(a, b);

	return 0;


}

