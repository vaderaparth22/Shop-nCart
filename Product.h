#pragma once
#include "LargeLibrary.h"

#include<iostream>
#include<vector>
#include<string>
using std::string;
#pragma region Roundme
double Myround(double x);
#pragma endregion




class Product
{
private:
;
static int nextindex;
              
 static int nextID;
	string prodName ;
	double basePrice;
	string className;
	bool isPurchase;
public:
	int index;
	int ID;
	Product(string prodName, double basePrice, bool isPurchase);
	
	virtual string getProdName();
	virtual double valiadateBasePrice();
	virtual void display(std::vector<Product> product);
	void baseDisplay();
	virtual string classNameFunction();
 	  bool getIsPurchase();
	  void setIsPurchase();
};

