
#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP
#include <string> 
#include <arpa/inet.h>
#include <netdb.h>


class TcpClient {
    protected: 
        int socket_handler;
        struct addrinfo hints;
        struct addrinfo *serverInfo;
        struct addrinfo *ptr; 
        int status; 

    public: 

        TcpClient(const std::string& host, const std::string& portNumber); 
        ~TcpClient(); 
        
        void connect();
        void send(std::string& msg); 
        std::string recieve();
        void disconnect(); 
        


};
#endif