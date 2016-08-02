#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <arpa/inet.h>

int
main(){
 int sock;
 struct sockaddr_in addr;

 sock = socket(AF_INET, SOCK_DGRAM, 0);

 addr.sin_family = AF_INET;
 addr.sin_port = htons(12345);
 addr.sin_addr.s_addr = inet_addr("192.168.0.8");

 sendto(sock, "HELLO", 5, 0, (struct sockaddr *)&addr, sizeof(addr));

 close(sock);

 return 0;
}
