#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <WinSock2.h>
#include <string>
typedef char byte;
typedef std::string string;

class ClientSocket
{
private:
	static bool WSA_LOADED;
	static unsigned int ClientSocket::instances = 0;

  SOCKET s_;

public: 
	ClientSocket();
	~ClientSocket();

	connect(const string& host, int port);
	void close();

	int receive(byte * buffer, int read_len); 
  int send(const byte * buffer,  int write_len);
}

#endif /* CLIENTSOCKET_H */

