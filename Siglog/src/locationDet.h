#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>




void locdet_text_print_info(const u_char *target_ip, const char *arguments ){
	
	
	printf("\033[1;37m\n\nDeveloper: Hunkar Acar => (Cyber SecurITy Guard)\033[0m");
	char fund[] = "\n_________________________________________________________";
	printf("\033[1;37m%s\033[0m\n",fund);
	printf("\033[1;37m\n\n| SiGloG 1.1 Software Inc.\033[0m\n");
	printf("\033[1;37m|\033[0m\n");
	printf("\033[1;37m|-SiGloG ####\033[0m\n");
	char use[] = "|-Location etc. obtaining and detecting information";	
	printf("\033[1;37m%s\033[0m\n",use);
	printf("\033[1;37m|-State: Location Detected\033[0m\n");
	printf("\033[1;37m|-Target IP: %s\033[0m\n",target_ip);
	printf("\033[1;37m|-Running Parameter: %s\033[0m\n",arguments);
	printf("\033[1;37m|-LOcation,host,time information:\033[0m\n");
	printf("\033[1;37m\t|-IP \033[0m\n");
	printf("\033[1;37m\t|-Hostname \033[0m\n");
	printf("\033[1;37m\t|-city\033[0m\n");
	printf("\033[1;37m\t|-Country\033[0m\n");
	printf("\033[1;37m\t|-Timezone\033[0m\n");
	printf("\033[1;37m\t|-Organization\033[0m\n");
	printf("\033[1;37m|\033[0m\n");
	printf("\033[1;37m| SiGloG 1.1 Software Inc.\033[0m\n\n\n\n\n");
	//char fund2[] = "\033[1;37m--------------------------------------------------------\033[0m\n\n\n";
	//printf("%s",fund2);
	sleep(4);
	
	}



size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp){
      
      //API yanıtını al
      printf("\033[1;32m%.*s \033[0m\n\n\n", (int)(size * nmemb), (char *)contents);
      return size * nmemb;

}



void locadet(char *target_ip){
	
	
	//Curl kütüphanesi için gerekli ön hazırlıklar
	//*curl işaretçisi oluşturuluyor...
	CURL *curl;
	CURLcode res;
	
	//Curl kütüphanesi başlatılıyor.
	curl_global_init(CURL_GLOBAL_DEFAULT);
	
	//Bu kod ile curl işaretçisi başlatılıyor.
	curl = curl_easy_init();
	
	
	
	if (curl) {
		
		// API isteği için URL'yi oluşturun, hedef IP'yi ekleyin
		char url[200]; // URL'nin boyutu ihtiyaca göre ayarlanabilir
		sprintf(url, "https://ipinfo.io/%s", target_ip);
		curl_easy_setopt(curl, CURLOPT_URL, url); //URL kütüphanesine ayar olarak veriliyor. Bu, CURL'un hangi URL'ye istek yapacağını belirtir.
		
		// Veriyi terminalde yazdırmak için callback fonksiyonunu belirle
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		
		// API isteğini gerçekleştir
		res = curl_easy_perform(curl);
		
		
		if (res != CURLE_OK) {
			fprintf(stderr, "\ncurl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
		
		//Curl işaretçisi temizleniyor(Bu kullanılan belleği serbest bırakır)
		curl_easy_cleanup(curl);
	}

	//Curl kütüphanesi kapatılıyor, Bu curl kütüphanesini temizler.
	curl_global_cleanup();
}
