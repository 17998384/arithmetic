//
//  test_socket.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/10/22.
//  Copyright © 2020 alex. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#define PORT 8001
#define SERVER_IP "172.16.13.204"


/*
    准备socket
 */
int prepare_socket()
{
    int socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        printf("creata socket fail!");
        _exit(-1);
    }
    return socket_fd;
}

/*
    准备链接
 */
void prepare_connect(int socket_fd)
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    addr.sin_family = PF_INET;
    addr.sin_port = htons(PORT);
    int conn_result = connect(socket_fd, &addr, sizeof(addr));
    if (conn_result < 0)
    {
        printf("connect fail!");
        _exit(-1);
    }
}

/*
    发送
 */
void my_send(int socket_fd)
{
    char buffer[1024];
    printf("please enter input send to server text:\n");
    gets(buffer);
    strcat(buffer, "end");
    send(socket_fd, buffer, strlen(buffer), 0);
}

/*
    接收
 */
void my_recv(int socket_fd)
{
    char buffer[1024];
    memset(buffer, 0, 1024);
    recv(socket_fd, buffer, 1024, 0);
    printf("from server : %s\n",buffer);
}

/// c语言socket
int main_test_socket(void)
{
    //准备socket
    int socket_fd = prepare_socket();
    //链接
    prepare_connect(socket_fd);
    while(1)
    {
        my_send(socket_fd);
        my_recv(socket_fd);
    }
    shutdown(socket_fd, 2);
    return 0;
}
