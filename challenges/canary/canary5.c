#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../libctf/static_lib/libctf.h"

struct user {
        char *info;
};

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


void func1(char *dest)
{
	unsigned int canary = generate_canary();
        char buf[32];

	puts("Enter User Info:");

	if(!fgets(buf, 64, stdin)){
		fputs("Error: failed to read input.", stderr);
                return;
	}

	strcpy(dest, buf);

        if((canary ^ canary_backup) != 0){
                puts("Stranger-Danger!!! I'm running away and never returning!"); 
                exit(1);
        } 

        return;
}

void main()
{
        struct user *user1;
	char *user_info;

        user1 = malloc(sizeof(struct user));
        user1->info = malloc(64);

        user_info = user1->info;
        func1(user_info);

        printf("Saved User Info: %s\n", user1->info);
        free(user1->info);
        free(user1);
        
        return;
}
