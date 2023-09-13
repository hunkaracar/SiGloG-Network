#!/usr/bin/python3

from scapy.all import *
import sys
import time

def image_look_2(loc_term):
	
	try:
		
		print("\033[1;37m\n\nDeveloper: Hunkar Acar => (Cyber SecurITy Guard)\033[0m")
		fund = "_________________________________________________________"
		print("\033[1;37m%s\033[0m\n" % fund)
		print("\033[1;37m| SiGloG 1.1 Software Inc.\033[0m")
		print("\033[1;37m|\033[0m")
		print("\033[1;37m|\033[0m")
		print("\033[1;37m|-SiGloG ####\033[0m")
		use = "|-Reading pcap file"
		print("\033[1;37m%s\033[0m" % use)
		print("\033[1;37m|-State: Reading\033[0m")
		print(f"\033[1;37m|-Pcap file name: %s\033[0m" % loc_term)
		print("\033[1;37m|-Running Parameter: -RA\033[0m")
		print("\033[1;37m|-Network listening results are read from pcap file\033[0m")
		print("\033[1;37m\t|-Ether / IP / \033[0m")
		print("\033[1;37m\t|-Ether / IP / TCP / Dns Qry \033[0m")
		#print("\033[1;37m\t|-HEX Dump\033[0m")
		print("\033[1;37m\t|-Source IP\033[0m")
		print("\033[1;37m\t|-Destination IP\033[0m")
		#print("\033[1;37m\t|-Organization\033[0m")
		print("\033[1;37m|\033[0m")
		print("\033[1;37m| SiGloG 1.1 Software Inc.\033[0m")
		print("\033[1;37m|\033[0m")
		print("\033[1;37m|\033[0m")
		print("\033[1;37m|\033[0m")
		print("\033[1;37m|\033[0m")
		print("\033[1;37m|-Pcap F1le Read:\033[0m\n")
		time.sleep(4)
		
	except KeyboardInterrupt:
		print("Pcap file reading Stop!!!\n")
		sys.exit(0)
		

def pcap_read(pcap_file):
	
	packts =  rdpcap(pcap_file)
	
	for packt in packts:
		print(packt.summary())
	


loc_term = sys.argv[1]
image_look_2(loc_term)
pcap_read(loc_term)
