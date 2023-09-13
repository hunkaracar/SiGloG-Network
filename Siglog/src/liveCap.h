#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <ctype.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>


void InitText_print(const char *interface, const char *arguments){
	
	
	printf("\033[1;37m\n\nDeveloper: Hunkar Acar => (Cyber SecurITy Guard)\033[0m");
	char fund[] = "\n_________________________________________________________";
	printf("\033[1;37m%s\033[0m\n",fund);
	printf("\033[1;37m\n\n| SiGloG 1.1 Software Inc.\033[0m\n");
	printf("\033[1;37m|\033[0m\n");
	printf("\033[1;37m|-SiGloG ####\033[0m\n");
	char use[] = "|-The network is listening on the specified network interface";	
	printf("\033[1;37m%s\033[0m\n",use);
	printf("\033[1;37m|-State: Network Listening\033[0m\n");
	printf("\033[1;37m|-Interface: %s\033[0m\n",interface);
	printf("\033[1;37m|-Running Parameter: %s\033[0m\n",arguments);
	printf("\033[1;37m|-Listening and getting information from the network:\033[0m\n");
	printf("\033[1;37m\t|-Ether / IP / \033[0m\n");
	printf("\033[1;37m\t|-Ether / IP / TCP / Dns Qry \033[0m\n");
	printf("\033[1;37m\t|-HEX Dump\033[0m\n");
	printf("\033[1;37m\t|-Source IP\033[0m\n");
	printf("\033[1;37m\t|-Destination IP\033[0m\n");
	//printf("\033[1;37m\t|-Organization\033[0m\n");
	printf("\033[1;37m|\033[0m\n");
	printf("\033[1;37m| SiGloG 1.1 Software Inc.\033[0m\n\n\n\n\n");
	//char fund2[] = "\033[1;37m--------------------------------------------------------\033[0m\n\n\n";
	//printf("%s",fund2);
	sleep(4);
	
	}
	

//IP adresini yazdıran yardımcı fonksiyon
void print_ip_address(const u_char *ip_address) {
	
	printf("\033[1;37m%d.%d.%d.%d\033[0m", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
}



void print_packet_info2(const u_char *packet, struct pcap_pkthdr packet_header) {
	
	struct ether_header *eth_header; //Bu işaretçi, Ethernet başlığı bilgilerini işaret edecek.
	eth_header = (struct ether_header *) packet; //Bellek bölgesindeki veriyi, Ethernet başlığı yapısına (struct ether_header) dönüştürerek eth_header işaretçisine atıyor. Bu sayede Ethernet başlığının içeriğine erişim sağlanabilir hale geliyor.
	
	/*
	 Ethernet başlığının ether_type alanı, taşıdığı verinin türünü belirtir. ETHERTYPE_IP sabiti, IP paketi taşıdığını ifade eder.
	 Bu koşulla, paketin IP paketi olduğu kontrol edilir.
	 */
	if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
		
		const u_char *ip_header; //BU işaretçi IP başlığının içeriğini işaret edecek.
		ip_header = packet + sizeof(struct ether_header); //Ethernet başlığının boyutu kadar (yani sizeof(struct ether_header)) artırılır. Bu sayede IP başlığının başlangıcına ulaşılır.
		
		u_char protocol = *(ip_header + 9);
		
		printf("\033[1;33mEther / IP / \033[0m");
		
		//Kaynak ve hedef IP adreslerini yazdır
		printf("\n|\n");
		printf("|\n");
		printf("\033[1;37m|-Src Ip => \033[0m"); // 12 byte offset (src IP)
		print_ip_address(ip_header + 12);
		printf("\033[1;37m\n|-Dst IP => \033[0m"); // 16 byte offset (dst IP)
		print_ip_address(ip_header + 16);
		printf("\n|\n");
		printf("|\n");
		
		printf(" / ");

        if (protocol == IPPROTO_UDP) {
			
             printf("\n\n\033[1m\033[0;34mUDP\033[0m\033[0m\n");
			 struct udphdr *udp_header = (struct udphdr *)(ip_header + sizeof(struct ip));
			 printf("\033[1;37m|-Src Port => %d\033[0m\n", ntohs(udp_header->source));// Ağ baytlarını(ntohs) ana makine baytlarına dönüştür
			 printf("\033[1;37m|-Dst Port => %d\033[0m\n\n", ntohs(udp_header->dest));
			// Ek UDP başlık bilgilerini burada analiz edebilirsiniz.
			
        } else if (protocol == IPPROTO_TCP) {
			
            printf("\n\n\033[1m\033[0;31mTCP\033[0m\033[0m\n");
			struct tcphdr *tcp_header = (struct tcphdr *)(ip_header + sizeof(struct ip));
			printf("\033[1;37m|-Src Port => %d\033[0m\n", ntohs(tcp_header->source)); //ntohs işlevi, ağ baytlarında saklanan bir 16-bit değeri alır ve bu değeri ana makinedeki doğru sıraya (endianness) dönüştürür.
			printf("\033[1;37m|-Dst Port => %d\033[0m\n\n", ntohs(tcp_header->dest));
			// Ek TCP başlık bilgilerini burada analiz edebilirsiniz.
        }
        
        printf("\033[0m\n");
	}
	
	
}


void print_hex(const u_char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("\033[1;32m%02X\033[0m", data[i]);
    }
    printf("\n");
}



/*
 Fonksiyonu, IP trafiği içeren paketlerin detaylarını analiz eder.
 UDP veya TCP protokollerini tanır ve UDP paketleri için DNS sorgularını ekrana yazdırır.
*/
void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {
    struct ether_header *eth_header;
    eth_header = (struct ether_header *) packet;

    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        const u_char *ip_header;
        ip_header = packet + sizeof(struct ether_header);

        u_char protocol = *(ip_header + 9);

        if (protocol == IPPROTO_UDP) {
            const u_char *udp_data = ip_header + 20; // IP başlığını geç
            int dns_data_length = ntohs(*((uint16_t *)(udp_data + 4)));
            printf("\033[1m\033[1;31mEther / IP / UDP / DNS Qry: \033[0m\033[0m");
            for (int i = 0; i < dns_data_length; i++) {
                if (isprint(udp_data[12 + i])) {
                    printf("\033[1;37m%c\033[0m", udp_data[12 + i]);
                } else {
                    printf(".");
                }
            }
            printf("\"\n");
        } else if (protocol == IPPROTO_TCP) {
            printf("\033[1m\nEther / IP / TCP\033[0m\n\n");
        }
        printf("\033[1mHex Dump:\n\033[0m");
        print_hex(packet, packet_header.caplen);
        printf("\n");
        sleep(2);
    }
}



void my_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    print_packet_info(packet, *header);
    print_packet_info2(packet, *header);
}


/*
 Bu Fonksiyonu, belirli bir ağ arayüzünden canlı ağ trafiğini yakalamak için kullanılır. pcap_open_live işlevi ile ağ arayüzü açılır ve yakalama işlemi başlatılır.
 Daha sonra, pcap_next işlevi ile yakalanan paketlerin detayları elde edilir ve my_packet_handler fonksiyonu ile analiz edilir. Bu işlem sürekli olarak devam eder.
*/
void LiveCapture(const char *interface) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr packet_header;

    handle = pcap_open_live(
        interface,
        BUFSIZ,
        1,  // Sadece 1 paket al
        0,  // Sürekli dinle
        error_buffer
    );


    if (handle == NULL) {
        printf("Error opening device %s: %s\n", interface, error_buffer);
        return;
    }
    

    while (1==1) {
        const u_char *packet = pcap_next(handle, &packet_header);
        if (packet != NULL) {
            my_packet_handler(NULL, &packet_header, packet);
        }
    }

    pcap_close(handle);
}
