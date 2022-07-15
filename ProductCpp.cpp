#include "Product.h"


using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::getline;

 
double Myround(double x)
{
	return floor(x * 100 + 0.5) / 100;
}

int Product::nextindex = 0;
int Product::nextID = 1000;
Product::Product(string prodName, double basePrice, bool isPurchase= false)
{
	this->prodName = prodName;
	this->basePrice = basePrice;
	this->isPurchase = isPurchase;
	this->ID = ++nextID;
	this->index = ++nextindex;
}

string Product::getProdName()
{
	return prodName;
}
double Product::valiadateBasePrice()
{
	return Myround(basePrice);
}
string Product::classNameFunction()
{
	return "Product";
}

void Product::baseDisplay()
{ 
	cout << ID <<"\t" << getProdName()<<"\t \t   " << valiadateBasePrice() <<"    \t" << index  <<"\t"<<classNameFunction();
}

bool Product::getIsPurchase()
{
	return isPurchase;
}

void Product::setIsPurchase()
{
	isPurchase = true;
}

void Product::display(std::vector<Product> p)
{

	for (int i = 0; i < p.size(); i++)
	{
		p[i].baseDisplay();
	}
}


