/*
The ipv6.h header file is a custom-made library that provides a function to generate random IPv6 addresses.
It can be used in conjunction with the main.c file, which calls the function and prints the output.
The ipv6.h header file is useful for testing and debugging purposes,
as it allows the creation of valid IPv6 addresses without relying on external sources.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random hexadecimal digit
char get_random_hex_digit() {
    const char hex_digits[] = "0123456789abcdef";
    return hex_digits[rand() % 16];
}

// Function to generate a random IPv6 address
void generate_random_ipv6(char ipv6_str[]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 4; ++j) {
            ipv6_str[i * 5 + j] = get_random_hex_digit();
        }
        if (i < 7) {
            ipv6_str[i * 5 + 4] = ':';
        } else {
            ipv6_str[i * 5 + 4] = '\0'; // Null-terminate the string
        }
    }
}

int ipv6_generator() {

    printf("\033[1;35m\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\033[1;32m\t\t  IPV6 ADDRESS GENERATOR \n");
    printf("\033[1;35m\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");


     // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    int num_addresses;
    printf("\n\033[1;33m [+]\033[1;32m Enter the number of IPv6 addresses to generate: ");
    scanf("%d", &num_addresses);
    printf("\n");

    if (num_addresses <= 0) {
        printf("\n\033[1;33m [!]\033[1;31m Invalid number of addresses. Exiting...\n");
        return 1;
    }

    for (int count = 0; count < num_addresses; ++count) {
        char ipv6_str[40];
        generate_random_ipv6(ipv6_str);
        printf("\033[1;33m%d.)\033[1;32m %s\n",count + 1, ipv6_str);
    }

    return 0;
}
