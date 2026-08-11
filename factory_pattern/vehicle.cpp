// Vehicle Factory
// Interface: Vehicle
// Classes: Car, Bike, Truck
// VehicleFactory::createVehicle(type)


// Notification Factory
// Interface: Notification
// Classes: EmailNotification, SMSNotification, PushNotification
// NotificationFactory::createNotification(type)

//oestion 1
//interface for vehicle
class Vehicle{
    public:
      virtual void drive() = 0;
      virtual ~Vehicle() = default;
};

class car: public Vehicle{
    public:
    void drive() override{
        cout<<"car is on its way"<<endl;
    }
};

class bike:public Vehicle{
    public:
    void drive() override{
        cout<<"bike is on its way"<<endl;
    }
};