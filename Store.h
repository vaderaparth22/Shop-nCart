#pragma once
#include<iostream>
#include "Product.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace std;
class Store
{

private:
	
public:
	Store (vector<Product*> availableProducts);
	vector<Product*> list_productInStore;
	void addItemToStore(Product* AddProduct);
	void removeItemFromStore(int a);
	void removeAllItemFromStore();
	int  findProductBySerial(int serial);
	Product getProductByIndex(int index);
	int getProductCountInStore();

	//void availableroduct()
	
};




class Cart
{
private:


public:

	Cart();

    vector<Product*> list_productInCart;
	Cart(vector<Product*> list_productInCart);
	void addItemToCart(Product* p);
	void removeItemFromCart(int b);
	void removeAllItemFromCart(Product* removeAllProduct);
	int  findProductBySerial(int serial);
	Product getProductByIndex(int index);
	int getProductCountInCart();
	double getTotalBasePrice();
	double getTotalFinalPrice();
	void checkOut();
};