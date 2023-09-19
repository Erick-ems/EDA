#include <stdio.h>



int main (){

	int lista[5];
	int i;
	for(i = 0; i < 5; i++){
		scanf("%d", &lista[i]);
	}

	int crescente = 1;
	// verificar se os valores estão crescentes já assumindo o pressuposto que estão

	for(i = 1; i < 5; i ++){
		if(lista[i] < lista[i-1]){
			crescente = 0;
			break;
		}
	}
	int decrescente = 1;
	// verificar se os valores estão decrescente já assumindo o pressuposto que estão
	for(i = 1; i < 5; i++){
		if(lista[i] > lista[i-1]){
			decrescente = 0;
			break;
		}
	}
	
	if(crescente){
		printf("C\n");
	}else if(decrescente){
		printf("D\n");
	}else{
		printf("N\n");
	}



	return 0;
}
