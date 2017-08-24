#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void func1() {
	char buf[64];

	/*Zero-out memory contents of buf*/
	memset(buf, 0, 64);
	puts("Enter User Data:");

	/*Read up to 76 bytes of data from stdin (int fd 0) into buf*/
	read(0, buf, 76);

	printf("Data entered: %s", buf);
	return;
}

void main() {

	func1();
	return;
}
