#pragma once
#include <fstream>

class Message {
	std::string _text;
	std::string _sender;
	std::string _receiver;
public:
	Message(std::string text = "Message", std::string sender = "USER_1", std::string receiver = "USER_2") :
		_text(text), _sender(sender), _receiver(receiver) {
	}

	friend std::fstream& operator >>(std::fstream& is, Message& msg);
	friend std::ostream& operator <<(std::ostream& os, const Message& nmsg);
};

