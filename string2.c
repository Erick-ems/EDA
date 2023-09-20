/*fa�a um programa que leia uma string e a imprima de tr�s para frente. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char string[30];
	int i;
	
	gets(string);
	
	for (i = strlen(string)-1; i >= 0; i--) printf("%c", string[i]);
	
	printf("\n");
	
	return 0;
}