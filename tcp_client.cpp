#include "tcp_client.hpp"
#include <iostream> 
#include <string> 
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>



TcpClient::TcpClient()
{

    socket_id = 0;
    ptr = nullptr; 
    std::memset(&hints,0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM; 
    serverInfo = nullptr; 
};

TcpClient::~TcpClient()
{
    freeaddrinfo(serverInfo); 
    disconnect(); 
};

void* startRecieveLoop(void* tcpInstance){
    TcpClient* client = static_cast<TcpClient*>(tcpInstance);
    client->TcpClient::recieveLoop();
    return nullptr; 
}
void* TcpClient::get_in_addr(struct sockaddr *sa) 
{
    if (sa->sa_family == AF_INET) 
    {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr); 
}

bool TcpClient::connectClient(const std::string& host, const std::string& portNumber, std::function<void(const std::string&)> callBack)
{
    this->callBack = callBack; 

    int status = getaddrinfo(host.c_str(),portNumber.c_str(),&hints, &serverInfo);
    if(status != 0){
        std::cerr << "getaddrinfo failed: " << gai_strerror(status) << std::endl;
        return false; 
    }
    // Create the socket availible addresses
    for(ptr = serverInfo; ptr != nullptr; ptr = ptr->ai_next)
    {
        if((socket_id = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol))== -1)
        {
            perror("client: socket");
            continue; 
        }
        break; 
    }
    // failed to get create a socket from the availaible addresses
    if(ptr == nullptr)
    {    
        return false; 
    }
    
    // print the name of the host we are connecting to
    inet_ntop(ptr->ai_family, get_in_addr((struct sockaddr* )ptr->ai_addr), hostName, sizeof(hostName));
    std::cout << "client connecting to: " << hostName << "\n";

    //create thread before connecting to the socket, check if it fails
    if(pthread_create(&recievedThread, nullptr, startRecieveLoop, this)!= 0){
        return false; 
    }
    if(connect(socket_id,ptr->ai_addr,ptr->ai_addrlen) < 0)
    {
        return false; 
    }
    std::cout << "connected\n"; 
    return true;


}

bool TcpClient::send(std::string& msg)
{
    int n = write(socket_id, msg.c_str(), msg.size());
    if(n < 0)
    {
        return false; 
    }
    std::cout << "message sent\n"; 
    return true; 
}
std::string TcpClient::recieve(int max_size)
{
    std::string buffer(max_size + 1, '\0');
    int n = read(socket_id, &buffer[0], max_size);
    buffer[n] = '\0';
    return buffer;
}

void TcpClient::recieveLoop(int max_size)
{
    std::string buffer(max_size + 1, '\0');
    char temp;
    while (read(socket_id, &temp, 1) > 0) {
        if (temp == '\n') {
            callBack(buffer);
            buffer.clear();
        } else {
            buffer += temp;
        }
    }
}


void TcpClient::disconnect()
{
    close(socket_id);
    pthread_join(recievedThread, nullptr); 
    socket_id = 0; 
}
        

