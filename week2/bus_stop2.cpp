#include <iostream>
#include <map>
#include <string>
#include <vector>

using Route = std::map<std::vector<std::string>, int>;

int main() {
    int Q = 0; // количество операций
    int N = 0; // количество остановок

    Route routes;

    int count = 1;

    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        std::vector<std::string> temp_v;
        std::cin >> N;

        for (int j = 0; j < N; j++) {
            std::string temp_s;
            std::cin >> temp_s;
            temp_v.push_back(temp_s);
        }
        if (routes.count(temp_v) == 1) {
            std::cout << "Already exists for " << routes.find(temp_v)->second << std::endl;

        } else {
            routes[temp_v] = count;
            std::cout << "New bus " << count << std::endl;
            count++;
        }
    }

    return 0;
}
