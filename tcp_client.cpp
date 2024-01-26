#include "tcp_client.hpp"

#include <string> 
#include <arpa/inet.h>
#include <netdb.h>


TcpClient::TcpClient()
{

    socket_handler = 0; 

};

TcpClient::~TcpClient()
{
    disconnect(); 
};
void* TcpClient::get_in_addr(struct sockaddr_in &server_address)
{

}

void TcpClient::connect(const std::string& host, int portnumber)
{
    int getaddrinfo();
    socket_handler = socket(AF_INET, SOCK_STREAM, 0);
    int IP = inet_pton(AF_INET, host.c_str() , &server_address.sin_addr);
    if(IP == -1)
    {
        
    }
    else
    {

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
        

