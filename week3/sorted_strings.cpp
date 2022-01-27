#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class SortedStrings {
public:
    void AddString(const std::string& str) {
        strings.push_back(str);
    }
    std::vector<std::string> GetSortedStrings() {
        std::sort(std::begin(strings), std::end(strings));
        return strings;
    }
private:
    std::vector<std::string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const std::string& s : strings.GetSortedStrings()) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
