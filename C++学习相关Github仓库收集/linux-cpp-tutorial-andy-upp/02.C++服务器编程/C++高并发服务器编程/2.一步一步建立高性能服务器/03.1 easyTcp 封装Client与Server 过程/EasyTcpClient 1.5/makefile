obj = *.o
target = server client


# server: server.o
# 	g++ server.o  -o server  
# server.o: server.cpp  
# 	gcc -std=c++11 -c server.cpp -o server.o  


client: client.o
	g++ client.o  -o client
client.o: client.cpp
	g++   -std=c++11 -c client.cpp -pthread -o client.o  


.PHONY: clean  
clean:
	rm -rf $(obj) $(target)


