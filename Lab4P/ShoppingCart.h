#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
#include <vector>
#include <iostream>
#include "ItemToPurchase.h"

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
class ShoppingCart {
    private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
    
    public:
    ShoppingCart();
    ShoppingCart(string name, string date);
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart();
    void PrintTotal();
    void PrintDescriptions();
    void PrintItemCost();
    int GetCostOfCart();

};

#endif