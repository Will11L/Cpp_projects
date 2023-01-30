#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Store{

    std::vector<Product> _products;
    std::vector<Client> _clients;
    std::vector<Order> _orders;
    
    public:
    
    //Constructors
    Store();
    Store(vector<Product> products, vector<Client> clients, vector<Order> orders);

    //Getters
    vector<Product> getProducts();
    vector<Client> getClients();
    vector<Order> getOrders();

    //Setters
    void setProducts(vector<Product> products);
    void setClients(vector<Client> clients);
    void setOrders(vector<Order> orders);

    //Display
    void displayAllProducts();
    void displayOneProduct(string title);

    void displayAllClients(); // Question 5 : ajouts de fonctionnalités à Magasin
    void displayOneClient(string name, int id); // Question 5 : ajouts de fonctionnalités à Magasin

    void displayAllOrders(); // Question 7 : ajouts de fonctionnalités à Magasin
    void displayOrderOfClient(int id); // Question 7 : ajouts de fonctionnalités à Magasin

    //Methods
    void addProduct(Product product);
    void addNewProduct(string title, string description, int quantity, double price);
    void productQuantityUpdate(string title, int quantity);

    void addNewClient(Client client); // Question 5 : ajouts de fonctionnalités à Magasin
    void addProductToClientCart(string title, int quantity, Client& client);
    void removeProductFromClientCart(string title, Client& client);
    void updateProductQuantityInClientCart(string title, int quantity, Client& client);

    void validateOrder(Client& client);  // Question 7 : ajouts de fonctionnalités à Magasin
    void updateOrderStatus(Order& order, bool status); // Question 7 : ajouts de fonctionnalités à Magasin

    Client getOneClient(int id);    // obtenir un client à partir de son id
    Order getOneOrder(int id);      // obtenir une commande à partir d'un client (id)
};

//Constructors
Store::Store(){
    this->_products = std::vector<Product>();

    this->_clients = std::vector<Client>();

    this->_orders = std::vector<Order>();
};
Store::Store(vector<Product> products, vector<Client> clients, vector<Order> orders){
    this->_products = products;
    this->_clients = clients;
    this->_orders = orders;
};

//Getters
vector<Product> Store::getProducts(){
    return this->_products;
};
vector<Client> Store::getClients(){
    return this->_clients;
};
vector<Order> Store::getOrders(){
    return this->_orders;
};

//Setters
void Store::setProducts(vector<Product> products){
    this->_products = products;
};
void Store::setClients(vector<Client> clients){
    this->_clients = clients;
};
void Store::setOrders(vector<Order> orders){
    this->_orders = orders;
};

//Display
void Store::displayAllProducts(){
    for(int i = 0; i < (int)this->_products.size(); i++){
        cout << this->_products[i] << endl;
    };
};
void Store::displayOneProduct(string title){
    bool found = false;
    for(int i = 0; i < (int)this->_products.size(); i++){
        if(this->_products[i].getTitle() == title){
            cout << this->_products[i] << endl;
            found = true;
        }
    };
    if(found == false){
        cout << "There is no product with that title." << endl;
    };
};

void Store::displayAllClients(){ // Question 5 : ajouts de fonctionnalités à Magasin
    cout << "Clients: " << endl;
    for(int i = 0; i < (int)this->_clients.size(); i++){
        cout << this->_clients[i] << endl;
    };
};
void Store::displayOneClient(string name, int id){ // Question 5 : ajouts de fonctionnalités à Magasin
    bool found = false;
    for(int i = 0; i < (int)this->_clients.size(); i++){
        if(this->_clients[i].getLastName() == name || this->_clients[i].getId() == id){
            cout << this->_clients[i] << endl;
            found = true;
        };
    };
    if(found == false){
        cout << "There is no client with that name or id." << endl;
    };
};

void Store::displayAllOrders(){ // Question 7 : ajouts de fonctionnalités à Magasin
    cout << "Orders --------- " << endl;
    for(int i = 0; i < (int)this->_orders.size(); i++){
        cout << this->_orders[i] << endl;
    };
};
void Store::displayOrderOfClient(int id){ // Question 7 : ajouts de fonctionnalités à Magasin
    int cpt = 1;
    for(int i = 0; i < (int)this->_orders.size(); i++){
        if(this->_orders[i].getClient().getId() == id){
            cout << "Order n°" << cpt << " for Client n° : "<< this->_orders[i].getClient().getId() << " "<< endl;
            cout << this->_orders[i] << endl;
        }
        else{
            cout << "There is no order for that client." << endl;
        };
    };
};

//Methods
void Store::addProduct(Product product){    // fonction basique, pas utilisée réellement -> voir addNewProduct(...)
    this->_products.push_back(product);
};
void Store::addNewProduct(string title, string description, int quantity, double price){
    bool alreadyHere = false;
    for(int i = 0; i < (int)this->_products.size(); i++){
        if(this->_products[i].getTitle() == title){
            cout << "this product is already here" << endl;
            this->_products[i].setQuantity(this->_products[i].getQuantity()+quantity);
            alreadyHere = true;
        };
    };
    if(alreadyHere == false){
        Product product = Product(title, description, quantity, price);
        this->_products.push_back(product);
    };
};
void Store::productQuantityUpdate(string title, int quantity){
    bool found = false;
    for(int i = 0; i < (int)this->_products.size(); i++){
        if(this->_products[i].getTitle() == title){
            this->_products[i].setQuantity(quantity);
            found = true;
        };
    };
    if(found == false){
        cout << "There is no product with that title." << endl;
    };

};

void Store::addNewClient(Client client){   // Question 5 : ajouts de fonctionnalités à Magasin
    this->_clients.push_back(client);
};
void Store::addProductToClientCart(string title, int quantity, Client& client){
    bool foundClient = false;
    bool foundProduct = false;
    for(int i = 0; i < (int)this->_clients.size(); i++){
        if(this->_clients[i].getId() == client.getId()){
            foundClient = true;
            for(int j = 0; j < (int)this->_products.size(); j++){
                if(this->_products[j].getTitle() == title){
                    this->_clients[i].addProductToCart(this->_products[j], quantity);
                    client.addProductToCart(this->_products[j], quantity);
                    foundProduct = true;
                };
            };
        }
    };
    if(foundClient == false){
        cout << "There is no client with that id." << endl;
    };
    if(foundProduct == false){
        cout << "There is no product with that title." << endl;
    };
};
void Store::removeProductFromClientCart(string title, Client& client){
    bool foundClient = false;
    bool foundProduct = false;
    for(int i = 0; i < (int)this->_clients.size(); i++){
        if(this->_clients[i].getId() == client.getId()){
            foundClient = true;
            for(int j = 0; j < (int)this->_products.size(); j++){
                if(this->_products[j].getTitle() == title){
                    this->_clients[i].removeProductFromCart(this->_products[j]);
                    client.removeProductFromCart(this->_products[j]);
                    foundProduct = true;
                };
            };
        }
    };
    if(foundClient == false){
        cout << "There is no client with that id." << endl;
    };
    if(foundProduct == false){
        cout << "There is no product with that title." << endl;
    };
};
void Store::updateProductQuantityInClientCart(string title, int quantity, Client& client){
    bool foundClient = false;
    bool foundProduct = false;
    for(int i = 0; i < (int)this->_clients.size(); i++){
        if(this->_clients[i].getId() == client.getId()){
            foundClient = true;
            for(int j = 0; j < (int)this->_products.size(); j++){
                if(this->_products[j].getTitle() == title){
                    this->_clients[i].updateProductQuantityInCart(this->_products[j], quantity);
                    client.updateProductQuantityInCart(this->_products[j], quantity);
                    foundProduct = true;
                };
            };
        }
    };
    if(foundClient == false){
        cout << "There is no client with that id." << endl;
    };
    if(foundProduct == false){
        cout << "There is no product with that title." << endl;
    };
};

void Store::validateOrder(Client& client){  // Question 7 : ajouts de fonctionnalités à Magasin
    bool orderIsValid = true;
    Order currentOrder = Order();

    bool foundClient = false;
    for(int i = 0; i < (int)this->_clients.size(); i++){
        if(this->_clients[i].getId() == client.getId()){
            currentOrder.setClient(this->_clients[i]);
            foundClient = true;
        };
    };
    if(foundClient == false){
        cout << "There is no client with that id." << endl;
        orderIsValid = false;
    };

    if(client.getCart().size() > 0){
        for (int i = 0; i < (int)client.getCart().size(); i++){
            for (int j = 0; j < (int)this->_products.size(); j++){
                if(client.getCart()[i].getTitle() == this->_products[j].getTitle()){
                    if(client.getCart()[i].getQuantity() >= this->_products[j].getQuantity()){
                        orderIsValid = false;
                        cout << "There is not enough quantity of " << client.getCart()[i].getTitle() << " in the store." << endl;
                    };
                };
            };
        };
    }
    else{
        orderIsValid = false;
        cout << "The cart is empty." << endl;
    };

    if(orderIsValid == true){
        cout << "The order is valid." << endl;
        updateOrderStatus(currentOrder, true);
        for(int i = 0; i < (int)getClients().size(); i++){
            if(getClients()[i].getId() == client.getId()){
                for(int j = 0; j < (int)client.getCart().size(); j++){
                    for(int k = 0; k < (int)this->_products.size(); k++){
                        if(client.getCart()[j].getTitle() == this->_products[k].getTitle()){
                            this->_products[k].setQuantity(this->_products[k].getQuantity() - client.getCart()[j].getQuantity());
                        };
                    };
                };
            };
        };
        getOneClient(client.getId()).clearCart();
        // ----------------------------------- //
        // Codes pour Virements, Banques, etc.
        // ----------------------------------- //
        cout << "Transaction done." << endl;
    };

    // Quelle que soit la validité de la commande, elle est ajoutée à l'historique des commandes.
    // A l'aide d'autres méthodes à implémenter, un caissier peut ainsi supprimer un produit de la commande et la refaire valider par la suite.
    this->_orders.push_back(currentOrder);

};

void Store::updateOrderStatus(Order& order, bool status){
    order.setIsDelivered(status);
};

Client Store::getOneClient(int id){
    bool found = false;
    for(int i = 0; i < (int)this->_clients.size(); i++){
        if(this->_clients[i].getId() == id){
            return this->_clients[i];
            found = true;
        };
    };
    if(found == false){
        cout << "There is no client with that id." << endl;
    };
    return Client();
    // return un client vide si non trouvé, le reste du code comprendra et signalera que le client n'existe pas.
};

Order Store::getOneOrder(int id){
    bool found = false;
    for(int i = 0; i < (int)this->_orders.size(); i++){
        if(this->_orders[i].getClient().getId() == id){
            return this->_orders[i];
            found = true;
        };
    };
    if(found == false){
        cout << "There is no order for that client." << endl;
    };
    return Order();
    // return une commande vide si non trouvée, le reste du code comprendra et signalera que la commande n'existe pas.
};

// Améliorations : effectuer la vérification de la transaction. Banque... etc.
// On peut aussi faire des petites vérifications comme savoir si les quantités ou les prix sont bien positifs, etc.