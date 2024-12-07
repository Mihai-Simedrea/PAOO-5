#include <iostream>

using namespace std;

class Bitmap {};

class Widget {
    private:
        int value;
        Bitmap *pb;

    public:
        Widget(int val = 0) : value(val) {}

        // unexpected behaviour 
        // Widget& operator=(const Widget& rhs) {
        //     delete pb;
        //     pb = new Bitmap(*rhs.pb);
        //     return *this;
        // }

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
