#!/bin/bash

echo "Installing dependencies..."
sleep 3

# Dağıtımı tespit et
if [ -f /etc/debian_version ]; then
   sudo apt-get update
   sudo apt-get install -y libpcap0.8 libcurl4
   pip3 install scapy
   pip3 install requests
   #pip3 install jsonlib
   echo "Dependencies downloaded and installed."
   
   
elif [ -f /etc/arch-release ]; then
   sudo pacman -Sy 
   sudo pacman -S --noconfirm libpcap libcurl
   pip3 install scapy
   pip3 install requests
   echo "Dependencies downloaded and installed."
   
   
elif [ -f /etc/redhat-release ]; then
   sudo dnf makecache
   sudo dnf install -y libcurl libpcap
   pip3 install scapy
   pip3 install requests
   #pip3 install jsonlib
   echo "Dependencies downloaded and installed."
   
   
else
   echo "This distribution is not supported."
   
fi
