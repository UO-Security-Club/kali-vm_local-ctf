#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../libctf/static_lib/libctf.h"

int canary_backup;

int generate_canary() {
	/*Generates a pseudo-random int value seeded with the current system time.
	Stores copy of generated value as global variable for comparison later.*/
	int tmp_canary;
	srand((int) time(0));

	canary_backup = rand();
	tmp_canary = canary_backup;

	return tmp_canary;
}

int func1() {
	int login_status = 0;
    	/*set local canary variable to return value of generate_canary()*/
	int canary = generate_canary();
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
	if(canary != canary_backup){
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

