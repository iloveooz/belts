// Реализуйте функции и методы классов и при необходимости добавьте свои

#include <iostream>
#include <map>
#include <vector>
#include <string>

class Date {
public:
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
	void AddEvent(const Date& date, const std::string& event);
	bool DeleteEvent(const Date& date, const std::string& event);
	int  DeleteDate(const Date& date);

	void Find(const Date& date) const;

	void Print() const;
private:
	std::map<Date, std::vector<std::string>> dbase;
};

int main() {
	Database db;

	std::string command;
	while (getline(std::cin, command)) {
		if (command == "exit" or command == "EXIT" or command == "quit" or command == "QUIT") {
			break;
		}
	}

	return 0;
}
