#include <string>
#include <stdio.h>
#include <iostream>
#include <cmath>

#include "Product.cpp"
#include "Client.cpp"
#include "Order.cpp"
#include "Store.cpp"


using namespace std;


void storeManagement(Store store){
    int choiceSM;
    string title, description; int quantity; double price;

    do{
        cout << endl << "Store management - What do you want to do ? " << endl;
                    cout << "1 - Display all products" << endl;
                    cout << "2 - Find a product" << endl;
                    cout << "3 - Add a new product" << endl;
                    cout << "4 - Update product quantity" << endl;
                    cout << "5 - Exit" << endl;
                    
                    cin >> choiceSM;
                    switch(choiceSM){
                        case 1:
                            cout << endl << "All the products of the Store : " << endl;
                            store.displayAllProducts();
                            break;

                        case 2:
                            cout << "Enter the name of the product : " << endl;
                            cin >> title;
                            cout << endl;
                            store.displayOneProduct(title);
                            break;

                        case 3:
                            cout << "Enter the title (string), description (string), quantity (int) and price (double) of the product :" << endl;
                            cin >> title >> description >> quantity >> price;
                            cout << endl;
                            store.addNewProduct(title, description, quantity, price);
                            break;

                        case 4:
                            cout << "Enter the title (string) and the quantity (int) to change" << endl;
                            cin >> title >> quantity;
                            cout << endl;
                            store.productQuantityUpdate(title, quantity);

                            break;

                        case 5:
                            cout << "Store Management - Exit" << endl;
                            break;

                        default:
                            cout << "Please enter a valid choice" << endl;
                            break;
                    }; 
    }while(choiceSM!=5);
};

void clientManagement(Store store){
    int choiceCM, id, quantity; 
    string title, first_name, last_name;
    Client client;
    Order order;

    do{
        cout << endl << "Client management - What do you want to do ? " << endl;
                    cout << "1 - Display all clients" << endl;
                    cout << "2 - Find a client" << endl;
                    cout << "3 - Add a new client" << endl;
                    cout << "4 - Add a product to a client's cart" << endl;
                    cout << "5 - Remove a product from a client's cart" << endl;
                    cout << "6 - Update a product quantity in a client's cart" << endl;
                    cout << "7 - Exit" << endl;
                    
                    cin >> choiceCM;
                    switch(choiceCM){
                        case 1:
                            cout << endl << "All the clients of the Store : " << endl;
                            store.displayAllClients();
                            break;

                        case 2:
                            cout << "Enter the name and id of the client : " << endl;
                            cin >> last_name >> id;
                            cout << endl;
                            store.displayOneClient(last_name, id);
                            break;

                        case 3:
                            cout << "Enter the id (int) , first_name (string) and last-name (string) of the client :" << endl;
                            cin >> id >> first_name >> last_name;
                            cout << endl;
                            client = Client(id, first_name, last_name);
                            store.addNewClient(client);
                            break;

                        case 4:
                            // On ajoute un produit au panier d'un client, on doit donc récupérer le client à partir de son id.
                            // addProductToClientCart(...) se chareg de faire l'ajout -> cf la Classe Store.
                            cout << "Enter the title (string) and quantity (int) of the product to add to the client's cart , and the client's id (Client)" << endl;
                            cin >> title >> quantity >> id;
                            cout << endl;
                            client = store.getOneClient(id);
                            store.addProductToClientCart(title, quantity, client); 
                            cout << quantity << " " << title << " added to the cart of " << client.getFirstName() << " " << client.getLastName() << endl;
                            break;

                        case 5:
                            cout << "Enter the title (string) to remove from the cart and the client's id " << endl;
                            cin >> title >> id;
                            cout << endl;
                            client = store.getOneClient(id);
                            store.removeProductFromClientCart(title, client);
                            break;

                        case 6:
                            cout << "Enter the title (string) and quantity (int) of the product, and the client's id'" << endl;
                            cin >> title >> quantity >> id;
                            cout << endl;
                            client = store.getOneClient(id);
                            store.updateProductQuantityInClientCart(title, quantity, client);
                            break;

                        case 7:
                            cout << "Client Management - Exit" << endl;
                            break;

                        default:
                            cout << "Please enter a valid choice" << endl;
                            break;
                    };
    }while(choiceCM!=7);
};

void orderManagement(Store store){
    int choiceOM, id; 
    string title, first_name, last_name;
    Client client;
    Order order;

    do{
        cout << endl << "Order management - What do you want to do ? " << endl;
                    cout << "1 - Display all orders" << endl;
                    cout << "2 - Find orders of a client" << endl;
                    cout << "3 - validate an order" << endl;
                    cout << "4 - Exit" << endl;
                    
                    cin >> choiceOM;
                    cout << "allo ? : " << endl;
                    switch(choiceOM){
                        case 1:
                            cout << endl << "All the orders of the Store : " << endl;
                            store.displayAllOrders();
                            break;

                        case 2:
                            cout << "Enter the id of the client : " << endl;
                            cin >> id;
                            cout << endl;
                            store.displayOrderOfClient(id);
                            break;

                        case 3:
                            // la nouvelle commande est obtenue à partir du panier du client
                            cout << "Enter the id (int) of the client to validate the cart : " << endl;
                            cin >> id;
                            cout << endl;
                            client = store.getOneClient(id);
                            store.validateOrder(client); 
                            break;

                        case 4:
                            cout << "Order Management - Exit" << endl;
                            break;

                        default:
                            cout << "Please enter a valid choice" << endl;
                            break;
                    };
    }while(choiceOM!=4);
};

int main(){

    Store store = Store();
    //Ajout de quelques produits
    store.addNewProduct("Banana", "A yellow fruit", 10, 1.5);
    store.addNewProduct("PS5", "A gaming console", 10, 500);
    store.addNewProduct("toilet_paper", "Soft and fluffy - 6 rolls", 100, 1.5);

    //Ajout de quelques clients
    Client client1 = Client(1, "Geralt", "of_Rivia");
    Client client2 = Client(2, "Han", "Solo");
    Client client3 = Client(3, "Tyler", "Durden");

    store.addNewClient(client1);
    store.addNewClient(client2);
    store.addNewClient(client3);

    store.addProductToClientCart("Banana", 2, client1);
    store.addProductToClientCart("PS5", 1, client2);
    store.addProductToClientCart("toilet_paper", 1, client3);

    int choice;

    do{
        cout << endl << "Hello , what do you want to do ?" << endl;
        cout << "1 - Store management" << endl;
        cout << "2 - Client management" << endl;
        cout << "3 - Order management" << endl;
        cout << "4 - Exit" << endl;

        cin >> choice;
        switch(choice){
            case 1:
                storeManagement(store);
                break;

            case 2:
                clientManagement(store);
                break;

            case 3:
                orderManagement(store);
                break;

            case 4:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Please enter a valid choice" << endl;
                break;
        };
        cout << 12 << endl;
    }while(choice!=4);

    return 0;
};

// --------------- A améliorer/ A ajouter ---------------- //

// on peut aussi faire des petites vérifications comme savoir si les quantités ou les prix sont bien positifs, etc.
// les noms/descriptions doivent être attachés par un _ et non un espace, (appel avec cin...).
// Cela reste du détail qui ne gêne aucunement le fonctionnement du programme (si pris en compte) car il ne change en rien les idées derrière le code.

// vérifier qu'on entre bien des booléens valides pour le statut de la commande (true ou false).
// les méthodes simulant le menu peuvent être intégrer dans une classe "Menu" qui gère les différents menus du programme (nécessitant un Store).
// Le but était surtout de travailler sur le fonctionnement du magasin, pas nécessairement sur le menu.
// Parfois certaines méthodes n'utilisent pas les getters/setters, mais c'est pour des raisons de simplicité et de lisibilité du code.


// --------------- Pistes de continuation --------------- //

// Dernière question subisidiaire non réalisée : enregistrement et lecture des données dans un fichier texte (pour pouvoir les récupérer et les réutiliser lors d'un prochain lancement du programme).
