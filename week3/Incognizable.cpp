class Incognizable {
public:
    Incognizable() {
        a = 0;
        b = 0;
    }
    Incognizable(int a, int b) {
        this->a = a;
        this->b = b;
    }
    Incognizable(int a) {
        this->a = a;
        this->b = 0;
    }

private:
    int a;
    int b;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
