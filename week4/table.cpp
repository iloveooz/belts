#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream ifs("input.txt");

    int n = 0, m = 0;
    ifs >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = 0;
            ifs >> x;
            ifs.ignore(1);
            std::cout << std::setw(10) << x;
            if (j != m - 1) {
                std::cout << " ";
            }
        }
        if (i != n - 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}
