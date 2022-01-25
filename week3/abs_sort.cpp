#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N = 0;
    std::cin >> N;

    std::vector<int> A(N);

    for (auto& i : A) {
        std::cin >> i;
    }

    std::sort(begin(A), end(A), [] (int i, int j) {
        return abs(i) < abs(j);
    });

    for (const auto& i : A) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;
}
