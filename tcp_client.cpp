#include "tcp_client.hpp"

#include <string> 
#include <arpa/inet.h>
#include <netdb.h>


TcpClient::TcpClient(const std::string& host, const std::string& portNumber)
{

    socket_handler = 0;
    std::memset(&hints,0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(host.c_str(), portNumber.c_str(), &hints, &serverInfo);
};

TcpClient::~TcpClient()
{
    freeaddrinfo(serverInfo); 
    disconnect(); 
};

void TcpClient::connect()
{


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
        

