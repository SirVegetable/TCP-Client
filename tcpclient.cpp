#include "tcp_client.hpp"

#include <string> 
#include <arpa/inet.h>


class TcpClient {
    public: 

        TcpClient::TcpClient(){}; 
        TcpClient::~TcpClient(){}; 

        void TcpClient::connect(const std::string& host, int portnumber){};
        void TcpClient::send(std::string& msg){}; 
        std::string TcpClient::recieve(){};
        void TcpClient::disconnect(){}; 
        


};