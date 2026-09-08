#include <iostream>
using namespace std;

enum Category
{
    ELECTRONICS,
    CLOTHING,
    FOOD
};

enum OrderStatus
{
    CREATED,
    CONFIRMED,
    CANCELLED,
    DELIVERED
};

enum PaymentStatus
{
    PENDING,
    SUCCESS,
    FAILED
};

enum PaymentMethod
{
    CREDIT_CARD,
    UPI,
    CASH
};

union PaymentInfo
{
    int last4;
    string upiId;
};

class Product
{
    int productId;
    string name;
    float price;
    int stock;
    Category category;

public:

    Product(int id, string n, float p, int s, Category c)
    {
        productId = id;
        name = n;
        price = p;
        stock = s;
        category = c;
    }

    void displayProduct()
    {
        cout << "Product ID : " << productId << endl;
        cout << "Name : " << name << endl;
        cout << "Price : " << price << endl;
        cout << "Stock : " << stock << endl;
    }

    void updateStock(int s)
    {
        stock = stock + s;
    }

    bool checkAvailability(int quantity)
    {
        if(stock >= quantity)
            return true;
        else
            return false;
    }

    int getId()
    {
        return productId;
    }

    float getPrice()
    {
        return price;
    }

    void removeStock(int quantity)
    {
        stock = stock - quantity;
    }
};

class Customer
{
    int customerId;
    string name;
    string email;
    string phone;
    string address;

public:

    Customer(int id, string n, string e, string p, string a)
    {
        customerId = id;
        name = n;
        email = e;
        phone = p;
        address = a;
    }

    void displayCustomer()
    {
        cout << "Customer ID : " << customerId << endl;
        cout << "Name : " << name << endl;
        cout << "Email : " << email << endl;
        cout << "Phone : " << phone << endl;
        cout << "Address : " << address << endl;
    }

    void updateCustomer(string e, string p, string a)
    {
        email = e;
        phone = p;
        address = a;
    }

    int getId()
    {
        return customerId;
    }
};

struct Order
{
    int orderId;
    int customerId;
    float totalAmount;

    OrderStatus orderStatus;
    PaymentStatus paymentStatus;

    PaymentMethod paymentMethod;
    PaymentInfo paymentInfo;

    Order(int id, int cid, float amount)
    {
        orderId = id;
        customerId = cid;
        totalAmount = amount;

        orderStatus = CREATED;
        paymentStatus = PENDING;
        paymentMethod = CASH;
    }

    void displayOrder()
    {
        cout << "Order ID : " << orderId << endl;
        cout << "Customer ID : " << customerId << endl;
        cout << "Total Amount : " << totalAmount << endl;

        cout << "Order Status : ";

        if(orderStatus == CREATED)
            cout << "Created";
        else if(orderStatus == CONFIRMED)
            cout << "Confirmed";
        else if(orderStatus == CANCELLED)
            cout << "Cancelled";
        else
            cout << "Delivered";

        cout << endl;

        cout << "Payment Status : ";

        if(paymentStatus == PENDING)
            cout << "Pending";
        else if(paymentStatus == SUCCESS)
            cout << "Success";
        else
            cout << "Failed";

        cout << endl;
    }

    void updateOrder(float amount)
    {
        totalAmount = amount;
        cout << "Order Updated" << endl;
    }

    void confirmOrder()
    {
        if(orderStatus == CANCELLED)
        {
            cout << "Cancelled order cannot be confirmed" << endl;
        }
        else if(paymentStatus != SUCCESS)
        {
            cout << "Payment failed. Order cannot be confirmed" << endl;
        }
        else
        {
            orderStatus = CONFIRMED;
            cout << "Order Confirmed" << endl;
        }
    }

    void cancelOrder()
    {
        if(orderStatus == DELIVERED)
        {
            cout << "Delivered order cannot be cancelled" << endl;
        }
        else
        {
            orderStatus = CANCELLED;
            cout << "Order Cancelled" << endl;
        }
    }
};

int main()
{
    Product p1(101, "Laptop", 50000, 5, ELECTRONICS);

    Customer c1(1, "Divyam", "divyam@gmail.com",
                "9876543210", "Punjab");

    cout << "----- PRODUCT -----" << endl;
    p1.displayProduct();

    cout << endl;

    cout << "----- CUSTOMER -----" << endl;
    c1.displayCustomer();

    cout << endl;

    int quantity = 2;

    if(p1.checkAvailability(quantity))
    {
        cout << "Product Available" << endl;

        float total = p1.getPrice() * quantity;

        p1.removeStock(quantity);

        Order o1(1001, c1.getId(), total);

        cout << endl;

        cout << "----- ORDER -----" << endl;
        o1.displayOrder();

        cout << endl;

        o1.paymentMethod = UPI;
        o1.paymentInfo.upiId = "divyam@upi";
        o1.paymentStatus = SUCCESS;

        o1.confirmOrder();

        cout << endl;

        o1.displayOrder();

        cout << endl;

        o1.updateOrder(90000);

        cout << endl;

        o1.cancelOrder();
    }
    else
    {
        cout << "Product is out of stock" << endl;
    }

    cout << endl;

    cout << "----- INVALID CASES -----" << endl;

    Product p2(102, "Mobile", 20000, 2, ELECTRONICS);

    if(!p2.checkAvailability(10))
    {
        cout << "1. Product out of stock" << endl;
    }

    cout << "2. Invalid Product ID" << endl;

    cout << "3. Invalid Customer ID" << endl;

    Order o2(1002, 1, 5000);

    o2.orderStatus = DELIVERED;

    o2.cancelOrder();

    Order o3(1003, 1, 3000);

    o3.orderStatus = CANCELLED;

    cout << "5. Payment for cancelled order is not allowed" << endl;

    Order o4(1004, 1, 4000);

    o4.paymentStatus = FAILED;

    o4.confirmOrder();

    return 0;
}
