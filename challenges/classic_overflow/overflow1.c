#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
Source file name:
	overflow1.c
Compiled with: 
	gcc -m32 -mpreferred-stack-boundary=2 -o overflow1 overflow1.c -fno-stack-protector -no-pie
*/

char str[] = "Enter Input:\n";

int func1() {
	int As = 0x41414141;
	char buf[32];

	write(1, str, strlen(str));

	read(0, buf, 36);

	return As;
}

void main() {
	int ret = func1();

	printf("func1() returned: 0x%08x\n", ret);
	return;
}
