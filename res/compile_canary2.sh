CHL_FILE="/root/Desktop/CTF/challenges/canary/canary2.c"
HD1_FILE="/root/Desktop/CTF/libctf/success.c"
HD2_FILE="/root/Desktop/CTF/libctf/secure_login.c"
BIN_FILE="/root/Desktop/CTF/challenges/canary/canary2"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $CHL_FILE $HD1_FILE $HD2_FILE -fno-stack-protector -no-pie
