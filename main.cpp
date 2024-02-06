#include "tcp_client.hpp"
#include <iostream>
#include <string>



int main(){
    std::string portNumber = "12345"; 
    std::string host = "127.0.0.1";
    TcpClient client;
    std::string message;

    if(client.connectClient(host,portNumber,[](const std::string& msg){
        std::cout << msg << "\n";
    }))
    {
        while(true){
            std::getline(std::cin,message);
            if(message == "QUIT"){
                break; 
            }
            message += "\n";
            client.send(message);

        }
        client.disconnect(); 

    } 
    else
    {
        std::cout << "Connection failed\n"; 
    }
    return 0; 

}