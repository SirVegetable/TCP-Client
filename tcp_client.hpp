
#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP
#include <string> 
#include <arpa/inet.h>
#include <netdb.h>
#include <type_traits>


class TcpClient {
    protected: 
        int socket_handler;
        struct addrinfo hints;
        struct addrinfo *serverInfo;
        struct addrinfo *ptr; 
        int status;
        char s[INET6_ADDRSTRLEN]; 

    public: 

        TcpClient(); 
        ~TcpClient();
        void* get_in_addr(struct  sockaddr*);
        bool connectClient(const std::string& host, const std::string& portNumber);
        void send(std::string& msg); 
        std::string recieve();
        void disconnect(); 
        


};
#endif