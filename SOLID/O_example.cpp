#include <bits/stdc++.h>
using namespace std;

// ============================================================
// INTERFACE
// ============================================================
// payment acts as an INTERFACE.
// It tells every payment method: "You MUST implement pay()."
//
// Since pay() is pure virtual (= 0), payment is an ABSTRACT CLASS.
//
// ABSTRACTION:
// We expose only WHAT a payment method should do (pay())
// and hide HOW each payment method performs the payment.
// ============================================================

class payment {
public:

    // Pure virtual function
    // Every child class MUST override this function.
    virtual void pay() = 0;

    // Virtual destructor
    // Important when deleting a child object through
    // a parent-class pointer.
    virtual ~payment() = default;
};


// ============================================================
// IS-A RELATIONSHIP
// ============================================================
// meathod1UPI IS-A payment
//
// Inheritance:
// meathod1UPI --> payment
//
// This is also called an IS-A relationship.
// ============================================================

class meathod1UPI : public payment {
public:

    // Runtime Polymorphism
    // Child class provides its own implementation of pay().
    void pay() override {
        cout << "UPI" << endl;
    }
};


// ============================================================
// IS-A RELATIONSHIP
// ============================================================
// meathod2Net IS-A payment
//
// It also inherits from payment and provides its own
// implementation of pay().
// ============================================================

class meathod2Net : public payment {
public:

    void pay() override {
        cout << "NET_BANKING" << endl;
    }
};


// ============================================================
// OPEN-CLOSED PRINCIPLE (OCP)
// ============================================================
// OCP says:
//
// "Classes should be OPEN for extension
//  but CLOSED for modification."
//
// Suppose tomorrow we want:
//
//     CreditCard
//     PayPal
//     Crypto
//
// We can simply create new classes:
//
//     class CreditCard : public payment
//     class PayPal : public payment
//
// We DON'T need to modify the existing payment class.
//
// Therefore, this design follows OCP.
// ============================================================


int main() {

    // ========================================================
    // POLYMORPHISM
    // ========================================================
    // Parent-class pointer pointing to child-class object.
    //
    // payment*  --->  meathod1UPI object
    //
    // Because pay() is virtual, C++ decides at RUNTIME
    // which pay() function should be called.
    // ========================================================

    payment* p = new meathod1UPI();

    p->pay();       // Output: UPI

    delete p;


    // ========================================================
    // Another payment method
    // ========================================================
    // meathod2Net IS-A payment
    // ========================================================

    payment* p1 = new meathod2Net();

    p1->pay();      // Output: NET_BANKING

    delete p1;


    return 0;
}