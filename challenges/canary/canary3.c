#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../libctf/libctf.h"

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
    int local_canary = generate_canary();
    char uname_buf[32];

    puts("Enter Username:");
    if(fgets(uname_buf, 38, stdin) && login_status){

        /* If the local canary is no longer equal to the copy of it's original value,
        We assume a buffer overflow! */
        if(local_canary != canary_backup){
            puts("Buffer Overflow Detected!"); 
            exit(1);
        }
    }
   
    return login_status;
}

void main() {

    /*If func1() returns a non-zero value, then the login was successful*/
    if(func1()){
        puts("Login was successful\nDispensing sensitive information:");
        success(); //Print flag
    }else{
        puts("Failed to login\nIncorrect username");
    }

    return;
}

