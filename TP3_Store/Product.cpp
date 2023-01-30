#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Product{
    string title;
    string description;
    int quantity;
    double price;

    public:
    //Constructors
    Product();
    Product(string title, string description, int quantity, double price);

    //Getters
    string getTitle();
    string getDescription();
    int getQuantity();
    double getPrice();

    //Setters
    void setTitle(string title);
    void setDescription(string description);
    void setQuantity(int quantity);
    void setPrice(double price);

    //Display
    friend ostream& operator<<(ostream& os, Product product);

    //Methods
    
};

//Constructors
Product::Product(){
    this->title = "";
    this->description = "";
    this->quantity = 0;
    this->price = 0.0;
};
Product::Product(string title, string description, int quantity, double price){
    this->title = title;
    this->description = description;
    this->quantity = quantity;
    this->price = price;
};

//Getters
string Product::getTitle(){
    return this->title;
};
string Product::getDescription(){
    return this->description;
};
int Product::getQuantity(){
    return this->quantity;
};
double Product::getPrice(){
    return this->price;
};

//Setters
void Product::setTitle(string title){
    this->title = title;
};
void Product::setDescription(string description){
    this->description = description;
};
void Product::setQuantity(int quantity){
    this->quantity = quantity;
};
void Product::setPrice(double price){
    this->price = price;
};

//Display
ostream& operator<<(ostream& os, Product product){
    os << "Title : " << product.title << endl;
    os << "Description : " << product.description << endl;
    os << "Quantity : " << product.quantity << endl;
    os << "Price : " << product.price << " euros" << endl;
    return os;
};
