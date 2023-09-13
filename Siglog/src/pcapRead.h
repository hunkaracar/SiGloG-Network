#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void pcap_read(const char *file_pcap) {
     
     char command[256];

	 //command and arguments combining
     snprintf(command,sizeof(command), "python3 pcapread.py %s", file_pcap);
     int result = system(command);
     
     //command exit code
     if (result == 0) {
		 //printf("\n\nCommand Working Successfuly\n");
	 }
	 
	 else {
		 //printf("Command Failed!");
	 }
}
