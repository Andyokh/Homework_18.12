#pragma once
#include <fstream>

class User {
	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User(std::string name = "USER", std::string login = "QWERTY", std::string pass = "12345") :
		_name(name), _login(login), _pass(pass) {
	}

	friend std::fstream& operator >>(std::fstream& is, User& user);
	friend std::ostream& operator <<(std::ostream& os, const User& user);
};
