#If using vmware, install vmware tools with:
apt update && apt -y full-upgrade
apt -y install open-vm-tools-desktop fuse
#reboot now

#Application Installs
apt-get install vim
apt-get install gcc
apt-get install gdb
apt-get install git
apt-get install screen
apt-get install gdbserver
apt-get install nasm
apt-get install socat
apt-get install strace
apt-get install ltrace

#32 bit libraries
dpkg --add-architecture i386
apt-get update
apt-get install ia32-libs
apt-get install libc6:i386 libncurses5:i386 libstdc++6:i386 lib32z1
apt-get install libc6-dev-i386
apt-get update

#Download/setup GDB-peda
git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" >> ~/.gdbinit

#Install pip and pwntools
apt-get update
apt-get install python2.7 python-pip python-dev git libssl-dev libffi-dev build-essential
pip install --upgrade pip
pip install --upgrade pwntools
