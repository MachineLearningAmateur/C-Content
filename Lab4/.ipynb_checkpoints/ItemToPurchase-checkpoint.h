#ifndef ITEMTOPURCHASE
#define ITEMTOPURCHASE 

#include<iostream>
#include<string>

using namespace std;

class ItemToPurchase {
    private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    
    public: 
    ItemToPurchase();
    void SetName(string input);
    string GetName();
    void SetPrice(int price);
    int GetPrice();
    void SetQuantity(int quantity);
    int GetQuantity();
};

#endif
