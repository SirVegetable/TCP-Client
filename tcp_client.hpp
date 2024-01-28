
#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP
#include <string> 
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <thread>


class TcpClient {
    protected: 
        int socket_id;
        struct addrinfo hints;
        struct addrinfo *serverInfo;
        struct addrinfo *ptr; 
        int status;
        char hostName[INET6_ADDRSTRLEN];

    public: 

        TcpClient(); 
        ~TcpClient();
        void* get_in_addr(struct  sockaddr*);
        bool connectClient(const std::string& host, const std::string& portNumber);
        bool send(std::string& msg); 
        std::string recieve(int max_size = 2048);
        void recieveLoop(int max_size = 2048);
        void disconnect(); 
        


};
#endif