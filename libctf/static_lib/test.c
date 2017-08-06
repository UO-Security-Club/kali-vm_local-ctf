#include <stdio.h>
#include <stdlib.h>
#include "libctf.h"

void main() {
	puts("Attempting to invoke static lib function: success()");
	success();
	return;
}
