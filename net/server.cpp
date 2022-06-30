#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    //创建套接字
    int service_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口

    // 如果未指定，服务端主动关闭连接的话，会出现TIME_WAIT
    // Address already in use

    int on = 1;
    //setsockopt(service_socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
    if (setsockopt(service_socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int)) < 0){
            perror("setsockopt(SO_REUSEADDR) failed");
            exit(0);
    }
    

    int ret = bind(service_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret < 0){
        perror("");
        exit(0);
    }

    //进入监听状态，等待用户发起请求
    listen(service_socket, 20);

    //接收客户端请求
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_socket = accept(service_socket, (struct sockaddr*)&client_addr, &client_addr_size);

    //向客户端发送数据
    char str[] = "Hello World!";
    write(client_socket, str, sizeof(str));
   
    //关闭套接字
    close(client_socket);
    close(service_socket);

    return 0;
}
