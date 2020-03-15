#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    char message[100];

    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8096);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);

    connect(fd, (struct sockaddr *)&serv, sizeof(serv));

    while (1)
    {
        printf("Enter a message: ");
        fgets(message, 100, stdin);
        send(fd, message, strlen(message), 0);
    }
}