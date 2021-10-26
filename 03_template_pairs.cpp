#include <iostream>
#include <utility>

template <typename First, typename Second>
std::pair<First, Second> operator * (const std::pair<First, Second>& p1, const std::pair<First, Second>& p2) {
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return std::make_pair(f, s);
}

template <typename First, typename Second>
std::ostream& operator << (std::ostream& output, const std::pair<First, Second>& pair) {
	output << pair.first << ' ' << pair.second;
	return output;
}

template <typename T>
T Sqrt(T x) {
	return x * x;
}

int main(int argc, char **argv) {
	auto p = std::make_pair(2, 5.5);
	std::cout << Sqrt(p) << std::endl;
	return 0;
}
