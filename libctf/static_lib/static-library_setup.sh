#compile library file
gcc -m32 -c libctf.c -o libctf.o

#build static library
ar rcs libctf.a libctf.o

#compile test program
gcc -m32 -o test test.c -L. -lctf

#run test
./test
