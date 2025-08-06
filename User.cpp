#include "User.h"
#include <fstream>

std::fstream& operator >>(std::fstream& is, User& user)
{
	is >> user._name;
	is >> user._login;
	is >> user._pass;
	return is;
}

std::ostream& operator <<(std::ostream& os, const User& user)
{
	os << user._name << " " << user._login << " " << user._pass;
	return os;
}
