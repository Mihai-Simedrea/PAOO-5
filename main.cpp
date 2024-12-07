#include <iostream>

using namespace std;

class Widget {
    private:
        int value;

    public:
        Widget(int val = 0) : value(val) {}

        Widget& operator=(const Widget& rhs) {
            value = rhs.value;
            return *this;
        }

        void display() const {
            cout << "Value: " << value << endl;
        }
};

int main() {
    Widget w1(10), w2(20), w3;

    w3 = w2 = w1;
    w3.display();

    return 0;
}
