#include "ItemToPurchase.h"

// string itemName - Initialized in default constructor to "none"
// int itemPrice - Initialized in default constructor to 0
// int itemQuantity - Initialized in default constructor to 0


ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
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
