#!/usr/bin/python3

from scapy.all import sniff, Ether, ARP, IP, TCP, UDP
import signal
import sys
import time


def image_look(interface):
	
    try:
        print("\033[1;37m\n\nDeveloper: Hunkar Acar => (Cyber Security Guard)\033[0m")
        fund = "_________________________________________________________"
        print("\033[1;37m%s\033[0m\n" % fund)
        print("\033[1;37m| SiGloG 1.1 Software Inc.\033[0m")
        print("\033[1;37m|\033[0m")
        print("\033[1;37m|\033[0m")
        print("\033[1;37m|-SiGloG ####\033[0m")
        use = "|-The network is listening on the specified network interface"
        print("\033[1;37m%s\033[0m" % use)
        print("\033[1;37m|-State: Network Listening\033[0m")
        print(f"\033[1;37m|-Interface: {interface}\033[0m")
        print("\033[1;37m|-Running Parameter: --sniff-python\033[0m")
        print("\033[1;37m|-Listening and getting information from the network:\033[0m")
        print("\033[1;37m\t|-Ether / IP\033[0m")
        print("\033[1;37m\t|-Ether / IP / TCP / Dns Qry\033[0m")
        # print("\033[1;37m\t|-HEX Dump\033[0m")
        print("\033[1;37m\t|-Source IP\033[0m")
        print("\033[1;37m\t|-Destination IP\033[0m")
        # print("\033[1;37m\t|-Organization\033[0m")
        print("\033[1;37m|\033[0m")
        print("\033[1;37m| SiGloG 1.1 Software Inc.\033[0m\n\n\n\n\n")
        time.sleep(4)


    except KeyboardInterrupt:
        print("\nSniffing Stopped!!!\n")
        sys.exit(0)


# Defining Variables
packet_count = 0
tcp_count = 0
udp_count = 0
arp_count = 0
total_data_size = 0


def network_sniff(packet):
	
    try:
        global packet_count, tcp_count, udp_count, arp_count, total_data_size

        packet_count += 1

        if Ether in packet:
            eth_pkt = packet[Ether]

            if ARP in eth_pkt:
                arp_count += 1
                print(packet.summary())

            if IP in eth_pkt:
                ip_pkt = eth_pkt[IP]

                if TCP in ip_pkt:
                    tcp_count += 1
                    total_data_size += len(ip_pkt[TCP].payload)
                    print(packet.summary())  # Paketi ekrana yazdır
                elif UDP in ip_pkt:
                    udp_count += 1
                    total_data_size += len(ip_pkt[UDP].payload)
                    print(packet.summary())  # Paketi ekrana yazdır

    except KeyboardInterrupt:
        print("^C Sniff Stopped::")

    except Exception as e:
        print(f"Return Error Code => {e}")


time.sleep(2)


def signal_handler(signal, frame):
	
    print(f"\n\nNumber of Packet: {packet_count}")
    print(f"Number of TCP packet: {tcp_count}")
    print(f"Number of UDP packet: {udp_count}")
    print(f"Number of ARP packet: {arp_count}")
    print(f"Total data size: {total_data_size} bytes - Total Data Size KB:({int(total_data_size)/1024}) - Total Data Size MB:({int(total_data_size)/1048576})")

    sys.exit(0)


try:
	
	# Specify the network interface you want to listen to
	if len(sys.argv) != 2:
		print("Usage: python script.py <interface>")
		sys.exit(1)

	interface = sys.argv[1]

	image_look(interface)

	# Processor for the Ctrl+C signal
	signal.signal(signal.SIGINT, signal_handler)

	# Use the sniff function to listen to the network on the specified interface
	sniff(iface=interface, prn=network_sniff)
	
	
except Exception as error:
	print(f"Return Error COde => Attention!!!: {error}\n")
