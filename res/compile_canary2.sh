#compile with static libctf

SRC_FILE="../challenges/canary/canary2.c"
LIB_DIR="../libctf/static_lib/"
BIN_FILE="../challenges/canary/canary2"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $SRC_FILE -L$LIB_DIR -lctf -fno-stack-protector
