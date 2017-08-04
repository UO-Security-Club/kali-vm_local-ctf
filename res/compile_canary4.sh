CHL_FILE="/root/Desktop/CTF/challenges/canary/canary4.c"
LB1_FILE="/root/Desktop/CTF/libctf/success.c"
LB2_FILE="/root/Desktop/CTF/libctf/secure_login.c"
BIN_FILE="/root/Desktop/CTF/challenges/canary/canary4"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $CHL_FILE $LB1_FILE $LB2_FILE -fno-stack-protector -no-pie
