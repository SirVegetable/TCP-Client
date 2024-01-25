tcp_client.o: tcp_client.cpp tcp_client.hpp
		g++ -o $@ -c $<

tcp_client: main.cpp tcp_client.o
		g++ -o $@ $< tcp_client.o