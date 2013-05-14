#include "ClientSocket.h"

bool ClientSocket::WSA_LOADED = false;
unsigned int ClientSocket::instances = 0;

class ClientSocket

ClientSocket::ClientSocket()
{
	if(WSA_LOADED == false)
	{ 
    WSADATA info;

    if (WSAStartup(MAKEWORD(2,0), &info)) {
      throw "Could not start WSA";
	    WSA_LOADED = true;
	    
	    
    }
    
    instances = instance + 1;
  }
}

ClientSocket::~ClientSocket();
{
  instances = instances - 1;
  if ((instances == 0) && (WSA_LOADED == true) {
    WSACleanup();
    WSA_LOADED = false;
  }
}

ClientSocket::connect(string host, int port)
{
  s_ = socket(AF_INET,SOCK_STREAM,0);

  if (s_ == INVALID_SOCKET) {
    throw "INVALID_SOCKET";
  }
}

ClientSocket::close()
{
}

int	ClientSocket::receive(byte * buffer, int read_len)
{ return 1;
}

int ClientSocket::send(const byte * buffer,  int write_len)
{ return 1;
}

