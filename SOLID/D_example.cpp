#include <bits/stdc++.h>
using namespace std;

// ============================================================
// DEPENDENCY INVERSION PRINCIPLE (DIP)
// ============================================================
//
// High-level class should NOT directly depend on a
// low-level class.
//
// Both should depend on an abstraction (interface).
//
// Easy to remember:
// "Depend on interface, not implementation."
// ============================================================


// ============================================================
// ABSTRACTION / INTERFACE
// ============================================================
//
// Notification is an interface.
// It defines WHAT a notification should do,
// but not HOW it should do it.
//
// Email and SMS will provide the actual implementation.
// ============================================================

class Notification {
public:

    virtual void send(string message) = 0;

    virtual ~Notification() = default;
};


// ============================================================
// LOW-LEVEL MODULE
// ============================================================
//
// EmailNotification IS-A Notification.
// It provides the actual implementation of send().
// ============================================================

class EmailNotification : public Notification {
public:

    void send(string message) override {
        cout << "Email: " << message << endl;
    }
};


// ============================================================
// ANOTHER LOW-LEVEL MODULE
// ============================================================
//
// SMSNotification IS-A Notification.
// ============================================================

class SMSNotification : public Notification {
public:

    void send(string message) override {
        cout << "SMS: " << message << endl;
    }
};


// ============================================================
// HIGH-LEVEL MODULE
// ============================================================
//
// NotificationService is the HIGH-LEVEL class.
//
// IMPORTANT:
// It does NOT depend directly on:
//     EmailNotification
//     SMSNotification
//
// Instead, it depends on:
//     Notification (interface)
//
// This is Dependency Inversion Principle.
// ============================================================

class NotificationService {

private:

    // --------------------------------------------------------
    // MEMBER POINTER
    // --------------------------------------------------------
    //
    // Notification* = type
    // notification   = member variable name
    //
    // This pointer will point to some object that implements
    // the Notification interface.
    //
    // It could point to:
    //     EmailNotification
    //     SMSNotification
    // --------------------------------------------------------

    Notification* notification;


public:

    // --------------------------------------------------------
    // CONSTRUCTOR
    // --------------------------------------------------------
    //
    // Notification* n
    //
    // Here 'n' is a PARAMETER.
    //
    // Someone from outside will give us the address of a
    // Notification object.
    // --------------------------------------------------------

    NotificationService(Notification* n) {

        // Store the received pointer inside our member variable.
        //
        // Left side:
        //     notification
        //     = member variable
        //
        // Right side:
        //     n
        //     = constructor parameter

        notification = n;
    }


    void notifyUser(string message) {

        // Call the send() function through the interface.
        //
        // Because send() is virtual, the correct child
        // implementation will be called at runtime.

        notification->send(message);
    }
};


int main() {

    // ========================================================
    // EMAIL NOTIFICATION
    // ========================================================

    EmailNotification email;

    // &email = address of email object
    //
    // We pass this address to NotificationService.
    //
    // NotificationService expects:
    //     Notification*
    //
    // EmailNotification* can be treated as Notification*
    // because EmailNotification IS-A Notification.

    NotificationService service1(&email);

    service1.notifyUser("Payment successful");


    cout << endl;


    // ========================================================
    // SMS NOTIFICATION
    // ========================================================

    SMSNotification sms;

    // We can give SMS instead of Email.
    //
    // We DON'T need to modify NotificationService.

    NotificationService service2(&sms);

    service2.notifyUser("Payment successful");


    return 0;
}