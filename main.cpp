#include <iostream>

using namespace std;

class Bitmap {};

class Widget {
    private:
        int value;
        Bitmap *pb;

    public:
        Widget(int val = 0) : value(val), pb(nullptr) {}

        void swap(Widget& other) {
            std::swap(value, other.value);
            std::swap(pb, other.pb);
        }

        // Widget& operator=(const Widget& rhs) {
        //     if (this == &rhs) return *this; // check for self-assignment
        //     delete pb;
        //     pb = new Bitmap(*rhs.pb);
        //     return *this;
        // }

        // Widget& operator=(const Widget& rhs) {
        //     Bitmap* pOrig = pb; // remember original pb
        //     pb = new Bitmap(*rhs.pb); // point pb to a copy of rhs's bitmap
        //     delete pOrig; // delete original pb
        //     return *this;
        // }

        Widget& operator=(const Widget& rhs) {
            Widget temp(rhs); // make a copy of rhs's data
            swap(temp); // swap *this's data with the copy's
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
