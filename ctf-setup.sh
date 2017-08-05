$RESDIR="/var/ctf"
if [ ! -d "$RESDIR" ]; then
	mkdir /var/ctf
	cp -r res/ /var/ctf/
fi
