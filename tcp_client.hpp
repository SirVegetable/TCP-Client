
#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP
#include <string> 
#include <arpa/inet.h>


class TcpClient {
    protected: 
        int socket_handler;
        struct sockaddr_in server_address;

    public: 

        TcpClient(); 
        ~TcpClient(); 
        void* get_in_addr(sockaddr_in& server_address);
        void connect(const std::string& host, int portnumber);
        void send(std::string& msg); 
        std::string recieve();
        void disconnect(); 
        


};
#endif