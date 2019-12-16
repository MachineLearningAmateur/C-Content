#include "ItemToPurchase.h"

// string itemName - Initialized in default constructor to "none"
// int itemPrice - Initialized in default constructor to 0
// int itemQuantity - Initialized in default constructor to 0


ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = -1;
    itemQuantity = -1;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemPrice = price;
    itemDescription = description;
    itemQuantity = quantity; 
}

string ItemToPurchase::GetName() {
    return itemName; 
}
void ItemToPurchase::SetName(string input) {
    itemName = input;
}


void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

// Ex. of PrintItemCost() output:

// Bottled Water 10 @ $1 = $10

// Ex. of PrintItemDescription() output:

// Bottled Water: Deer Park, 12 oz.

void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl; 
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}