#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int saveData() {
	puts("Would you like to re-enter the data? [Y/n]");
	int c = fgetc(stdin);
	if(c != 0x6e)
		return 1;
	return 0;
}

void func1() {
	char buf[64];

	memset(buf, 0, 64);
	puts("Enter User Data:");
	read(0, buf, 128);

	puts("You Enter:");
	puts(buf);

	if(!saveData())
		return;

	puts("Re-enter data:");
	read(0, buf, 128);

	puts("Data saved. Goodbye!");
	return;
}

void main() {
	func1();
	return;
}
