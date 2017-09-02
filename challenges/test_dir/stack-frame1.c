#include <stdio.h>
#include <stdlib.h>

/*
Compiled with:
	gcc -m32 -mpreferred-stack-boundary=2 stack-frame1.c -o stack-frame1
*/

void func2(int y) {
	int z = y + 2;
	printf("%d\n", z);

	return;
}

void func1(int x) {
	int y = x + 1;
	func2(y);

	return;
}

void main() {
	int x = 0;
	func1(x);

	return;
}
