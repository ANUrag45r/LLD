#include <bits/stdc++.h>
using namespace std;

// =====================================================
// STRATEGY INTERFACE
// =====================================================

class FareStrategy {
public:
    virtual void fare(int distance) = 0;
    virtual ~FareStrategy() = default;
};


// =====================================================
// CONCRETE STRATEGY 1: BIKE
// =====================================================

class BikeFare : public FareStrategy {
public:

    void fare(int distance) override {
        cout << "Bike fare = " << distance * 20 << endl;
    }
};


// =====================================================
// CONCRETE STRATEGY 2: CAR
// =====================================================

class CarFare : public FareStrategy {
public:

    void fare(int distance) override {
        cout << "Car fare = " << distance * 40 << endl;
    }
};


// =====================================================
// FACTORY
// Factory decides WHICH strategy to create
// =====================================================

class Factory {
public:

    static FareStrategy* choose(string vehicle) {

        if (vehicle == "CAR") {
            return new CarFare();
        }

        if (vehicle == "BIKE") {
            return new BikeFare();
        }

        return nullptr;
    }
};


// =====================================================
// MAIN
// =====================================================

int main() {

    string vehicle;
    int distance;

    cin >> vehicle >> distance;

    // Factory chooses the strategy
    FareStrategy* f = Factory::choose(vehicle);

    if (f == nullptr) {
        cout << "Invalid vehicle" << endl;
        return 0;
    }

    // Strategy executes the algorithm
    f->fare(distance);

    delete f;

    return 0;
}