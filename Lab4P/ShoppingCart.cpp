#include "ShoppingCart.h"
//string customerName;
// string currentDate;
// vector <ItemToPurchase> cartItems;
// Default constructor
// Parameterized constructor which takes the customer name and date as parameters (1 pt)
// Private data members
// string customerName - Initialized in default constructor to "none"
// string currentDate - Initialized in default constructor to "January 1, 2016"
// vector < ItemToPurchase > cartItems
// Public member functions
// GetCustomerName() accessor (1 pt)
// GetDate() accessor (1 pt)
// AddItem()
// Adds an item to cartItems vector. Has parameter ItemToPurchase. Does not return anything.
// RemoveItem()
// Removes item from cartItems vector. Has a string (an item's name) parameter. Does not return anything.
// If item name cannot be found, output this message: Item not found in cart. Nothing removed.
// ModifyItem()
// Modifies an item's description, price, and/or quantity. Has parameter ItemToPurchase. Does not return anything.
// If item can be found (by name) in cart, check if parameter has default values for description, price, and quantity. If not, modify item in cart.
// If item cannot be found (by name) in cart, output this message: Item not found in cart. Nothing modified.
// GetNumItemsInCart() (2 pts)
// Returns quantity of all items in cart. Has no parameters.
// GetCostOfCart() (2 pts)
// Determines and returns the total cost of items in cart. Has no parameters.
// PrintTotal()
// Outputs total of objects in cart.
// If cart is empty, output this message: SHOPPING CART IS EMPTY
// PrintDescriptions()
// Outputs each item's description.

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date; 
}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}
    
void ShoppingCart::AddItem(ItemToPurchase newItem) {
    cartItems.push_back(newItem);
}

void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == itemName) {
            cartItems.erase(cartItems.begin() + i);
            found = true;
        }
    }
    if (!found)
        cout << "Item not found in cart. Nothing removed." << endl;
        
}
void ShoppingCart::ModifyItem(ItemToPurchase item) {
    bool found = false;
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            if(item.GetQuantity() != 0){
                cartItems.at(i).SetQuantity(item.GetQuantity());
            }
            found = true;
        }
    }
    if (!found)
        cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() {
    int total = 0;
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        total = total + cartItems.at(i).GetQuantity();
    }
    return total;
}

void ShoppingCart::PrintTotal() {
    if (cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else
        cout << cartItems.size() << endl;
}

void ShoppingCart::PrintDescriptions() {
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        cartItems.at(i).PrintItemDescription();
    }
}

void ShoppingCart::PrintItemCost() {
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        cartItems.at(i).PrintItemCost();
    }
}

int ShoppingCart::GetCostOfCart() {
    int totalCost = 0;
    for (unsigned int i = 0; i < cartItems.size(); i++) {
       totalCost = totalCost + cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
    }
    return totalCost;
}