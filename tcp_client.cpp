#include "tcp_client.hpp"

#include <string> 
#include <arpa/inet.h>
#include <netdb.h>


TcpClient::TcpClient(const std::string& host, const std::string& portNumber)
{

    socket_handler = 0;
    std::memset(&hints,0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    int status = getaddrinfo(host.c_str(), portNumber.c_str(), &hints, &serverInfo);
    if(status != 0)
    {
        freeaddrinfo(serverInfo);
        throw std::runtime_error("get addrinfo failed: " + std::string(gai_strerror(status)));
    }
};

TcpClient::~TcpClient()
{
    freeaddrinfo(serverInfo); 
    disconnect(); 
};

bool TcpClient::connect()
{
    // Create the socket for the first availible address
    for(ptr = serverInfo; ptr != nullptr; ptr = ptr->ai_next)
    {
        if((socket_handler = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol))== -1)
        {
            perror("client: socket");
            continue; 
        }
        break; 
    }

    if(ptr == nullptr)
    {
        return false; 
    }

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

}
        

