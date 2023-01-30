#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Client{

    int id;
    string first_name;
    string last_name;
    vector<Product> _cart;

    public:
    //Constructors
    Client();
    Client(int id, string first_name, string last_name);

    //Getters
    int getId();
    string getFirstName();
    string getLastName();
    vector<Product> getCart();

    //Setters
    void setId(int id);
    void setFirstName(string first_name);
    void setLastName(string last_name);
    void setCart(vector<Product> cart);

    //Display
    friend ostream& operator<<(ostream& os, Client client);

    //Methods
    void addProductToCart(Product product, int quantity);
    void clearCart();
    void updateProductQuantityInCart(Product product, int quantity);
    void removeProductFromCart(Product product);
};

//Constructors
Client::Client(){
    this->id = 0;
    this->first_name = "John";
    this->last_name = "Doe";
    this->_cart = std::vector<Product>();
};
Client::Client(int id, string first_name, string last_name){
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->_cart = std::vector<Product>();
};

//Getters
int Client::getId(){
    return this->id;
};
string Client::getFirstName(){
    return this->first_name;
};
string Client::getLastName(){
    return this->last_name;
};
vector<Product> Client::getCart(){
    return this->_cart;
};

//Setters
void Client::setId(int id){
    this->id = id;
};
void Client::setFirstName(string first_name){
    this->first_name = first_name;
};
void Client::setLastName(string last_name){
    this->last_name = last_name;
};
void Client::setCart(vector<Product> cart){
    this->_cart = cart;
};

//Display
ostream& operator<<(ostream& os, Client client){
    os << "Client ID : " << client.getId() << endl;
    os << "First Name : " << client.getFirstName() << endl;
    os << "Last Name : " << client.getLastName() << endl;
    os << "Cart --------- " << endl;
    for(int i = 0; i < (int)client.getCart().size(); i++){
        os << client.getCart()[i] << endl;
    }
    return os;
};

//Methods
void Client::addProductToCart(Product product, int quantity){
    this->_cart.push_back(product);
    this->_cart[this->_cart.size() - 1].setQuantity(quantity);
};
void Client::clearCart(){
    this->_cart.clear();
};
void Client::updateProductQuantityInCart(Product product, int quantity){
    for(int i = 0; i < (int)this->_cart.size(); i++){
        if(this->_cart[i].getTitle() == product.getTitle()){
            this->_cart[i].setQuantity(quantity);
        }
    }
};
void Client::removeProductFromCart(Product product){
    for(int i = 0; i < (int)this->_cart.size(); i++){
        if(this->_cart[i].getTitle() == product.getTitle()){
            this->_cart.erase(this->_cart.begin() + i);
            // on supprime du panier le ième élément correspondant à CE produit
        }
    }
};
