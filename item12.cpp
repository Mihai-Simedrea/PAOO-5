#include <iostream>
#include <string.h>

using namespace std;

class Date {
    public:
        Date() = default;
        Date(const Date& rhs) = default;
        Date& operator=(const Date& rhs) = default;
        ~Date() = default;
};

void logCall(const string& funcName) {
     cout << funcName <<  endl;
}

class Customer {
    public:
        Customer(const string& name = "", const Date& lastTransaction = Date())
            : name(name), lastTransaction(lastTransaction) {}

        Customer(const Customer& rhs) {
            logCall("Customer copy constructor");
            init(rhs);
        }

        Customer& operator=(const Customer& rhs) {
            logCall("Customer copy assignment operator");
            if (this != &rhs) {
                init(rhs);
            }
            return *this;
        }

    private:
        void init(const Customer& rhs) {
            name = rhs.name;
            lastTransaction = rhs.lastTransaction;
        }

        string name;
        Date lastTransaction;
};

class PriorityCustomer : public Customer {
    public:
        PriorityCustomer(const string& name = "", const Date& lastTransaction = Date(), int priority = 0)
            : Customer(name, lastTransaction), priority(priority) {}

        PriorityCustomer(const PriorityCustomer& rhs)
            : Customer(rhs),
            priority(rhs.priority) {
            logCall("PriorityCustomer copy constructor");
        }

        PriorityCustomer& operator=(const PriorityCustomer& rhs) {
            logCall("PriorityCustomer copy assignment operator");
            if (this != &rhs) {
                Customer::operator=(rhs);
                priority = rhs.priority;
            }
            return *this;
        }

    private:
        int priority;
};


int main() {
    Date d1, d2;
    Customer c1("Alice", d1), c2("Bob", d2);
    c2 = c1;
    Customer c3(c1);

    PriorityCustomer pc1("Charlie", d1, 5), pc2("Diana", d2, 10);
    pc2 = pc1;
    PriorityCustomer pc3(pc1);

    return 0;
}