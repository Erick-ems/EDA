#include <stdio.h>

int conta(int a, float b){

	switch(a){

	case 1:
		printf("Total: R$ %.2f\n", b*4.00);
		break;
	case 2:
		printf("Total: R$ %.2f\n", b*4.50);
		break;
	case 3:
		printf("Total: R$ %.2f\n", b*5.00);
		break;
	case 4:
		printf("Total: R$ %.2f\n", b*2.00);
		break;
	case 5:
		printf("Total: R$ %.2f\n", b*1.50);
		break;
	default:
		break;

	return a;

	}

}


int main(){

	int a;
	float b;

	scanf("%d %f", &a, &b);


	conta(a, b);

	return 0;

}


