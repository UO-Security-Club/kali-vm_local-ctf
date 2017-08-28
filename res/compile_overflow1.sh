#compile with static libctf

SRC_FILE="../challenges/classic_overflow/overflow1.c"
BIN_FILE="../challenges/classic_overflow/overflow1"

gcc -m32 -mpreferred-stack-boundary=2 -o $BIN_FILE $SRC_FILE -fno-stack-protector -no-pie
