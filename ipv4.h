/*
This is a custom header file called ipv4.h that can generate random IPv4 addresses.
It contains the necessary functions and data structures to create and manipulate IPv4 addresses.
This header file can be included in the main.c file to use its features.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ipv4_generator()
{
        printf("\033[1;35m\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\033[1;32m\t\t  IPV4 ADDRESS GENERATOR \n");
        printf("\033[1;35m\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");


// Seed the random number generator with the current time
        srand((unsigned int)time(NULL));

// Function to generate a random IPv4 address
        int num_addresses;
        printf("\n\033[1;33m [+]\033[1;32m Enter the number of IPv6 addresses to generate : ");
        scanf("%d",&num_addresses);
        printf("\n");

        if (num_addresses <= 0) {
                printf("\n\033[1;33m [!]\033[1;31m Invalid number of addresses. Exiting...\n");
                return 1;
        }

        for(int i = 1;i <= num_addresses;i++){
                int ip[4];
                for(int j = 0;j < 4;j++){

                        ip[j] = rand() % 256;
                }
                printf("\033[1;33m %d.)\033[1;32m %d:%d:%d:%d\n",i,ip[0],ip[1],ip[2],ip[3]);
        }
        return 0;

}