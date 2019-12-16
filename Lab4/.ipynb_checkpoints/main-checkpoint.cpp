#include<iostream>
#include<string>
#include "ItemToPurchase.h"
using namespace std;

// Item 1
// Enter the item name:
// Chocolate Chips
// Enter the item price:
// 3
// Enter the item quantity:
// 1

// Item 2
// Enter the item name:
// Bottled Water
// Enter the item price:
// 1
// Enter the item quantity:
// 10

int main() {
    ItemToPurchase item1;
    ItemToPurchase item2;
    string name;
    int price;
    int quantity;
    int total;
    
    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    cout << "Enter the item price:" << endl;
    cin >> price;
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    
    item1.SetName(name);
    item1.SetPrice(price);
    item1.SetQuantity(quantity);
    
    cout << endl;
    
    cout << "Item 2" << endl;
    cout << "Enter the item name:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter the item price:" << endl;
    cin >> price;
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    
    item2.SetName(name);
    item2.SetPrice(price);
    item2.SetQuantity(quantity);
    
    total = item1.GetQuantity() * item1.GetPrice() + item2.GetQuantity() * item2.GetPrice();
    cout << endl;
//     TOTAL COST
//     Chocolate Chips 1 @ $3 = $3
//     Bottled Water 10 @ $1 = $10
//     Total: $13
    cout << "TOTAL COST" << endl;
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = " << "$" << item1.GetQuantity() * item1.GetPrice() << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = " << "$" << item2.GetQuantity() * item2.GetPrice() << endl;
    cout << endl;
    cout << "Total: $" << total << endl;
}