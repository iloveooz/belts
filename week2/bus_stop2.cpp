#include <iostream>
#include <map>
#include <string>
#include <vector>

using Route = std::map<std::vector<std::string>, int>;

int main() {
    int Q = 0; // количество операций
    int N = 0; // количество остановок

    Route routes;

    int count = routes.size() + 1;

    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        std::cin >> N;
        std::vector<std::string> stops(N);

        for (auto& str : stops) {
            std::cin >> str;
        }
        if (routes.count(stops) == 1) {
            std::cout << "Already exists for " << routes.find(stops)->second << std::endl;

        } else {
            routes[stops] = count;
            std::cout << "New bus " << count++ << std::endl;
        }
    }

    return 0;
}
