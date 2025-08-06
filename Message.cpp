#include "Message.h"
#include <fstream>

std::fstream& operator >>(std::fstream& is, Message& msg)
{
	is >> msg._text;
	is >> msg._sender;
	is >> msg._receiver;
	return is;
}

std::ostream& operator <<(std::ostream& os, const Message& msg)
{
	os << msg._text << " " << msg._sender << " " << msg._receiver;
	return os;
}