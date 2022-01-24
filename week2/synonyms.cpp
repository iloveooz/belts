#include <string>
#include <map>
#include <set>
#include <iostream>

using Synonyms = std::map<std::string, std::set<std::string>>;

void AddSynonyms(Synonyms& synonyms, const std::string& first, const std::string& second) {
	synonyms[second].insert(first);
	synonyms[first].insert(second);
}

size_t GetSynonymsCount(Synonyms& synonyms, const std::string& first) {
	return synonyms[first].size();
}

bool AreSynonyms(Synonyms& synonyms, const std::string& first, const std::string& second) {
	return synonyms[first].count(second) == 1;
}

int main() {
	int Q = 0;
	Synonyms synonyms;

	std::cin >> Q;

	for (int i = 0; i < Q; i++) {
		std::string req;
		std::cin >> req;

		if (req == "ADD") {
			std::string first, second;
			std::cin >> first >> second;

			AddSynonyms(synonyms, first, second);
		} else if (req == "COUNT") {
			std::string word;
			std::cin >> word;

			std::cout << GetSynonymsCount(synonyms, word) << std::endl;
		} else if (req == "CHECK") {
			std::string first, second;
			std::cin >> first >> second;

			if (AreSynonyms(synonyms, first, second)) {
				std::cout << "YES" << std::endl;
			} else {
				std::cout << "NO" << std::endl;
			}
		}
	}

	return 0;
}
