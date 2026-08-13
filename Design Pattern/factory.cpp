#include <bits/stdc++.h>
using namespace std;

// Interface / Abstract class
class Payment {
public:
    virtual void pay() = 0;
    virtual ~Payment() = default;
};

// Concrete class 1
class UPIPayment : public Payment {
public:
    void pay() override {
        cout << "User decided UPI payment" << endl;
    }
};

// Concrete class 2
class NetBanking : public Payment {
public:
    void pay() override {
        cout << "User decided NetBanking payment" << endl;
    }
};

// Factory
class Factory {
public:
    static Payment* selectPayment(string mode) {

        if (mode == "UPI") {
            return new UPIPayment();
        }

        if (mode == "NET Banking") {
            return new NetBanking();
        }

        return nullptr;
    }
};

int main() {

    string s;
    cin >> s;

    Payment* p = Factory::selectPayment(s);

    if (p != nullptr) {
        p->pay();
        delete p;
    }

    return 0;
}