#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int server;
    int client_size;
    /* client_size = sizeof(client); */

    struct sockaddr_in server_;

    if (-1 == (server = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("Cannot craete server socket");
        exit(1);
    }

    server_.sin_family = AF_INET;
    server_.sin_addr.s_addr = inet_addr("16.26.45.160");
    server_.sin_port = htons(4000);


    if (connect(server,(struct sockaddr *)&server_, sizeof(server_)) == -1)
    {
        perror("connection error\n");
        exit(1);
    }
        
        printf("for connection\n");

        char *   message = "message.!!";
        int   message_size =strlen(message);

        printf("Sending message size: %d\n",message_size); 

        write(server, (char*)&message_size, sizeof(int));
        
        write(server, message, message_size); 
        
        printf("Sending message: %s", message); 
        close(server);
        
        
    return 0;
}
