#Compile lib source file into PIC
gcc -m32 -c -Wall -Werror -fpic libctf.c

#Build shared lib from compiled object file
gcc -m32 -shared -o libctf.so libctf.o

#Move shared lib into standard dir with correct permissions
cp libctf.so /usr/lib32
chmod 0755 /usr/lib32/libctf.so

#Update the loader (otherwise -lctf won't link properly)
ldconfig

#compile the target binary
#gcc -m32 -Wall -o test test.c -lctf
