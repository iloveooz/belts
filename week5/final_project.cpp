// Реализуйте функции и методы классов и при необходимости добавьте свои

#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

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
    void AddEvent(const Date& date, const std::string& event) {
        dbase[date].push_back(event);
        SortEvents(date);
    }

    bool DeleteEvent(const Date& date, const std::string& event) {
        if (std::count(dbase.at(date).begin(), dbase.at(date).end(), event) > 0) {
            dbase.at(date).erase(
                    std::remove_if(dbase.at(date).begin(), dbase.at(date).end(),
                                   [&event] (const std::string& value) { return value == event; }), dbase.at(date).end());
            return true;
        } else {
            return false;
        }
    }

    int  DeleteDate(const Date& date) {
        size_t size = dbase.at(date).size();
        if (dbase.count(date) > 0) {
            dbase.erase(date);
        }
        return size;
    }

    void Find(const Date& date) const {
        
    }

    void Print() const {
        for (const auto& [key, value] : dbase) {
            std::cout << key << ' ';
            for (const auto& item : value) {
                std::cout << item << ' ';
            }
            std::cout << std::endl;
        }
    }

private:
    void SortEvents(const Date& date) {
        std::sort(dbase.at(date).begin(), dbase.at(date).end());
    }
    std::map<Date, std::vector<std::string>> dbase;
};

std::vector<std::string> ParseCommand(const std::string& str) {
    std::vector<std::string> result;
    char delimiter = ' ';
    std::string word;

    std::stringstream sstream(str);

    while(std::getline(sstream, word, delimiter)) {
        result.push_back(word);
    }

    return result;
}

Date ParseDate(const std::string& sDate) {
    std::vector<std::string> date_parts;
    char delimiter = '-';
    std::string word;

    std::stringstream sstream(sDate);

    while(std::getline(sstream, word, delimiter)) {
        date_parts.push_back(word);
    }

    Date date(std::stoi(date_parts[0]), std::stoi(date_parts[1]), std::stoi(date_parts[2]));

    return date;
}

int main() {
    Database db;

    std::string command; // request date event
    std::vector<std::string> request; // add del find print
    Date date;


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
                    } else {
                        std::cout << "Event not found" << std::endl;
                    }
                } else {
                    std:: cout << "Deleted " << db.DeleteDate(date) << " events";
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
                std::cout << "Unknown command: " << command << std::endl;
            }

            if (command == "q" or command == "Q") {
                break;
            }
        }
    }

    return 0;
}
