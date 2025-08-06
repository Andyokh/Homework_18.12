#include "User.h"
#include "Message.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
	//Открытие файла в конструкторе 
	std::fstream user_file("users.txt", std::ios::in | std::ios::out | std::ios::app);
	if (!user_file)
		user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
	std::fstream msg_file("msg.txt", std::ios::in | std::ios::out | std::ios::app);
	if (!msg_file) {
		msg_file = std::fstream("msg.txt", std::ios::in | std::ios::out | std::ios::trunc);
	}

	//Установка прав доступа к файлу
	if (user_file || msg_file) {
		fs::permissions("users.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
		fs::permissions("msg.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
	}
	char key = 'a';
	while (key != 'q')
	{
		User user;
		std::vector<User> users;
		Message msg;
		std::vector<Message> messages;
		int n{};
		std::cout << "Select '1' read, '2' write: ";
		std::cin >> n;
		// Считывание данных из файла
		if (n == 1 && (user_file || msg_file))
		{
			user_file.seekg(0, std::ios_base::beg);
			while (user_file >> user)
				users.emplace_back(user);
			msg_file.seekg(0, std::ios_base::beg);
			while (msg_file >> msg)
				messages.emplace_back(msg);
		}
		if (users.empty())
			users.emplace_back(user);
		if (messages.empty())
			messages.emplace_back(msg);

		// Вывод данных на консоль
		for (const auto& user : users)
			std::cout << user << std::endl;
		for (const auto& msg : messages)
			std::cout << msg << std::endl;

		// Запись данных в файл
		if (n == 2 && (user_file || msg_file))
		{
			user_file.seekp(0, std::ios_base::end);
			user_file << '\n';
			for (const auto& user : users)
				user_file << user << std::endl;
			msg_file.seekp(0, std::ios_base::end);
			msg_file << '\n';
			for (const auto& msg : messages)
				msg_file << msg << std::endl;
		}
		user_file.clear();
		msg_file.clear();
		std::cout << std::endl;
		std::cout << "To exit the program press q or press any key to continue: ";
		std::cin >> key;
	}
	return 0;
}



