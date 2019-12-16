#ifndef ITEMTOPURCHASE
#define ITEMTOPURCHASE

#include<iostream>
#include<string>

// Parameterized constructor to assign item name, item description, item price, and item quantity (default values of 0). (1 pt)
// Public member functions
// SetDescription() mutator & GetDescription() accessor (2 pts)
// PrintItemCost() - Outputs the item name followed by the quantity, price, and subtotal
// PrintItemDescription() - Outputs the item name and description
// Private data members
// string itemDescription - Initialized in default constructor to "none"


using namespace std;

class ItemToPurchase {
    private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;
    
    public: 
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);
    void SetName(string input);
    string GetName();
    void SetPrice(int price);
    int GetPrice();
    void SetQuantity(int quantity);
    int GetQuantity();
    void SetDescription(string description);
    string GetDescription();
    void PrintItemCost();
    void PrintItemDescription();
};

#endif
