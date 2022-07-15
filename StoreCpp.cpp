#include "Store.h"



Store::Store(vector<Product*> availableProducts)
{
	Store::list_productInStore = availableProducts;
}


void Store::addItemToStore(Product* AddProduct)
{
	
	Store::list_productInStore.push_back(AddProduct);
}
void Store::removeItemFromStore(int a)
{
	// erase the 6th element
	//myvector.erase(myvector.begin() + 5);
	Store::list_productInStore.erase(list_productInStore.begin()+(a-1));
}
void Store::removeAllItemFromStore()
{
	Store::list_productInStore.clear();

}

int Store::findProductBySerial(int serial)
{
	for (int i = 0; Store::list_productInStore.size() > i; i++) 
	{

		if (Store::list_productInStore[i]->ID == serial) 
		{

			return i+1;

		}
	
	}
	return -1;

}
Product Store::getProductByIndex(int index)
{
	return  *list_productInStore[index];
}



int Store::getProductCountInStore()
{
	return  Store::list_productInStore.size();
}
