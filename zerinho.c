
#include <stdio.h>



int main(){

	int a,b,c;
	scanf("%d %d %d",&a, &b, &c);

	if(a == b && a == c && b == c){
		printf("empate\n");
	}else if(a == b && a != c){
		printf("C\n");
	}else if(a == c && a != b){
		printf("B\n");
	}else{
		printf("A\n");
	}



	return 0;
}
