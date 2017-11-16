#include <stdio.h>
#include <stdlib.h>

void foo(int i, int x){
	int j = i + x;
	printf("%d\n", j);
	return;
}

void main(){
	int i = 4;
	int x = 2;

	foo(i, x);

	return;
}
