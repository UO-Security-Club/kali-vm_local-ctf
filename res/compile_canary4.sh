CHL_FILE="../challenges/canary/canary4.c"
LB1_FILE="../libctf/success.c"
LB2_FILE="../libctf/secure_login.c"
BIN_FILE="../challenges/canary/canary4"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $CHL_FILE $LB1_FILE $LB2_FILE -fno-stack-protector
