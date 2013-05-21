#include "ClientSocket.h"

unsigned int ClientSocket::instances = 0;


ClientSocket::ClientSocket()
{
	if(instances == 0)
	{ 
    WSADATA info;

    if (WSAStartup(MAKEWORD(2,0), &info)) {
      throw "Could not start WSA";
    }
  }

	instances += 1;
}


ClientSocket::~ClientSocket()
{
	instances -= 1;

	if(instances == 0) {
		WSACleanup(); 
	}
}


void ClientSocket::connect(const std::string & host, int port)
{
  s_ = socket(AF_INET,SOCK_STREAM,0);

  if (s_ == INVALID_SOCKET) {
    throw "INVALID_SOCKET";
  }


  std::string error;

  hostent *he;
  if ((he = gethostbyname(host.c_str())) == 0) {
    error = strerror(errno);
    throw error;
  }

  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr = *((in_addr *)he->h_addr);
  memset(&(addr.sin_zero), 0, 8); 

  if (::connect(s_, (sockaddr *) &addr, sizeof(sockaddr))) {
    error = strerror(WSAGetLastError());
    throw error;
  }
}

void ClientSocket::close()
{
  closesocket(s_);
}


std::string ClientSocket::receive()
{ 
  std::string ret;
  char buf[1024];
 
  while (1) {
    u_long arg = 0;
    if (ioctlsocket(s_, FIONREAD, &arg) != 0)
      break;

    if (arg == 0)
      break;

    if (arg > 1024) arg = 1024;

    int rv = recv (s_, buf, arg, 0);
    if (rv <= 0) break;

    std::string t;

    t.assign (buf, rv);
    ret += t;
  }
 
  return ret;
}

int ClientSocket::sendbuffer(const std::string & buffer)
{ 
  send(s_, buffer.c_str(), buffer.length(), 0);
}
