#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void attempt_init(const char *target_url) {
	
	time_t now;
    struct tm *local_time;
    char time_str[200];

    now = time(NULL);
    local_time = localtime(&now);

    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);

	printf("SiGloG 1.I (c) Software Dev.Inc 2023 by Hunkar Acar - Use with certain permissions and ethical limits\n");
	printf("One of many modules of open source software and development(SiGloG 1.I)\n\n");
	printf("SiGloG (https://github.com/hunkaracar) Starting at %s\n",time_str);
	printf("[DATA] default wordlist modwordlist.txt using bruteForce Attack, 45 login tries(http-post)\n");
	printf("[DATA] attacking %s\n",target_url);
	sleep(3);
	
}



void bruteForce_attack(const char *target_url, const char *data_form, const char *error_str) {
	
	char command[320];
	
	//command and arguments combining
	snprintf(command, sizeof(command), "python3 loginBruteForce.py \"%s\" \"%s\" \"%s\"", target_url, data_form, error_str);
	int result = system(command);
	
	if (result == 0) {
		//printf("Command Successfuly Working");
	}
	
	else {
		//printf("Command Failed");
	}
	
}
