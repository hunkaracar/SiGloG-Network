#include <stdio.h>
#include <stdlib.h>


void print_document(){
	 
     printf("\nSiGloG 1.I Software Dev.Inc.\n");
     printf("\nDetailed help documentation:\n");
     printf("\tsiglog -h\n");
     printf("\tsiglog --help\n");
     printf("\tsiglog -V\n");
     printf("\tsiglog -i eth0 --dump  || <Interface (eth0,wlan0)>\n");
     printf("\tsiglog -L <targetIP>\n");
     printf("\tsiglog -RA <pcap_file:path>\n");
     printf("\tsiglog --scan=modem <modem:ip>\n");
     printf("\tsiglog --sniff-python <interface>\n");
     printf("\t./siglog --host http://10.0.2.5/dvwa/login.php --http-post '{\\\"username\\\": \\\"username\\\", \\\"password\\\": \\\"password\\\", \\\"Login\\\": \\\"Login\\\"}' -E 'Login failed'\n");
     printf("\tsiglog --docut\n\n");
}
