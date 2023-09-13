#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void sniff_python_dump(const char *iface) {
    
    char command[256];
    
    //command and arguments combining
    snprintf(command,sizeof(command), "python3 networksniff.py %s", iface);
    int result = system(command);
    
    //command exit code
    if (result == 0) {
		//printf("\n\nCommand working Successfuly\n");
		}
		 
	else {
		//printf("Command Failed!");
	}
	
}
