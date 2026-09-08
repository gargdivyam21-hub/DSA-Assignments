#include <iostream>
using namespace std;

class GPayUser
{
    int id;
    string name;
    string phone;
    float balance;

public:

    GPayUser()
    {
        id = 0;
        name = "Unknown";
        phone = "0000000000";
        balance = 0;
    }

    GPayUser(int i, string n, string p, float b)
    {
        id = i;
        name = n;
        phone = p;
        balance = b;
    }

    ~GPayUser()
    {
        cout << name << " account closed" << endl;
    }

    void setName(string n)
    {
        name = n;
    }

    void setPhone(string p)
    {
        phone = p;
    }

    void setBalance(float b)
    {
        balance = b;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getPhone()
    {
        return phone;
    }

    float getBalance()
    {
        return balance;
    }

    void display()
    {
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Phone : " << phone << endl;
        cout << "Balance : " << balance << endl;
    }

    void addMoney(float amount)
    {
        balance = balance + amount;
    }

    void sendMoney(GPayUser &user, float amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid amount" << endl;
        }
        else if(balance < amount)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            balance = balance - amount;
            user.balance = user.balance + amount;

            cout << name << " sent " << amount
                 << " to " << user.name << endl;

            cout << "Payment Successful" << endl;
        }
    }
};

int main()
{
    GPayUser user1(1, "Divyam", "9876543210", 10000);
    GPayUser user2(2, "Rahul", "9876500000", 5000);
    GPayUser user3(3, "Aman", "9876511111", 8000);
    GPayUser user4(4, "Rohan", "9876522222", 3000);
    GPayUser user5(5, "Karan", "9876533333", 7000);

    cout << " ----- USER 1 -----" << endl;
    user1.display();

    cout << endl;

    cout << "----- USER 2 -----" << endl;
    user2.display();

    cout << endl;

    cout << "----- PAYMENT -----" << endl;

    user1.sendMoney(user2, 2000);

    cout << endl;

    cout << "----- AFTER PAYMENT -----" << endl;

    cout << "Divyam Balance : " << user1.getBalance() << endl;
    cout << "Rahul Balance : " << user2.getBalance() << endl;

    return 0;
}
