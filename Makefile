CC = g++
CFLAGS = -g -Wall -Wextra -std=c++17

all: tcp_client

tcp_client: main.o tcp_client.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp tcp_client.hpp
	$(CC) $(CFLAGS) -c $<

tcp_client.o: tcp_client.cpp tcp_client.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f tcp_client *.o

