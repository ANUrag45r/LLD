#include <bits/stdc++.h>
using namespace std;

// Factory Pattern for choosing a vehicle for an Uber ride

// Interface / Abstract class
class Ride {
public:
    virtual void bookride() = 0;
    virtual ~Ride() = default;
};

// Concrete class 1: Car
class Car : public Ride {
private:
    string name;

public:
    Car(string s) {
        name = s;
        cout << name << " please wait...." << endl;
    }

    void bookride() override {
        cout << "Congrats " << name << ", car ride booked" << endl;
    }
};

// Concrete class 2: Bike
class Bike : public Ride {
private:
    string name;

public:
    Bike(string s) {
        name = s;
        cout << name << " please wait...." << endl;
    }

    void bookride() override {
        cout << "Congrats " << name << ", bike ride booked" << endl;
    }
};

// Factory
class Factory {
public:
    static Ride* choose(string vehicle, string name) {

        if (vehicle == "CAR") {
            return new Car(name);
        }

        if (vehicle == "BIKE") {
            return new Bike(name);
        }

        return nullptr;
    }
};

int main() {

    string name, vehicle;
    cin >> name >> vehicle;

    Ride* r = Factory::choose(vehicle, name);

    if (r != nullptr) {
        r->bookride();
        delete r;
    }

    return 0;
}