CHL_FILE="../challenges/canary/canary2.c"
HD1_FILE="../libctf/success.c"
HD2_FILE="../libctf/secure_login.c"
BIN_FILE="../challenges/canary/canary2"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $CHL_FILE $HD1_FILE $HD2_FILE -fno-stack-protector
