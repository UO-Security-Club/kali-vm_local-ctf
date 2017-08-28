#compile with static libctf

SRC_FILE="../challenges/canary/canary1.c"
LIB_DIR="../libctf/static_lib/"
BIN_FILE="../challenges/canary/canary1"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $SRC_FILE -L$LIB_DIR -lctf -fno-stack-protector -no-pie -z execstack
