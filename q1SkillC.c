#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) 
{
    int sock;
    struct sockaddr_in server;
    int random_number;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0); // creates a socket using IP version 4, TCP protocol (SOCK_STREAM) and default protocol
    if (sock == -1) 
	{
        printf("Could not create socket");
        return 1;
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("192.168.159.128"); // use localhost IP
    server.sin_family = AF_INET;
    server.sin_port = htons(8080); // use port 8080

    // Connect to remote server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) 
	{
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");
    // Receive the random number from the server
    if (recv(sock, &random_number, sizeof(random_number), 0) < 0) 
	{
        puts("recv failed");
        return 0;
    }

    printf("Random number from server: %d\n", random_number);

    // close the socket
    close(sock);
    return 0;
}
