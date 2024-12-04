#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "liveCap.h"
#include "locationDet.h"
#include "version.h"
#include "modemRecon.h"
#include "sniffPy.h"
#include "pcapRead.h"
#include "document.h"
#include "loginBruteForce.h"

int main(int argc, char *argv[]) {
	
    //char purpose[] = "This Program Signal Capture, Log analyze, Dump Network Traffic\n";
    //char purpose2[] = "And Modem(ROue) exploit target scan and Vendor Detect\n\n\n";
    

    if (argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {

        printf("\nSiGloG 1.I Software Dev.Inc. \n");
        printf("Development: ::\\\\\\Hunkar Acar////::\n");
        printf("Github: https://github.com/hunkaracar\n\n");
        //printf("--------------------------------------------------------------------\n");		
		
		char usage[] = " \nUsage: ./siglog [OPTION] ... [Params.] ..\n\n";
		//char try[] = "Try `siglog --help` for more options ";
		printf("%s",usage);
        printf("Options:\n");

        printf("\t--help: Show the help Bar\n");
        printf("\t-h: Show the help Bar\n");
        printf("\t--docut: Detailed help documentation\n");
        printf("\t--dump: Listening and Sniffing network traffic\n");
        //printf("\t-O: Saves as pcap file\n");
        printf("\t-i,--iface: Specifies the interface of the network to listen to (e.g. eth0)\n");
        //printf("\t-l: Keeps logs and saves for analysis\n");
        printf("\t-L: Location detect(Geolocation by IP address)\n");
        printf("\t-RA: Reads and extracts pcap files\n");
        printf("\t-V: Version Information for SiGloG\n");
        printf("\t-E: Indicates the error code in a bruteforce attack on the login page\n");
        printf("\t--host: Specifies the URL in a bruteforce attack on the login page\n");
        printf("\t--http-post: Specifies login form information in case of a brute force attack on the login page(data_form)\n");
        printf("\t--scan=modem: Gathers detailed information about the modem\n");
        printf("\t--sniff-python: More advanced network listening with Python\n\n");
		
		//printf("\n##################################\n");
		//printf("ReadMe ^^:)))\n\n");
        //printf("%s", purpose);
        //printf("%s", purpose2);
        printf("Siglog Software Dev.Inc. has features such as scanning, reconnaissance, detection, analysis and attack.\n");
        
    }
    	 
	 else if (argc < 2 || strcmp(argv[1], "-V") == 0){
		
		if (argc != 2){
			//printf("Usage: %s -V\n",argv[0]);
			printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
			return 1;
			}
		show_version();
		
		}
	
	else if (argc < 2 || strcmp(argv[1], "--docut") == 0) {
		
		if (argc != 2) {
			printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
			return 1;
			
			}
		print_document();
		} 	
	
		
	else if (argc < 3 || strcmp(argv[1], "-RA") == 0) {
		
		if (argc != 3) {
			 printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
			 return 1;
			}
		pcap_read(argv[2]);	
		
		}
	
	else if (argc < 3 || strcmp(argv[1], "--sniff-python") == 0) {
		 
		 if (argc != 3) {
			 printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
			 return 1;
			 }
			 
		sniff_python_dump(argv[2]);	 
	   }
	
    else if (argc < 3 || strcmp(argv[1], "--scan=modem") == 0){
		
		if (argc != 3){
			//printf("Usage: %s --scan=modem\n",argv[0]);
			printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
			return 1;
			
			}
			port_scan(argv[2]);
			redirectHTTP(argv[2]);
			getModemWebSiteVersion(argv[2]);
			checkRobotsTxt(argv[2]);
			Http_title(argv[2]);
		}
		
    		
    else if (argc < 3 || strcmp(argv[1], "-L") == 0){
		
		if (argc != 3){
			//printf("\nUsage: %s -L <target_ip>\n",argv[0]);
			printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
			return 1;
		}
		
		locdet_text_print_info(argv[2],argv[1]);
		printf("\033[1;33mDisplaying location information\033[0m\n");
		printf("\n\033[1;33m----------------------------------------------------------------------\033[0m\n\n\n\n");
		sleep(2);
		locadet(argv[2]);
	}
	
	 
    else if(argc < 4 || strcmp(argv[1], "-i") == 0 && strcmp(argv[3], "--dump") == 0){
		
		if (argc != 4){
			//printf("Usage: %s -i <interface> --dump\n",argv[0]);
			printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
			return 1;
			
		}
		
		InitText_print(argv[2],argv[3]);
		printf("\033[32mNetwork listening results\033[0m\n");
		printf("\033[32m-----------------------------------------------------------------\033[0m\n\n\n");
		sleep(5);
		LiveCapture(argv[2]);
		
		}	
		
	
	// ./siglog --host <target_url> --http-post <data_form> -E <error_str>
	else if (argc < 7 || (strcmp(argv[1], "--host") == 0 && strcmp(argv[3], "--http-post") == 0 && strcmp(argv[5], "-E") == 0)) {
		
		if (argc != 7) {
        printf("\n\033[1m\033[1;31mInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
        return 1;
		}
	attempt_init(argv[2]);
    bruteForce_attack(argv[2], argv[4], argv[6]);
    
	}
		
	else {
		
		printf("\033[1m\033[1;31m\nInvalid arguments or usage. Use --help for more information.\033[0m\033[0m\n\n");
        return 1;
	}
	
    return 0;
}
