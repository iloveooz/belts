// Реализуйте функции и методы классов и при необходимости добавьте свои

#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <string>

enum Command {
	req,
	dat,
	eve
};

class Date {
public:
	Date() {
		m_year = 0;
		m_month = 1;
		m_day = 1;
	}

	Date(int year, int month, int day) {
		m_year = year;
		m_month = month;
		m_day = day;
	}

	int GetYear() const {
		return m_year;
	}

	int GetMonth() const {
		return m_month;
	}

	int GetDay() const {
		return m_day;
	}

	int countDaysInDate() const {
		const int count = m_year * 365 + (m_month - 1) * 31 + m_day;
		return count;
	}
private:
	int m_year;
	int m_month;
	int m_day;
};

bool operator < (const Date& lhs, const Date& rhs) {
	if (lhs.countDaysInDate() < rhs.countDaysInDate())
		return true;
	return false;
}

std::ostream& operator << (std::ostream& stream, const Date& rhs) {
	stream <<
		std::setw(4) << std::setfill('0') << rhs.GetYear() << '/' <<
		std::setw(2) << std::setfill('0') << rhs.GetMonth() << '/' <<
		std::setw(2) << std::setfill('0') << rhs.GetDay();
	return stream;
}

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

std::string ParseCommand(const std::string& str, Command com) {
	std::string result;
	size_t pos1 = str.find(' ');
	size_t pos2 = str.find(' ');

	switch (com) {
		case req:			
			if (pos1 != std::string::npos)
				result = str.substr(0, pos1);
			break;
		case dat:
			if (pos1 != std::string::npos && pos2 != std::string::npos)
				result = str.substr(pos1 + 1, pos2);
			break;
		case eve:
			if (pos2 != std::string::npos)
				result = str.substr(pos2 + 1);
			break;
		default: 
			break;
	}

	return result;
}

int main() {
	Database db;

	std::string command; // request date event
	std::string request; // add del find print
	std::string date;    // year-month-day
	std::string event;   // event


	while (getline(std::cin, command)) {
		request = ParseCommand(command, req);
		date = ParseCommand(command, dat);
		event = ParseCommand(command, eve);

		if (request == "Add") {
			std::cout << request << std::endl;
			std::cout << date << std::endl;
			std::cout << event << std::endl;
		}

		if (request == "Del") {
			std::cout << request << std::endl;
			std::cout << date << std::endl;
			std::cout << event << std::endl;
		}

		if (request == "Find") {
			std::cout << request << std::endl;
			std::cout << date << std::endl;
			std::cout << event << std::endl;
		}

		if (request == "Print") {
			std::cout << request << std::endl;
			std::cout << date << std::endl;
			std::cout << event << std::endl;
		}

		if (command == "q" or command == "Q") {
			break;
		}
	}

	system("pause");
	return 0;
}
