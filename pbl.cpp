// ****************************************************
// Project Title: Employee Management System
// Concept: Inheritance (Employee → Manager / Worker)
// Language: C++
// ****************************************************

#include <iostream>
#include <string>
using namespace std;

// -----------------------------
// Base Class: Employee
// -----------------------------
class Employee {
protected:
    int id;
    string name;
    float salary;

public:
    virtual void getData() {
        cout << "\nEnter Employee ID: ";
        cin >> id;
        cin.ignore(); // Ignore newline left in buffer
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display() const { // Use const because it doesn't modify data
        cout << "\nEmployee ID: " << id;
        cout << "\nEmployee Name: " << name;
        cout << "\nSalary: " << salary;
    }

    virtual ~Employee() {} // Virtual destructor for proper cleanup
};

// -----------------------------
// Derived Class 1: Manager
// -----------------------------
class Manager : public Employee {
    string department;
    int teamSize;

public:
    void getData() override {
        Employee::getData();
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Team Size: ";
        cin >> teamSize;
    }

    void display() const override {
        cout << "\n----- Manager Details -----";
        Employee::display();
        cout << "\nDepartment: " << department;
        cout << "\nTeam Size: " << teamSize;
        cout << "\n---------------------------\n";
    }
};

// -----------------------------
// Derived Class 2: Worker
// -----------------------------
class Worker : public Employee {
    int workingHours;
    float overtimePay;

public:
    void getData() override {
        Employee::getData();
        cout << "Enter Working Hours: ";
        cin >> workingHours;
        cout << "Enter Overtime Pay: ";
        cin >> overtimePay;
    }

    void display() const override {
        cout << "\n----- Worker Details -----";
        Employee::display();
        cout << "\nWorking Hours: " << workingHours;
        cout << "\nOvertime Pay: " << overtimePay;
        cout << "\n--------------------------\n";
    }
};

// -----------------------------
// Main Function
// -----------------------------
int main() {
    int choice;
    char ch;

    cout << "======================================\n";
    cout << "   EMPLOYEE MANAGEMENT SYSTEM (OOP)   \n";
    cout << "======================================\n";

    do {
        cout << "\nSelect Employee Type:";
        cout << "\n1. Manager";
        cout << "\n2. Worker";
        cout << "\nEnter choice (1 or 2): ";
        cin >> choice;

        Employee *emp = nullptr; // Base class pointer initialization

        switch (choice) {
            case 1:
                emp = new Manager;
                break;
            case 2:
                emp = new Worker;
                break;
            default:
                cout << "\nInvalid choice! Please enter 1 or 2.\n";
                continue;
        }

        emp->getData();   // Runtime polymorphism
        emp->display();

        delete emp; // Free memory

        cout << "\nDo you want to add another employee? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    cout << "\nThank you for using Employee Management System!\n";

    return 0;
}
