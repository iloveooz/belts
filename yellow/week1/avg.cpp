#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> temp(n);
    int64_t sum = 0;
    for (int& t : temp) {
        std::cin >> t;
        sum += t;
    }

    int avg = sum / n;
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (temp[i] > avg) {
            result.push_back(i);
        }
    }

    std::cout << result.size() << std::endl;
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
