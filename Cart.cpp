#include "Store.h"

Cart::Cart(vector<Product*> list_productInCart)
{
	list_productInCart = list_productInCart;
}


Cart::Cart()
{
}

void Cart::addItemToCart(Product* p)
{
	Cart::list_productInCart.push_back(p);

}

void Cart::removeItemFromCart(int b)
{
	
		Cart::list_productInCart.erase(list_productInCart.begin() + (b - 1));

	
}

void Cart::removeAllItemFromCart(Product* removeAllProduct)
{
	Cart::list_productInCart.clear();
}

int Cart::findProductBySerial(int serial)
{
	for (int i = 0; Cart::list_productInCart.size() > i; i++)
	{

		if (Cart::list_productInCart.at(i)->ID == serial) {

			return i;

		}
		else {
			return -1;
		}
	}
	return -1;
}

Product Cart::getProductByIndex(int index)
{
	return  *list_productInCart[index];
}

int Cart::getProductCountInCart()
{
	return  Cart::list_productInCart.size();
}

double Cart::getTotalBasePrice()
{
	double basePrice = 0;
	for (int i = 0; list_productInCart.size() > i; i++)
	{
		basePrice+= Cart::list_productInCart.at(i)->valiadateBasePrice();
	}
	
	return Myround(basePrice);
}

double Cart::getTotalFinalPrice()
{
	double finalPrice = 0;
	for (int i = 0; list_productInCart.size() > i; i++)
	{
		finalPrice +=  ( Cart::list_productInCart.at(i)->valiadateBasePrice() * 1.15 ) ;
	}
	return Myround(finalPrice);
}


void Cart::checkOut()
{

	for (int i = 0; list_productInCart.size() > i; i++)
	{
		Cart::list_productInCart.at(i)->setIsPurchase();
	}
	Cart::list_productInCart.clear();



}