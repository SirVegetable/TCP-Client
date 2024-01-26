#include <tcp_client.hpp>
#include <iostream>


int main(int argc, char*argv[]){
    std::string portNumber = "12345"; 
    std::string host = "127.0.0.1";
    TcpClient client(host,portNumber);
    std::string message = "Pretty Boy Slim";

    client.connect(); 

    client.send(message);
    std::cout << client.recieve() << std::endl; 

    client.disconnect(); 


    return 0; 

}