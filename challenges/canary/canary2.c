#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libctf/static_lib/libctf.h"

int func1() {
	int login_status = 0;
	/*sets canary value to hex notation of 3,735,928,559*/
	int canary = 0xdeadbeef;
	char uname_buf[32];

	puts("Enter Username:");
	/*Read up to 38 bytes of user input into uname_buf*/
	if(!fgets(uname_buf, 38, stdin)){
		fputs("Error: failed to read input.", stderr);
		exit(1);
	}

	/*If the secure_login() function returns non-zero (it never will), set login_status to 1,*/
	if(secure_login(uname_buf)){
		login_status = 1;
	}

	/* If the canary is no longer equal to 0xdeadbeef,
	We assume a buffer overflow! */
	if(canary != 0xdeadbeef){
    		puts("Buffer Overflow Detected!");
		exit(1);
	}

	return login_status;
}

void main() {

	/*If func1() returns a non-zero value, then the login was successful*/
	if(func1()){
		puts("Login was successful\nDispensing sensitive information:");
		/* v---< Objective is to call the success() function*/
        	success();
		/*the success() function calls exit directly instead of returning*/
    	}

       	puts("Failed to login\nIncorrect username");
    	return;
}
