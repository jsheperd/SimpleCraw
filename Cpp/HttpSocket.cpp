#include <iostream>
#include "HttpSocket.h"

std::string HTTPSocket::getURL(const std::string & url)
{
	std::string host;
  std::string page;
	
	if(url.substr(0, 7) == std::string("http://")) {
		std::cout << "ez http\n";
	}


//	for(int i, l = url.length(); i<l; i++;) {
//	}


}

int main() {
 HTTPSocket	s;

 s.getURL("http://www.google.com");
 return 1;

}
