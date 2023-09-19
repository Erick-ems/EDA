		#include <stdio.h>



int main(){


	

	int x,y,z,a,b,c;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);

	int la = x/a;
	int al = y/b;
	int pro = z/c;
	

	int total = la*al*pro;
	printf("%d\n", total);

	return 0;



}
