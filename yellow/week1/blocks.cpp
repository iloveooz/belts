#include <iostream>
#include <cstdint>
// 10^5 <= 100'000
// ro <= 100
// (w, h, d) <= 10^4 = 10000

int main() {
    uint64_t massa = 0;

    int64_t n = 0;
    int64_t ro = 0;

    int64_t w = 0, h = 0, d = 0;

    std::cin >> n >> ro;

    for (int i = 0; i < n; i++) {
        int64_t t = 0;
        std::cin >> w >> h >> d;
        t = ro * (w * h * d);

        massa += t;
    }

    std::cout << massa;
    return 0;
}
