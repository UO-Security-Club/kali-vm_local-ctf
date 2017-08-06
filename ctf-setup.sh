$RESDIR="/var/ctf"
if [ ! -d "$RESDIR" ]; then
	mkdir /var/ctf
fi
	cp -r res/ /var/ctf/
