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

int main
{

    int client, server;
    int client_size;
    client_size = sizeof(client);

    struct socket_un server_, client_;

    if (-1 == (server = socket(AF_UNIX, SOCKET_STREAM, 0)))
    {
        perror("Cannot craete server socket");
        exit(1);
    }

    server_.sun_family = AF_UNIX;
    server_.sun_path = "./server";
    unlink("./server");

    if (bind(server (struct stocket *)&server_, sizeof(server)) == -1);
    {
        perror("binding error");
        exit(1):
    }

    if (listen(socket, 5) == 1)
    {
        perror("listening error");
        exit(1);
    }

    while(1)
    {
        
        printf("Waiting for connection");

        client = accept(server, (struct sockaddr *)&client, &client_size);

        if (client == -1)
        {
            perror("error with client connecting...");
            exit(1);
        }

        printf("client connected"); 

        int   message_size;
        char *   message;

        read(client, (char*)&message_size, 4);
        
        printf("message size: %d\n", message_size); 
        
        malloc(message,'0', message_size); 
        read(client, message, message_size);
        
        printf("Message: %s", message); 
        
        free(message);

    }
        
    return 0;
}

       

        

    

       




