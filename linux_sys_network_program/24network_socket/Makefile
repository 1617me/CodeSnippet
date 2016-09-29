tcp: tcp_server tcp_client

tcp_server:tcp_server.o
	gcc tcp_server.c -o server
	
tcp_client:tcp_client.o
	gcc tcp_client.c -o client

tcp_server.o: tcp_server.c
	gcc -c tcp_server.c
	
tcp_client.o:tcp_client.c
	gcc -c tcp_client.c


udp: udp_server udp_client

udp_server:udp_server.o
	gcc udp_server.c -o server
	
udp_client:udp_client.o
	gcc udp_client.c -o client

udp_server.o: udp_server.c
	gcc -c udp_server.c
	
udp_client.o:udp_client.c
	gcc -c udp_client.c
	
.PHONY:clean
clean:
	rm -rf *.o
