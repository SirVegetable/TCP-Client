#include "tcp_client.hpp"
#include <iostream> 
#include <string> 
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>


TcpClient::TcpClient()
{

    socket_handler = 0;
    ptr = nullptr; 
    std::memset(&hints,0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM; 
    serverInfo = nullptr; 
};

TcpClient::~TcpClient()
{
    freeaddrinfo(serverInfo); 
    disconnect(); 
};
void* TcpClient::get_in_addr(struct sockaddr *sa) 
{
    if (sa->sa_family == AF_INET) 
    {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr); 
}

bool TcpClient::connectClient(const std::string& host, const std::string& portNumber)
{

    int status = getaddrinfo(host.c_str(),portNumber.c_str(),&hints, &serverInfo);
    if(status != 0){
        std::cerr << "getaddrinfo failed: " << gai_strerror(status) << std::endl;
        return false; 
    }
    // Create the socket availible addresses
    for(ptr = serverInfo; ptr != nullptr; ptr = ptr->ai_next)
    {
        if((socket_handler = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol))== -1)
        {
            perror("client: socket");
            continue; 
        }
        break; 
    }
    // failed to get create a socket from the availaible addresses
    if(ptr == nullptr)
    {    
        return false; 
    }
    // need to translate the address of the server to binary
    int IP = inet_pton(ptr->ai_family,host.c_str(), get_in_addr((struct sockaddr *)ptr->ai_addr));
    if(IP == -1)
    {
        return false; 
    }
    
    if(connect(socket_handler,ptr->ai_addr,ptr->ai_addrlen) < 0)
    {
        return false; 
    }
    return true; 



}
void TcpClient::send(std::string& msg)
{

}
std::string TcpClient::recieve()
{

    return "";
}
void TcpClient::disconnect()
{
    close(socket_handler);
    socket_handler = 0; 
}
        

