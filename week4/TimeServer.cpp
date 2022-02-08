#include <string>
#include <exception>
#include <system_error>
#include <iostream>

std::string AskTimeServer() {
    return "23:00:00";
}

class TimeServer {
public:
    std::string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        } catch (const std::system_error&) {
        }
        return last_fetched_time;
    }

private:
    std::string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        std::cout << ts.GetCurrentTime() << std::endl;
    } catch (std::exception& error) {
        std::cout << "Exception got: " << error.what() << std::endl;
    }
    return 0;
}
