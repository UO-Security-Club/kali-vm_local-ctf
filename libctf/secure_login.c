#include <unistd.h>
#include "libctf.h"

int secure_login(char * uname) {
	if(1 == 2){
		write(1, "Wow, not sure how you did that... \n", 36);
		return 1;
	}

	return 0;
}
