#include <sys/socket.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror("\n Error : Could not create socket \n");
    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1113); 

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
        perror("\n inet_pton error occured\n");

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
       perror("\n Error : Connect Failed");

    int32_t flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    struct pollfd pfds[2];
    
    pfds[0].fd = sockfd;
    pfds[0].events = POLLIN;

    pfds[1].fd = sockfd;
    pfds[1].events = POLLERR | POLLHUP;
    while(3) {
        poll(pfds, 2, -1);
        printf("poll woke up\n");
        printf("0 %d\n", pfds[0].revents);
        printf("0 %d\n", pfds[1].revents);
        if (pfds[0].revents & POLLIN) {
            printf("in POLLIN");
            char buf[1024];
            printf("read set");
            fflush(stdout);
            int32_t i = read(sockfd, buf, 1024);
            printf("read %d bytes\n", i);

            if (!i) {
                printf("socket dropped");
                return 0;
             }
        } else { 
            printf("mpt POLLIN"); 
        }

        if (pfds[1].revents & POLLERR) {
            printf("socket error\n");
        }
    }
/*    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        printf("received %d bytes\n", n);
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    } 

    if(n < 0)
    {
        printf("\n Read error \n");
    } 
*/

    return 0;
}
