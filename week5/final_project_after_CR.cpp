// Реализуйте функции и методы классов и при необходимости добавьте свои

#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <exception>

class Date {
public:
    Date() {
        m_year = 0;
        m_month = 1;
        m_day = 1;
    }

    Date(int year, int month, int day) {
        m_year = year;
        if (month < 1 or month > 12)
            throw std::logic_error("Month value is invalid: " + std::to_string(month));
        m_month = month;
        if (day < 1 or day > 31)
            throw std::logic_error("Day value is invalid: " + std::to_string(day));
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
           std::setw(4) << std::setfill('0') << rhs.GetYear() << '-' <<
           std::setw(2) << std::setfill('0') << rhs.GetMonth() << '-' <<
           std::setw(2) << std::setfill('0') << rhs.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const std::string& event) {
        dbase[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const std::string& event) {
        if (dbase.count(date) > 0 && dbase[date].count(event) > 0) {
            dbase[date].erase(event);
            return true;
        }
        return false;
    }

    int  DeleteDate(const Date& date) {

        size_t size = 0;
        if (dbase.count(date) == 0)
            return size;
        else {
            size = dbase[date].size();
            dbase.erase(date);
        }
        return size;
    }

    void Find(const Date& date) const {
        if (!dbase.empty() && dbase.count(date) > 0) {
            for (const auto &entry: dbase.at(date)) {
                std::cout << entry << std::endl;
            }
        }
    }

    void Print() const {
        for (const auto& [key, value] : dbase) {
            if (!value.empty()) {
                for (const auto& item : value) {
                    std::cout << key << ' ' << item << std::endl;
                }
            }
        }
    }

private:
    std::map<Date, std::set<std::string>> dbase;
};

std::vector<std::string> ParseCommand(const std::string& str) {
    std::vector<std::string> result;
    char delimiter = ' ';
    std::string word;

    std::stringstream sstream(str);

    while (std::getline(sstream, word, delimiter)) {
        result.push_back(word);
    }

    return result;
}

Date ParseDate(const std::string& sDate) {
    int year = 0;
    int month = 0;
    int day = 0;

    bool ok = true;

    std::stringstream sstream(sDate);

    ok = ok && (sstream >> year);
    ok = ok && (sstream.peek() == '-');
    sstream.ignore(1);

    ok = ok && (sstream >> month);
    ok = ok && (sstream.peek() == '-');
    sstream.ignore(1);

    ok = ok && (sstream >> day);
    ok = ok && sstream.eof();

    if (!ok) {
        throw std::runtime_error("Wrong date format: " + sDate);
    }

    const Date date(year, month, day);
    return date;
}

void Tests() {

}

int main() {
    Database db;

    Tests();

    std::string command; // request date event
    std::vector<std::string> request; // add del find print
    Date date;

    try {
        while (getline(std::cin, command)) {
            if (!command.empty()) {
                request = ParseCommand(command);
                if (request[0] == "Add") {
                    date = ParseDate(request[1]);
                    db.AddEvent(date, request[2]);
                }
                else if (request[0] == "Del") {
                    date = ParseDate(request[1]);
                    if (request.size() == 3) {
                        if (db.DeleteEvent(date, request[2])) {
                            std::cout << "Deleted successfully" << std::endl;
                        }
                        else {
                            std::cout << "Event not found" << std::endl;
                        }
                    }
                    else {
                        int count = db.DeleteDate(date);
                        std::cout << "Deleted " << count << " events" << std::endl;
                    }
                }
                else if (request[0] == "Find") {
                    date = ParseDate(request[1]);
                    db.Find(date);
                }
                else if (request[0] == "Print") {
                    db.Print();
                }
                else {
                    std::cout << "Unknown command: " << request[0] << std::endl;
                }

                if (command == "q" or command == "Q") {
                    break;
                }
            }

        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
