#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <sstream>
#include <string>

template <typename Collection>
std::string Join(const Collection& collection, char d) {
	std::stringstream ss;
	bool first = true;
	for (const auto& item : collection){
		if (!first) {
			ss << d;
		}
		first = false;
		ss << item;
	}
	return ss.str();
}

template <typename First, typename Second>
std::pair<First, Second> operator * (const std::pair<First, Second>& p1, const std::pair<First, Second>& p2) {
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return std::make_pair(f, s);
}

template <typename First, typename Second>
std::ostream& operator << (std::ostream& output, const std::pair<First, Second>& pair) {
	return output << '(' << pair.first << ':' << pair.second << ')';
}

template <typename T>
std::ostream& operator << (std::ostream& output, const std::vector<T>& v) {
	return output << '[' << Join(v, ',') << ']';
}

template <typename Key, typename Value>
std::ostream& operator << (std::ostream& output, const std::map<Key, Value>& m) {
	return output << '{' << Join(m, ',') << '}';
}

template <typename T>
T Sqrt(T x) {
	return x * x;
}

int main(int argc, char **argv) {
	auto p = std::make_pair(20000, 5.5);
	std::cout << Sqrt(p) << std::endl;

	std::vector<int> v = {1, 2, 3, 4, 5};
	std::cout << v << std::endl;

	std::vector<std::vector<int>> vi = {{1, 2, 3}, {4, 5}};
	std::cout << vi << std::endl;

	std::vector<std::vector<std::pair<int, double>>> vp = {{{1, 0.5}, {2, 2.0}}, {{4, 3.3}, {5, 5.0}}, {{7, 6.6}, {8, 9.0}}};
	std::cout << vp << std::endl;

	std::map<int, double> m = {{1, 1}, {2, 2}, {3, 3.1}, {4, 4}, {5, 5}};
	std::cout << m << std::endl;

	return 0;
}
