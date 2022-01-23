#include <iostream>
#include <map>
#include <string>
#include <vector>

// NEW_BUS bus stop_count stop1 stop2 ...
// BUSES_FOR_STOP stop
// STOPS_FOR_BUS bus
// ALL_BUSES

using Route = std::map<std::string, std::vector<std::string>>; // один маршрут
using Bus = std::vector<std::string>; // автобусы, для порядка

int main()
{
    int Q = 0; // количество запросов
    std::string req; // запрос
    std::string bus; // автобус
    std::string bus_stop;
    int stop_count = 0; // количество остановок
    Route routes; // маршруты автобусов
    Bus buses;

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
                    std::cout << "Bus " << route.first << ": ";
                        for (const auto& elem : route.second)
                        {
                            std::cout << elem << ' ';
                        }
                    std::cout << std::endl;
                }
            }
        }
        else if (req == "NEW_BUS")
        {
            std::vector<std::string> tmp_r;
            std::string tmp;

            std::cin >> bus;
            std::cin >> stop_count;

            for (int i = 0; i < stop_count; i++)
            {
                std::cin >> tmp;
                tmp_r.push_back(tmp);
            }
            routes[bus] = tmp_r;
            buses.push_back(bus);
        }
        else if (req == "BUSES_FOR_STOP")
        {
            std::string list;
            std::cin >> bus_stop;
            if (routes.empty()) {
                std::cout << "No stop" << std::endl;
            } else {
                for (const auto &bus: buses) {
                    for (const auto& stop : routes.find(bus)->second) {
                        if (stop == bus_stop) {
                            list += (routes.find(bus)->first + ' ');
                        }
                    }
                }
                if (list.empty()) {
                    std::cout << "No stop" << std::endl;
                } else {
                    std::cout << list << std::endl;
                }
            }
        }
        else if (req == "STOPS_FOR_BUS") {
            std::string result;
            std::cin >> bus;

            if (routes.empty() || routes.count(bus) == 0) {
                std::cout << "No bus" << std::endl;
            } else {
                for (const auto &stop: routes.find(bus)->second) {
                    std::cout << "Stop " << stop << ": ";

                    for (const auto& sm_bus : buses) {
                        if (sm_bus != bus) {
                            for (const auto &route: routes.find(sm_bus)->second) {
                                if (route == stop) {
                                    result += (sm_bus + " ");
                                }
                            }
                        }
                    }

                    if (!result.empty())
                        std::cout << result;
                    else
                        std::cout << "no interchange";
                    std::cout << std::endl;
                    result = "";
                }

            }
        }
        else
        {
            std::cout << "Invalid command: " << req << std::endl;
            i--;
        }
    }

    return 0;
}
