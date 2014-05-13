#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/un.h>
#include <stdlib.h>

int main()
{

    int client, server;
    int client_size;
    client_size = sizeof(client);

    struct sockaddr_in server_;
    struct sockaddr_in client_;

    if (-1 == (server = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("Cannot craete server socket");
        exit(1);
    }

    server_.sin_family = AF_INET;
    server_.sin_addr.s_addr = htonl(INADDR_ANY);
    server_.sin_port = htons(4000);

    if (bind(server, (struct stockaddr *)&server_, sizeof(server_)) == -1)
    {
        perror("binding error");
        exit(5);
    }

    if (listen(server, 5) == -1)
    {
        perror("listening error");
        exit(1);
    }

    while(1)
    {
        
        printf("Waiting for connection\n");

        client = accept(server, (struct sockaddr *)&client_, &client_size);

        if (client == -1)
        {
            perror("error with client connecting...\n");
            exit(1);
        }

        printf("client connected\n"); 

        int   message_size;
        char *   message;

        read(client, (char*)&message_size, sizeof(int));
        
        printf("message size: %d\n", message_size); 
        
        message = (char *)malloc(message_size); 

        read(client, message, message_size);
        
        printf("Message: %s\n", message); 
        
        free(message);

    }
        
    return 0;
}
