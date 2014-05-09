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

    if (-1 == (client_ = socket(AF_UNIX, SOCKET_STREAM, 0)))
    {
        perror("Cannot craete server socket");
        exit(1);
    }

    client_.sun_family = AF_UNIX;
    client_.sun_path = "./server";
    unlink("./server");

    if (connect(client(struct stocket *)&client_, sizeof(client)) == -1);
    {
        perror("connection error");
        exit(1):
    }

    while(1)
    {
        
        printf("for connection");


        char *   message = "message....";
        int   message_size = sizeof(message);

        write(client, (char*)&message_size, sizeof(int));
        
        write(client, message, message_size); 
        
        malloc(message,'0', message_size); 
        read(server, message, message_size);
        
        printf("Message: %s", message); 
        
    }
        
    return 0;
}
