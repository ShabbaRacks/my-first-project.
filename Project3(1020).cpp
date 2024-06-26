// Project3(1020).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Base class Auto
class Auto {
private:
    string* inventoryNumber;
    string* location;

    void allocateMemory();

public:
    // Constructors
    Auto();
    Auto(const string& invNum, const string& loc);
    ~Auto();

    // Accessor functions
    string getInventoryNumber() const;
    string getLocation() const;

    // Mutator functions
    void setInventoryNumber(const string& invNum);
    void setLocation(const string& loc);

    // Virtual Print function
    virtual void Print() const;
};

// Implementation of base class Auto
void Auto::allocateMemory() {
    inventoryNumber = new string;
    location = new string;
}

Auto::Auto() {
    allocateMemory();
}

Auto::Auto(const string& invNum, const string& loc) {
    allocateMemory();
    setInventoryNumber(invNum);
    setLocation(loc);
}

Auto::~Auto() {
    delete inventoryNumber;
    delete location;
}

string Auto::getInventoryNumber() const {
    return *inventoryNumber;
}

string Auto::getLocation() const {
    return *location;
}

void Auto::setInventoryNumber(const string& invNum) {
    if (invNum.empty()) {
        cout << "Warning: Unable to set the Inventory Number because it cannot be an empty string!\n";
    }
    else {
        *inventoryNumber = invNum;
    }
}

void Auto::setLocation(const string& loc) {
    if (loc.empty()) {
        cout << "Warning: Unable to set the Location because it cannot be an empty string!\n";
    }
    else {
        *location = loc;
    }
}

void Auto::Print() const {
    cout << "\nBase Class - Inventory Information\n";
    cout << "__________________________________\n";
    cout << "Inventory Number: " << *inventoryNumber << endl;
    cout << "Location        : " << *location << endl;
}

// Derived class Car
class Car : public Auto {
private:
    string make;
    string model;
    string color;
    int yearBuilt;
    int numberOfDoors;
    string interior;

public:
    // Constructors
    Car() = default;
    Car(const string& invNum, const string& loc, const string& make, const string& model,
        const string& color, int year, int doors, const string& interior);

    // Accessor functions
    string getMake() const;
    string getModel() const;
    string getColor() const;
    int getYearBuilt() const;
    int getNumberOfDoors() const;
    string getInterior() const;

    // Mutator functions
    void setMake(const string& make);
    void setModel(const string& model);
    void setColor(const string& color);
    void setYearBuilt(int year);
    void setNumberOfDoors(int doors);
    void setInterior(const string& interior);

    // Override Print function
    virtual void Print() const override;
};

// Implementation of derived class Car
Car::Car(const string& invNum, const string& loc, const string& make, const string& model,
    const string& color, int year, int doors, const string& interior)
    : Auto(invNum, loc), make(make), model(model), color(color), yearBuilt(year),
    numberOfDoors(doors), interior(interior) {}

string Car::getMake() const {
    return make;
}

string Car::getModel() const {
    return model;
}

string Car::getColor() const {
    return color;
}

int Car::getYearBuilt() const {
    return yearBuilt;
}

int Car::getNumberOfDoors() const {
    return numberOfDoors;
}

string Car::getInterior() const {
    return interior;
}

void Car::setMake(const string& make) {
    if (make.empty()) {
        cout << "Warning: Unable to set the Make because it cannot be an empty string!\n";
    }
    else {
        this->make = make;
    }
}

void Car::setModel(const string& model) {
    if (model.empty()) {
        cout << "Warning: Unable to set the Model because it cannot be an empty string!\n";
    }
    else {
        this->model = model;
    }
}

void Car::setColor(const string& color) {
    if (color.empty()) {
        cout << "Warning: Unable to set the Color because it cannot be an empty string!\n";
    }
    else {
        this->color = color;
    }
}

void Car::setYearBuilt(int year) {
    if (year < 1900) {
        cout << "Warning: Unable to set the Year because it must be above 1900 or greater!\n";
    }
    else {
        yearBuilt = year;
    }
}

void Car::setNumberOfDoors(int doors) {
    if (doors <= 0) {
        cout << "Warning: Unable to set the Number or doors because it must be above 0!\n";
    }
    else {
        numberOfDoors = doors;
    }
}

void Car::setInterior(const string& interior) {
    if (interior.empty()) {
        cout << "Warning: Unable to set the Interior because it cannot be an empty string!\n";
    }
    else {
        this->interior = interior;
    }
}

void Car::Print() const {
    cout << "\n\nDerived Class - Car Information\n";
    cout << "_______________________________\n";
    cout << "Inventory Number: " << getInventoryNumber() << endl;
    cout << "Location        : " << getLocation() << endl;
    cout << "Make            : " << make << endl;
    cout << "Model           : " << model << endl;
    cout << "Color           : " << color << endl;
    cout << "Year            : " << yearBuilt << endl;
    cout << "Number of Doors : " << numberOfDoors << endl;
    cout << "Interior        : " << interior << endl;
}

// Derived class Truck
class Truck : public Auto {
private:
    string make;
    string model;
    string color;
    int yearBuilt{};
    int numberOfDoors{};
    string towingCapacity;

public:
    // Constructors
    Truck() = default;
    Truck(const string& invNum, const string& loc, const string& make, const string& model,
        const string& color, int year, int doors, const string& towingCap);

    // Accessor functions
    string getMake() const;
    string getModel() const;
    string getColor() const;
    int getYearBuilt() const;
    int getNumberOfDoors() const;
    string getTowingCapacity() const;

    // Mutator functions
    void setMake(const string& make);
    void setModel(const string& model);
    void setColor(const string& color);
    void setYearBuilt(int year);
    void setNumberOfDoors(int doors);
    void setTowingCapacity(const string& towingCap);

    // Override Print function
    virtual void Print() const override;
};

// Implementation of derived class Truck
Truck::Truck(const string& invNum, const string& loc, const string& make, const string& model,
    const string& color, int year, int doors, const string& towingCap)
    : Auto(invNum, loc), make(make), model(model), color(color), yearBuilt(year),
    numberOfDoors(doors), towingCapacity(towingCap) {}

string Truck::getMake() const {
    return make;
}

string Truck::getModel() const {
    return model;
}

string Truck::getColor() const {
    return color;
}

int Truck::getYearBuilt() const {
    return yearBuilt;
}

int Truck::getNumberOfDoors() const {
    return numberOfDoors;
}

string Truck::getTowingCapacity() const {
    return towingCapacity;
}

void Truck::setMake(const string& make) {
    if (make.empty()) {
        cout << "Warning: Unable to set the Make because it cannot be an empty string!\n";
    }
    else {
        this->make = make;
    }
}

void Truck::setModel(const string& model) {
    if (model.empty()) {
        cout << "Warning: Unable to set the Model because it cannot be an empty string!\n";
    }
    else {
        this->model = model;
    }
}

void Truck::setColor(const string& color) {
    if (color.empty()) {
        cout << "Warning: Unable to set the Color because it cannot be an empty string!\n";
    }
    else {
        this->color = color;
    }
}

void Truck::setYearBuilt(int year) {
    if (year < 1900) {
        cout << "Warning: Unable to set the Year because it must be above 1900 or greater!\n";
    }
    else {
        yearBuilt = year;
    }
}

void Truck::setNumberOfDoors(int doors) {
    if (doors <= 0) {
        cout << "Warning: Unable to set the Number or doors because it must be above 0!\n";
    }
    else {
        numberOfDoors = doors;
    }
}

void Truck::setTowingCapacity(const string& towingCap) {
    if (towingCap.empty()) {
        cout << "Warning: Unable to set the Towing Capacity because it cannot be an empty string!\n";
    }
    else {
        towingCapacity = towingCap;
    }
}

void Truck::Print() const {
    cout << "\n\nDerived Class - Truck Information\n";
    cout << "_________________________________\n";
    cout << "Inventory Number: " << getInventoryNumber() << endl;
    cout << "Location        : " << getLocation() << endl;
    cout << "Make            : " << make << endl;
    cout << "Model           : " << model << endl;
    cout << "Color           : " << color << endl;
    cout << "Year            : " << yearBuilt << endl;
    cout << "Number of Doors : " << numberOfDoors << endl;
    cout << "Towing Capacity : " << towingCapacity << endl;
}

int main() {
    // Create instances of Auto, Car, and Truck classes
    Auto autoInstance("BN549", "Nashville");
    Car carInstance("BK576", "Knoxville", "Chevy", "Camaro", "Yellow", 2023, 2, "Leather");
    Truck truckInstance;

    // Set values for Truck instance using dot operator
    truckInstance.setInventoryNumber("BA342");
    truckInstance.setLocation("Ashville");
    truckInstance.setMake("Ford");
    truckInstance.setModel("F350");
    truckInstance.setColor("Red");
    truckInstance.setYearBuilt(2019);
    truckInstance.setNumberOfDoors(4);
    truckInstance.setTowingCapacity("21000");

    // Display program title
    cout << setw(29) << "" << "Class Inheritance Program\n\n";

    // Call Print member function of each instance
    autoInstance.Print();
    carInstance.Print();
    truckInstance.Print();

    return 0;
}