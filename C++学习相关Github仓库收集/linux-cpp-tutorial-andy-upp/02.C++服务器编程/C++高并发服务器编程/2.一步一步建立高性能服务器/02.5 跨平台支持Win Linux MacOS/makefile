obj = *.o
target = server client


server: server.o
	g++ server.o  -o server  
server.o: easyTcpServer.cpp  
	gcc -std=c++11 -c easyTcpServer.cpp -o server.o  


# client: client.o
# 	g++ client.o  -o client
# client.o: easyTcpClient.cpp  
# 	g++   -std=c++11 -c easyTcpClient.cpp -pthread -o client.o  



.PHONY: clean  
clean:
	rm -rf $(obj) $(target)


