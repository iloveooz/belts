// Реализуйте функции и методы классов и при необходимости добавьте свои

#include <iostream>
#include <map>
#include <vector>
#include <string>

enum class DaysInMonth {
	January = 31,
	February = 28,
	March = 31,
	April = 30,
	May = 31,
	June = 30,
	July = 31,
	August = 31,
	September = 30,
	October = 31,
	November = 30,
	December = 31
};

class Date {
public:
	Date() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
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
private:
	int countDaysInDate() const {
		
	}

	int m_year;
	int m_month;
	int m_day;
};

bool operator < (const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear()) {
		return true;
	} else {
		if (lhs.GetMonth() < rhs.GetMonth()) {

		}
	}
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

	return 0;
}
