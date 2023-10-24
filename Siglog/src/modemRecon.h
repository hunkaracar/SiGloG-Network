#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_TITLE_LENGTH 1024
#define MAX_BUF_SIZE 1024
#define MAX_PACKET_SIZE 65535
#define TIMEOUT 22 // Connection timeout (in seconds)

void port_scan(const char *target_ip_address) {
	
    printf("Starting SiGloG 1.I (Software Dev. Inc.) at today (Against-Device)\n");
    sleep(1);
    printf("Scanning %s [20 ports](most used Modem ports)\n",target_ip_address);
    printf("Trying to discover ports\n");
    printf("TRying...\n");
    printf("TRying...\n");
    printf("Trying to complete scans\n");
    sleep(2);
    printf("Scan completed\n");
    printf("Scanning completed, final determinations made\n");
    printf("Discovered...\n");
    printf("Network packets are processed\n");
    printf("Receiving network packets\n");
    printf("Discovery (1) Host Up [%s]\n\n", target_ip_address);
    sleep(4);
    
    int ports[] = {
        21, 22, 23, 25, 53, 67, 68, 80,
        110, 139, 143, 443, 445, 631, 2000, 3389, 5000 , 8000, 8080, 9876
    };

    const char *protocolPorts[] = {
        "Ftp", "Ssh", "Telnet", "SMTP", "DNS", "DHCP", "DHCP",
        "Http", "POP3", "Netbios", "IMAP", "Https", "SMB", "IPP", "Bandwith-Test(?)", "RDP", "Universal Plug and Play (UPNP)", "Ipcam(?)" , "Http-Proxy", "sd(?)"
    };

    // Create socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation Error!!");
        exit(EXIT_FAILURE);
    }

    // Set IP address and port number
    struct sockaddr_in targetAddr;
    targetAddr.sin_family = AF_INET;
    targetAddr.sin_addr.s_addr = inet_addr(target_ip_address);

    //printf("Discovery (1) Host Up [%s]\n\n", target_ip_address);
    sleep(2);
    printf("___________________________________________________\n");
	printf("      PORT        STATE       SERVICE      VERSION \n");
	//printf("|------------|------------|-------------|---------|\n");

    int i;
    for (i = 0; i < sizeof(ports) / sizeof(*ports); i++) {
        targetAddr.sin_port = htons(ports[i]);
        // Wait 1 second before each connection attempt
        sleep(2);

        if (connect(sockfd, (struct sockaddr*)&targetAddr, sizeof(targetAddr)) < 0) {
            if (errno == EINPROGRESS) {
                // Connection in progress
                struct timeval timeout;
                timeout.tv_sec = TIMEOUT;
                timeout.tv_usec = 0;
                fd_set fdSet;
                FD_ZERO(&fdSet);
                FD_SET(sockfd, &fdSet);
                int selectResult = select(sockfd + 1, NULL, &fdSet, NULL, &timeout);
                if (selectResult == 1) {
                    int socketError;
                    socklen_t socketErrorSize = sizeof(socketError);
                    getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &socketError, &socketErrorSize);
                
                    if (socketError == 0) {
                       
						printf("|%4d/tcp   %8s   %10s    %s   \n", ports[i], "open", protocolPorts[i],"soon..");

                    } 
                    
                    else {
                        printf("Port %d [%s] error: %s\n", ports[i], protocolPorts[i], strerror(socketError));
                    }
                } 
                
                else if (selectResult == 0) {
                    //printf("Port %d [%s] Connection timed out \n", ports[i], protocolPorts[i]);
                } else {
                    perror("Select error");
                    exit(EXIT_FAILURE);
                }
            } 
            
            else if (errno == ECONNREFUSED) {
                //printf("Discovery Port %d [%s] closed\n", ports[i], protocolPorts[i]);
            } 
            
            else if (errno == EHOSTUNREACH) {
                printf("|  %4d/tcp    %8s    %10s   %s  \n", ports[i], "filtered" ,protocolPorts[i],"  unknow");
            } 
            
            else {
                //printf("Port %d [%s] error: %s\n", ports[i], protocolPorts[i], strerror(errno));
            }
        } 

		/*
        printf("_______________________________________________\n");
		printf("| Port       | State      | Service     | Version |\n");
		printf("|------------|------------|-------------|---------|\n");
		* */
		
        else {
            
			printf("| %4d/tcp    %8s    %10s      %s   \n", ports[i], "open", protocolPorts[i],"soon..");
 
            close(sockfd); // Close the connection
        }

        // Re-create connection socket
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket creation error");
            exit(EXIT_FAILURE);
        }

        // Set socket timeout
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
            perror("Setsockopt error");
            exit(EXIT_FAILURE);
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
            perror("Setsockopt error");
            exit(EXIT_FAILURE);
        }
    }

    // Close the socket
    close(sockfd);
    printf("\n|\n");
    printf("|\n");
    printf("|\n");
    printf("--Port Scan Completed--\n\n");
    printf("|\n");
    printf("|\n");
    printf("|\n");
    sleep(2);
}


void redirectHTTP(const char* target_ip) {
	printf("|\n",
	       "|\n",
	       "|\n",
	       "|\n",
	       "|\n",
	       "|\n",
	       "|\n");
	printf("|-WSS(Web Site Side Script Scanning) loading...\n");   
	printf("|-WSS(Web Site Side Script Scanning) load..\n");
	printf("|-WSS scanning\n");
	printf("|-WSS scan completed\n",
	       "|\n",
	       "|\n");
	printf("|-Http-Service (Port 80) scan\n");     
	printf("|-Http-Url redirect \n"); sleep(2);
	printf("|\n");
	printf("|\n");
    printf("|-Redirect MOdem Network Device Http Url\n");
    printf("\t|-HTTP URL: http://%s\n",target_ip);
    printf("|\n");
    printf("|\n");
    sleep(2);
}

void getModemWebSiteVersion(const char* target_ip) {
		
		printf("|\n");
        printf("|-Modem Network DEvice HTTP on 80 port information showing\n");
        //printf("-------------------------------------------------------------------------\n\n");
        sleep(1);
        
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    if (inet_pton(AF_INET, target_ip, &(server.sin_addr)) <= 0) {
        perror("inet_pton");
        return;
    }

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("\nConnection Error.\n");
        printf("!!The system may not survive!!!\n");
        return;
    }

    char request[MAX_BUF_SIZE];
    sprintf(request, "GET / HTTP/1.0\r\n\r\n");
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        return;
    }

    char response[MAX_BUF_SIZE];
    if (recv(sock, response, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return;
    }

    char* serverHeader = strstr(response, "Server:");
    if (serverHeader != NULL) {
        char serverInfo[MAX_BUF_SIZE];
        sscanf(serverHeader, "Server: %[^\r\n]", serverInfo);
        printf("\t|-HTTP Version Server Info: %s\n", serverInfo);
        //printf("\t|\n");
        //redirectHTTP(target_ip);
    } else {
        printf("\nServer Info not found.\n\n");
    }

    close(sock);
}


void checkRobotsTxt(const char* target_ip){
	
	CURL *curl;
	CURLcode res;
	
	char url2[256];
	
	snprintf(url2,sizeof(url2),"http://%s/robots.txt",target_ip);
	
	curl = curl_easy_init(); //curl baslat
	
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url2);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Sadece başlığı al, içeriği alma
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, TIMEOUT); // Bağlantı zaman aşımı ayarı
        
        res = curl_easy_perform(curl);
        
        curl_easy_cleanup(curl);
        
        if (res == CURLE_OK) {
			long response_code;
			curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE,&response_code);
			if (response_code == 200) {
				printf("\t|-Robots.txt detect found\n");
			}
			else {
				printf("\t|-RObots.txt Not detect\n");
			}
		}
		else {
			fprintf(stderr, "CURL Error: %s\n\n", curl_easy_strerror(res));
			printf("!!The system may not survive!!!");
		}

	}
	
}



// Callback işlevi, HTTP yanıtını alır
size_t write_callback_2(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    char *title = (char *)userp;
    
    // HTTP yanıtını başlık etiketi içinde arayın
    char *title_start = strstr(contents, "<title>");
    char *title_end = strstr(contents, "</title>");
    
    if (title_start && title_end) {
        title_start += strlen("<title>");
        size_t title_length = title_end - title_start;
        
        // Başlık etiketini temizleyin
        if (title_length < MAX_TITLE_LENGTH) {
            strncpy(title, title_start, title_length);
            title[title_length] = '\0';
        }
    }
    
    return total_size;
}


void Http_title(const char *target_ip) {
	
    CURL *curl;
    CURLcode res;
    
    char url[300];
    
    snprintf(url, sizeof(url), "http://%s", target_ip);

    char title[MAX_TITLE_LENGTH] = "";
    
    curl = curl_easy_init();
    if (curl) {
        // CURL ayarlarını yapılandır
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Yönlendirmeleri izle
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_2);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, title);
        
        // HTTP isteği gönder
        res = curl_easy_perform(curl);
        
        // Başlığı yazdır
        if (res == CURLE_OK) {
            printf("\t|-Web site Header: %s\n", title);
        }
         
        else {
            fprintf(stderr, "CURL Error: %s\n", curl_easy_strerror(res));
        }
        
        
        // CURL'ü temizle
        curl_easy_cleanup(curl);
    }
    
    printf("\n\n\nPort scan completed.\n");
    printf("WSS(Web Site Side Script Scanning) completed.\n");
    printf("All scans completed.\n");
    printf("SiGloG Software Dev. Inc.\n");
    
}
