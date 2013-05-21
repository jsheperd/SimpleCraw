#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <WinSock2.h>
#include <string>

class ClientSocket
{
private:
	static bool WSA_LOADED;
	static unsigned int instances;

  SOCKET s_;

public: 
	ClientSocket();
	~ClientSocket();

	void connect(const std::string& host, int port);
	void close();

	std::string receive(); 
  int sendbuffer(const std::string & buffer);
};

#endif /* CLIENTSOCKET_H */

