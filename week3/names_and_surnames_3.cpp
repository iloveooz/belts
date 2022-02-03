#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class Person {
public:
    Person(const std::string& fn, const std::string& sn, int birthyear) {
        if (!fn.empty())
            first_names[birthyear] = fn;
        if (!sn.empty())
            last_names[birthyear] = sn;
        m_birthyear = birthyear;
    }

    void ChangeFirstName(int year, const std::string& first_name) {
        if (year >= m_birthyear)
            first_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        if (year >= m_birthyear)
            last_names[year] = last_name;
    }
    std::string GetFullName(int year) const {
        const std::string first_name = FindNameByYear(first_names, year);
        const std::string last_name = FindNameByYear(last_names, year);

        if (first_name.empty() && last_name.empty())
            return "No person";
        if (first_name.empty() && !last_name.empty())
            return last_name + " with unknown first name";
        if (!first_name.empty() && last_name.empty())
            return first_name + " with unknown last name";
        if (!first_name.empty() && !last_name.empty())
            return first_name + " " + last_name;
        return {};
    }
    std::string GetFullNameWithHistory(int year) const {
        const std::string all_first_names = FindAllNamesByYear(first_names, year);
        const std::string all_last_names =  FindAllNamesByYear(last_names, year);

        if (all_first_names.empty() && all_last_names.empty())
            return "No person";
        if (all_first_names.empty() && !all_last_names.empty())
            return all_last_names + " with unknown first name";
        if (!all_first_names.empty() && all_last_names.empty())
            return all_first_names + " with unknown last name";
        if (!all_first_names.empty() && !all_last_names.empty())
            return all_first_names + " " + all_last_names;
        return {};
    }

private:
    std::string FindNameByYear(const std::map<int, std::string>& dict, int year) const {
        std::string result;
        for (const auto& item : dict) {
            if (item.first <= year)
                result = item.second;
        }
        return result;
    }

    std::string FindAllNamesByYear(const std::map<int, std::string>& dict, int year) const {
        std::vector<std::string> all_names;
        std::string result;

        for (const auto& it : dict)
            if (it.first <= year && (all_names.empty() || all_names.back() != it.second)) {
                all_names.push_back(it.second);
            }

        if (all_names.empty())
            return "";

        std::reverse(std::begin(all_names), std::end(all_names));

        result = all_names[0];

        for (int i = 1; i < all_names.size(); ++i) {
            if (i == 1) {
                result += " (";
            } else {
                result += ", ";
            }
            result += all_names[i];
        }

        if (all_names.size() > 1) {
            result += ")";
        }

        return result;
    }

    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
    int m_birthyear;
};

using namespace std;

int main() {
    {
        Person person("Eugene", "Sokolov", 1900);

        person.ChangeLastName(1910, "Sokolov");
        person.ChangeFirstName(1920, "Evgeny");
        person.ChangeLastName(1930, "Sokolov");
        cout << person.GetFullNameWithHistory(1940) << endl;
    }

    std::cout << "-----" << std::endl;

    {
        Person person("Polina", "", 1965);

        person.ChangeLastName(1967, "Sergeeva");
        for (int year: {1900, 1965, 1990}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeFirstName(1970, "Appolinaria");
        for (int year: {1969, 1970}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeLastName(1968, "Volkova");
        for (int year: {1969, 1970}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeFirstName(1990, "Polina");
        person.ChangeLastName(1990, "Volkova-Sergeeva");
        cout << person.GetFullNameWithHistory(1990) << endl;

        person.ChangeFirstName(1966, "Pauline");
        cout << person.GetFullNameWithHistory(1966) << endl;

        person.ChangeLastName(1960, "Sergeeva");
        for (int year: {1960, 1967}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeLastName(1961, "Ivanova");
        cout << person.GetFullNameWithHistory(1967) << endl;
    }

    std::cout << "-----" << std::endl;

    {
        Person person("Polina", "", 1965);
        person.ChangeFirstName(1965, "Appolinaria");

        person.ChangeLastName(1965, "Sergeeva");
        person.ChangeLastName(1965, "Volkova");
        person.ChangeLastName(1965, "Volkova-Sergeeva");

        for (int year : {1964, 1965, 1966}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }
    }

    std::cout << "-----" << std::endl;

    {
        Person person("Polina", "Sergeeva", 1960);
        for (int year : {1959, 1960}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeFirstName(1965, "Appolinaria");
        person.ChangeLastName(1967, "Ivanova");
        for (int year : {1965, 1967}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

    }

    return 0;
}
