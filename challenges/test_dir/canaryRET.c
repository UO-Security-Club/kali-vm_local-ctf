#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libctf/static_lib/libctf.h"

/*
Source file name:
	canary1.c
Compiled with:
	gcc -m32 -mpreferred-stack-boundary=2 -o canary1 canary1.c -L../libctf/static_lib -lctf -fno-stack-protector -no-pie
*/

int func1() {
	int login_status = 0;
	char uname_buf[32];

	puts("Enter Username:");
	/*Read up to 38 bytes of user input into uname_buf*/
	if(!fgets(uname_buf, 48, stdin)){
		fputs("Error: failed to read input.", stderr);
		exit(1);
	}

	/*If the secure_login() function returns non-zero (it never will), set login_status to 1,*/
	if(secure_login(uname_buf)){
		login_status = 1;
	}

	return login_status;
}

void main() {

	/*If func1() returns a non-zero value, then the login was successful*/
	if(func1()){
		puts("Login was successful\nDispensing sensitive information:");	
        	success();
		/*the success() function calls exit directly instead of returning*/
    	}

       	puts("Failed to login\nIncorrect username");
    	return;
}

