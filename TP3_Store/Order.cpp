#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Order{

    Client client;
    vector<Product> productsToBuy;
    bool isDelivered;

    public:
    //Constructors
    Order();
    Order(Client client, vector<Product> productsToBuy, bool isDelivered);

    //Getters
    Client getClient();
    vector<Product> getProductsToBuy();
    bool getIsDelivered();

    //Setters
    void setClient(Client client);
    void setProductsToBuy(vector<Product> productsToBuy);
    void setIsDelivered(bool isDelivered);

    //Display
    friend ostream& operator<<(ostream& os, Order order);

    //Methods

};

//Constructors
Order::Order(){
    this->client = Client();
    this->productsToBuy = vector<Product>();
    this->isDelivered = false;
};
Order::Order(Client client, vector<Product> productsToBuy, bool isDelivered){
    this->client = client;
    this->productsToBuy = productsToBuy;
    this->isDelivered = isDelivered;
};

//Getters
Client Order::getClient(){
    return this->client;
};
vector<Product> Order::getProductsToBuy(){
    return this->productsToBuy;
};
bool Order::getIsDelivered(){
    return this->isDelivered;
};

//Setters
void Order::setClient(Client client){
    this->client = client;
};
void Order::setProductsToBuy(vector<Product> productsToBuy){
    this->productsToBuy = productsToBuy;
};
void Order::setIsDelivered(bool isDelivered){
    this->isDelivered = isDelivered;
};

//Display
ostream& operator<<(ostream& os, Order order){
    os << "Client : " << order.client << endl;
    os << "Order Products --------- " << endl;
    for(int i = 0; i < (int)order.productsToBuy.size(); i++){
        os << order.productsToBuy[i] << endl;
    }
    if(order.getIsDelivered()){
        os << "Is delivered : Yes" << endl;
    }else{
        os << "Is delivered : No" << endl;
    };
    return os;
};