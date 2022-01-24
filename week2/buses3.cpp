#include <iostream>
#include <string>
#include <map>
#include <set>

int main () {
	int Q = 0;
	std::map<std::set<std::string>, int> buses;
	std::string stop;

	std::cin >> Q; 
	
	for (int j = 0; j < Q; j++) {
		int N = 0;
		std::cin >> N;
		
		std::set<std::string> stops;

		for (int i = 0; i < N; i++) {
			std::cin >> stop;
			stops.insert(stop);
		}

		if (buses.count(stops) == 0) {
			int num = buses.size() + 1;
			buses[stops] = num;
			std::cout << "New bus " << num << std::endl;
		} else
			std::cout << "Already exists for " << buses[stops] << std::endl;

	}
	return 0;
}
