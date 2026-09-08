#include <iostream>
using namespace std;

class Employee
{
    int id;
    string name;
    string department;
    float baseSalary;

public:

    Employee()
    {
        id = 0;
        name = "Unknown";
        department = "Unknown";
        baseSalary = 0;
    }

    Employee(int i, string n)
    {
        id = i;
        name = n;
        department = "Unknown";
        baseSalary = 0;
    }

    Employee(int i, string n, string d, float salary)
    {
        id = i;
        name = n;
        department = d;
        baseSalary = salary;
    }

    Employee(Employee &e)
    {
        id = e.id;
        name = e.name;
        department = e.department;
        baseSalary = e.baseSalary;
    }

    float calculatePay()
    {
        return baseSalary;
    }

    float calculatePay(float bonus)
    {
        return baseSalary + bonus;
    }

    float calculatePay(int hours, float hourlyRate)
    {
        return baseSalary + (hours * hourlyRate);
    }

    float calculatePay(float bonus, float taxPercentage)
    {
        float tax = (baseSalary + bonus) * taxPercentage / 100;
        return baseSalary + bonus - tax;
    }

    void updateProfile(string d)
    {
        department = d;
    }

    void updateProfile(float salary)
    {
        baseSalary = salary;
    }

    void updateProfile(string d, float salary)
    {
        department = d;
        baseSalary = salary;
    }

    void display()
    {
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Base Salary : " << baseSalary << endl;
    }
};

int main()
{
    Employee e1;
    Employee e2(101, "Divyam");
    Employee e3(102, "Rahul", "IT", 50000);
    Employee e4(e3);

    e1.display();
    cout << endl;

    e2.display();
    cout << endl;

    e3.display();
    cout << endl;

    e4.display();
    cout << endl;

    cout << e3.calculatePay() << endl;
    cout << e3.calculatePay(5000.0f) << endl;
    cout << e3.calculatePay(10, 500.0f) << endl;
    cout << e3.calculatePay(5000.0f, 10.0f) << endl;

    cout << endl;

    e3.updateProfile("HR");
    e3.updateProfile(60000.0f);
    e3.updateProfile("Finance", 70000.0f);

    e3.display();

    return 0;
}
