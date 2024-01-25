#include <tcp_client.hpp>
#include <iostream>


int main(int argc, char*argv[]){

    TcpClient client;
    std::string message = "Pretty Boy Slim";
    

    client.connect("127.0.0.1", 2400); 

    client.send(message);
    std::cout << client.recieve() << std::endl; 

    client.disconnect(); 

    
    return 0; 

}