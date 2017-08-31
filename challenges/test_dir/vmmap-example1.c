#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char global_var[] = "I'm a string in the data segment!";

void func2() {
/*
This function prints the address of a global variable
and the string located at that address before returning.
*/
	
        printf("[*] Printing what's at address: 0x%08x\n%s\n\n", global_var, global_var);

	return;
}

void func1() {
/*
This function allocates memory in the heap,
copies a string into the allocated memory,
prints the string, frees the allocated memory,
and then calls func2.
*/

	char * heap_pointer = (char *)malloc(32);

	strcpy(heap_pointer, "Im a string in the heap!");
	printf("[*] Printing what's at address: 0x%08x\n%s\n\n", heap_pointer, heap_pointer);

	free(heap_pointer);

	func2();
	return;
}

void main() {
/*
This function stores an integer as a local variable,
prints its value and address and then calls func1.
*/
	int local_var = 256;

	printf("[*] Printing what's at address: 0x%08x\n%d\n\n", &local_var, local_var);
	func1();

	return;
}
