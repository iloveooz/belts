#include <string>

class Route {
public:
    void SetSource(const std::string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const std::string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }

    std::string GetSource() {
        return source;
    }
    std::string GetDestination() {
        return destination;
    }
    int GetLength() {
        return length;
    }
private:
    void UpdateLength() {

    }
    std::string source;
    std::string destination;
    int length;
};

int main() {
    Route route;
    return 0;
}
