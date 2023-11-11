/*
This main function is used to ask the user which type of IP address they want to print.
It includes the custom ipv4.h and ipv6.h header files that define the functions for handling IPv4 and IPv6 addresses.
The user can enter either 4 or 6 as an input to choose the desired address format. 
The function then calls the appropriate print function from the header files and displays the IP address on the screen.
*/

#include <stdio.h>
#include <string.h>
#include "ipv4.h"
#include "ipv6.h"
#include "docs/version.h"
#include "docs/error.h"
#include "docs/help.h"


/*
This paragraph explains the main function of our program.
It also demonstrates how to use the custom version and help options that we have implemented.
You can access these options by typing -vh or --help in the command line.
These options will show you the current version of the program and the available commands that you can use.
*/


int main(int argc(), char *argv[])
{
        for(int i = 1;i < argc; ++i){
                if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0){
                        show_version();
                        return 0;
                }
                else if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0){
                        show_help();
                        return 0;
                }
                else{
                       show_error();
                       return 0;
                }
        }

        int ip;

        printf("\033[1;35m\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\033[1;32m\t\t  IP ADDRESS GENERATOR \n");
        printf("\033[1;35m\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

        printf("\n\033[1;33m [+]\033[1;32m 1.IPV4 \n");
        printf("\033[1;33m [+]\033[1;32m 2.IPV6 \n");

        printf("\n\033[1;33m [+]\033[1;32m Which IP You want (1 or 2): ");
        scanf("%d",&ip);

        switch (ip){
        
                case 1:
                        ipv4_generator();
                        break;
                case 2:
                        ipv6_generator();
                        break;
                default:
                        printf("\n\033[1;33m [!]\033[1;31m Invalid number of value. Exiting...\n");
        }
       return 0;

}
