#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libctf.h"

void success()
{
    	FILE * fp;
    	char * line = NULL;
    	size_t len = 0;
    	ssize_t read;

    	fp = fopen("/root/Desktop/CTF/res/flag.txt", "r");
    	if(fp == NULL){
		fputs("Error: failed to open flag.txt file", stderr);
		exit(1);
	}

    	while ((read = getline(&line, &len, fp)) != -1) {
    	    	write(1, line, read);
    	}

    	fflush(stdout);
    	fclose(fp);

    	if(line)
    	    free(line);

    	exit(0);
}
