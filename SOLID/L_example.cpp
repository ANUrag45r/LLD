#include <bits/stdc++.h>
using namespace std;

// =====================================================
// LISKOV SUBSTITUTION PRINCIPLE (LSP)
// =====================================================
// Definition:
// Child objects should be replaceable with parent objects
// without breaking the correctness of the program.
//
// Easy way to remember:
// "Every Eagle can be used wherever a Bird is expected."
// "Every Penguin can be used wherever a Bird is expected."
//
// If a child cannot properly behave as its parent,
// inheritance is wrong and LSP is violated.
// =====================================================


// Base Class
// Contains behavior common to ALL birds.
class Bird {
public:

    virtual void eat() {
        cout << "Bird is eating" << endl;
    }

    virtual ~Bird() = default;
};


// Not every bird can fly.
// Therefore flying behavior is separated.
//
// FlyingBird IS-A Bird
class FlyingBird : public Bird {
public:

    virtual void fly() = 0;

    virtual ~FlyingBird() = default;
};


// Eagle IS-A FlyingBird
// Eagle can eat and fly.
class Eagle : public FlyingBird {
public:

    void eat() override {
        cout << "Eagle is eating" << endl;
    }

    void fly() override {
        cout << "Eagle is flying" << endl;
    }
};


// Penguin IS-A Bird
// Penguin cannot fly.
//
// Therefore Penguin inherits only from Bird
// and NOT from FlyingBird.
//
// This is what makes the design follow LSP.
class Penguin : public Bird {
public:

    void eat() override {
        cout << "Penguin is eating" << endl;
    }
};



int main() {

    Eagle eagle;
    Penguin penguin;

    // =================================================
    // LSP DEMONSTRATION
    // =================================================
    // Parent pointer -> Child object
    //
    // Eagle can replace Bird
    // Penguin can replace Bird
    //
    // Therefore LSP is satisfied.
    // =================================================

    Bird* b1 = new Eagle();
    Bird* b2 = new Penguin();

    b1->eat();     // Eagle is eating
    b2->eat();     // Penguin is eating

    cout << endl;


    // =================================================
    // FlyingBird pointer can point only to birds
    // that can actually fly.
    //
    // Eagle works.
    // Penguin does not.
    // =================================================

    FlyingBird* fb = new Eagle();

    fb->fly();     // Eagle is flying

    cout << endl;


    // Cleanup
    delete b1;
    delete b2;
    delete fb;

    return 0;
}