#include "tcp_client.hpp"
#include <iostream>


int main(int argc, char*argv[]){
    std::string portNumber = "12345"; 
    std::string host = "127.0.0.1";
    TcpClient* client =  new TcpClient();
    std::string message = "Pretty Boy Slim\n";

    if(client->connectClient(host,portNumber))
    {
        std::cout << "connected\n"; 

        client->send(message);
        std::cout << "message sent\n"; 
        std::cout << client->recieve() << std::endl; 

        client->disconnect(); 
    } 
    else
    {
        std::cout << "Connection failed\n"; 
    }

    delete client; 
    return 0; 

}