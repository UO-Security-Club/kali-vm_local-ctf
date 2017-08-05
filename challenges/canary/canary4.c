#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../libctf/libctf.h"

char ID_buf[64];
unsigned int canary_backup;

unsigned int generate_canary() {
        unsigned int tmp_canary;
        FILE *fp;

        fp = fopen("/dev/urandom", "r");
	/*Attempt to read a random value from /dev/urandom*/
        if(!(fread(&tmp_canary, sizeof(tmp_canary), 1, fp))){
                puts("Error reading from /dev/urandom");
                exit(1);
        }

        fclose(fp);

	/*Store copy of random value as global var for refernce later*/
        canary_backup = tmp_canary;

	/*Test that the random value is non-null and
	that the copy is equivalent to original value before returning it*/
        if((tmp_canary == 0) || (tmp_canary ^ canary_backup) != 0){
                exit(1);
        }

        return(tmp_canary);
}

int get_ID() {
        memset(ID_buf, 0, 64);
        strcpy(ID_buf, "Password for ID: ");
        size_t len =  strlen(ID_buf);
        size_t space_remaining = 64 - len;

        puts("Enter ID:");

        if(fgets(&ID_buf[len], space_remaining, stdin)){
                return 0;
        }

        return -1;
}

int func1() {

        int login_status = 0;
        unsigned int canary = generate_canary();
        char buf[32];

        memset(buf, 0, 32);

        printf(ID_buf); 

	if(!fgets(buf, 40, stdin)){
		fputs("Error: failed to read input.", stderr);
                return 0;
	}

        if((canary ^ canary_backup) != 0){
                puts("Stranger-Danger!!! I'm running away and never returning!"); 
                exit(1);
        }

        return login_status;
}

void main() {

    	if(get_ID() != 0){
    		return;
    	}

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

