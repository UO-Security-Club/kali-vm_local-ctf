CHL_FILE="/root/Desktop/CTF/challenges/canary/canaryN.c"
HDR_FILE="/root/Desktop/CTF/libctf/success.c"
BIN_FILE="/root/Desktop/CTF/challenges/canary/canaryN"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $CHL_FILE $HDR_FILE -fstack-protector -no-pie
