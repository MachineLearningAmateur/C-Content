#include<iostream>
#include<string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void PrintMenu(ShoppingCart &myCart);
void OutputShopCart(ShoppingCart &myCart);
void OutputItemDesc(ShoppingCart &myCart);
void addItem(ShoppingCart &myCart);
void removeItem(ShoppingCart &myCart);
void changeItem(ShoppingCart &myCart);

int main() {
    string name;
    string date;
    
    cout << "Enter customer's name:" << endl;
    getline(cin, name);
    cout << "Enter today's date:" << endl;
    getline(cin, date);
    cout << endl;
    cout << "Customer name: " << name << endl;
    cout << "Today's date: " << date << endl;
    ShoppingCart myCart(name, date);
    PrintMenu(myCart);

}

void PrintMenu(ShoppingCart &myCart) {
    char choice = 'a';
    bool otherwise = false;
    vector<char> choices {'a', 'd', 'c', 'i', 'o'};
    while (choice != 'q') {
        for (unsigned int i = 0; i < choices.size(); i++) {
            if(choices.at(i) == choice)
                otherwise = true;
        }
        if(otherwise) {
            cout << endl;
            cout << "MENU" << endl;
            cout << "a - Add item to cart" << endl;
            cout << "d - Remove item from cart" << endl;
            cout << "c - Change item quantity" << endl;
            cout << "i - Output items' descriptions" << endl;
            cout << "o - Output shopping cart" << endl;
            cout << "q - Quit" << endl;
            cout << endl;
        }
        cout << "Choose an option:" << endl;
        otherwise = false;
        cin >> choice;
        if (choice == 'o') {
            OutputShopCart(myCart); 
        }
        else if (choice == 'i')
            OutputItemDesc(myCart);
        else if (choice == 'a')
            addItem(myCart);
        else if (choice == 'd')
            removeItem(myCart);
        else if (choice == 'c')
            changeItem(myCart);
            
    }
}

void OutputShopCart(ShoppingCart &myCart) {
    cout << "OUTPUT SHOPPING CART" << endl;
    cout << myCart.GetCustomerName() << "\'s Shopping Cart - " << myCart.GetDate() << endl;
    cout << "Number of Items: " << myCart.GetNumItemsInCart() << endl;
    cout << endl;
    if (myCart.GetNumItemsInCart() == 0)
        cout << "SHOPPING CART IS EMPTY" << endl;
    myCart.PrintItemCost(); 
    cout << endl;
    cout << "Total: $" << myCart.GetCostOfCart() << endl;
}

void OutputItemDesc(ShoppingCart &myCart) {
    cout << "OUTPUT ITEMS\' DESCRIPTIONS" << endl;
    cout << myCart.GetCustomerName() << "\'s Shopping Cart - " << myCart.GetDate() << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    myCart.PrintDescriptions();
}

void addItem(ShoppingCart &myCart) {
    string name;
    string desc;
    int price;
    int quantity;
    cout << "ADD ITEM TO CART" << endl;
    cout << "Enter the item name:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter the item description:" << endl;
    getline(cin, desc);
    cout << "Enter the item price:" << endl;
    cin >> price;
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    
    ItemToPurchase entry(name, desc, price, quantity);
    myCart.AddItem(entry);
}

void removeItem(ShoppingCart &myCart) {
    string entry;
    cout << "REMOVE ITEM FROM CART" << endl;
    cout << "Enter name of item to remove:" << endl;
    cin.ignore();
    getline(cin, entry);
    myCart.RemoveItem(entry);
}

void changeItem(ShoppingCart &myCart) {
    string name;
    int quantity;
    ItemToPurchase yeet;
    cout << "CHANGE ITEM QUANTITY" << endl;
    cout << "Enter the item name:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter the new quantity:" << endl;
    cin >> quantity;
    yeet.SetQuantity(quantity);
    yeet.SetName(name);
    myCart.ModifyItem(yeet);
}