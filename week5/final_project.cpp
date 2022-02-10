// Реализуйте функции и методы классов и при необходимости добавьте свои

#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <string>

class Date {
public:
	Date() {
		m_year = 2022;
		m_month = 02;
		m_day = 10;
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

int main() {
	Database db;

	std::string command;

	while (getline(std::cin, command)) {
		if (command == "Add") {
			
		}

		if (command == "Del") {

		}

		if (command == "Find") {

		}

		if (command == "Print") {

		}

		if (command == "q" or command == "Q") {
			break;
		}
	}

	system("pause");
	return 0;
}
