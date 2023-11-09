#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <net/if.h>

/**
 *  -M	--mgroup	specify multicast group
 *  -P	--port		specify receive port
 *  -p	--player	specify decoder
 *  -H	--help		display help
 *  implement by getopt_long
 */

int main(int argc, char *argv[])
{
    int fd;
    int ret;
    int opt;
    int port = 8888;
    char *ip;






    exit(0);
}