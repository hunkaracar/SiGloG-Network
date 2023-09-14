# SiGloG-Network

# SiGloG

SiGloG is a network reconnaissance and penetration testing tool developed by [Software Dev.Inc.](https://github.com/hunkaracar).

## Features

SiGloG offers the following features:

- **Network Traffic Capture:** You can listen to and capture network traffic with the `--dump` option.

- **Specify Network Interface:** You can specify the network interface to listen on using `-i` or `--iface` (e.g., `eth0`).
  
- **Location Detection:** With the `-L` option, you can perform geolocation based on IP address.
  
- **Pcap File Reading:** Use the `-RA` option to read pcap files and extract their contents.
  
- **Version Information:** Get SiGloG version information with the `-V` option.
  
- **Display Error Codes:** Use the `-E` option to determine error codes in password brute force attacks on login pages.
  
- **Specify Target URL:** With `--host`, you can specify the target URL for password brute force attacks.
  
- **HTTP POST Data Specification:** Use `--http-post` to specify login form information for password brute force attacks (`data_form`).
  
- **Modem Information Gathering:** With `--scan=modem`, you can gather detailed information about a modem.
  
- **Advanced Network Listening:** The `--sniff-python` option enables more advanced network listening using Python.

SiGloG offers a range of features for scanning, reconnaissance, detection, analysis, and attacks.

## Usage

To use SiGloG, you can utilize the provided options and commands. For more details, refer to the documentation using the `--help` or `-h` option. Additionally, visit the [GitHub](https://github.com/hunkaracar) page for more information and updates.

## License

This software is open-source and is subject to the license terms specified under [LICENSE](LICENSE).


## Installation

To install SiGloG, follow these steps:

1. Download the SiGloG source code from the [GitHub repository](https://github.com/hunkaracar).

2. Navigate to the directory where you downloaded the source code using the terminal:

3. Compile SiGloG using the following command:

cd [Siglog]
gcc -o siglog siglog.c -lpcap -lcurl -g

./siglog -h or siglog --help

This command will display the SiGloG help menu with usage instructions.

You are now ready to use SiGloG!
