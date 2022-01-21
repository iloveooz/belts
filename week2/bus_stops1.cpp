// ReSharper disable CommentTypo
#include <iostream>
#include <map>
#include <string>
#include <vector>

// NEW_BUS bus stop_count stop1 stop2 ...
// BUSES_FOR_STOP stop
// STOPS_FOR_BUS bus
// ALL_BUSES

using Route = std::map<std::string, std::vector<std::string>>; // один маршрут

int main()
{
	int Q = 0; // количество запросов
	std::string req; // запрос
	std::string bus; // автобус
	int stop_count = 0; // количество остановок
	std::vector<Route> routes; // маршруты автобусов

	std::cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		std::cin >> req;

		if (req == "ALL_BUSES")
		{
			if (routes.empty())
			{
				std::cout << "No buses" << std::endl;
			}
			else
			{
				for (const auto& route : routes)
				{
					std::cout << "Bus ";
					for (const auto& stop : route)
					{
						std::cout << stop.first << ": ";
						for (const auto& elem : stop.second)
						{
							std::cout << elem << ' ';
						}
					}
					std::cout << std::endl;
				}
			}
		}
		else if (req == "NEW_BUS")
		{
			Route route;
			std::vector<std::string> tmp_r;
			std::string tmp;

			std::cin >> bus;
			std::cin >> stop_count;

			for (int i = 0; i < stop_count; i++)
			{
				std::cin >> tmp;
				tmp_r.push_back(tmp);
			}
			route[bus] = tmp_r;
			routes.push_back(route);
		}
		else if (req == "BUSES_FOR_STOP")
		{
			
		}
		else if (req == "STOPS_FOR_BUS")
		{
			
		}
		else
		{
			std::cout << "Invalid command: " << req << std::endl;
			i--;
		}
	}

	system("pause");
	return 0;
}
