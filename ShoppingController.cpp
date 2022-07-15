#include "ShoppingController.h"
using std::vector;
Cart sh_cart = Cart();
Product* p1 = new Product("White T Shirt", 23.162, 0);
Product* p2 = new Product("Red T Shirt", 34.577, 0);
Product* p3 = new Product("Yellow T Shirt", 24.9876, 0);
Product* p4 = new Product("Blue T Shirt", 12.45556, 0);
Product* p5 = new Product("Green T Shirt", 11.55556, 0);
Product* p6 = new Product("NoColor T Shirt", 8.48556, 0);
Product* p7 = new Product("Cobra T Shirt", 2.1256, 0);
vector<Product*> list{p1,p2,p3,p4,p5,p6,p7};
Store s1 = Store(list);
Cart c1 = Cart();
Date d1 = Date();
Passport pass = Passport();
//cart function calling
void ca()
{
	vector<string> MenuOptions = { "View items in the cart","Return an item to the shelf ","Go back" };
	ConsoleMenu mainMenu = ConsoleMenu("Cart", "Please Choose From Option Above", MenuOptions);
	int userSelection;
	int a;
	do
	{
		userSelection = mainMenu.displayAndGetSelection();
		switch (userSelection)
		{
		case 1: 
			for (int i = 0; i < c1.list_productInCart.size(); i++)
			{
				c1.list_productInCart[i]->baseDisplay();
				cout << "\n";
			}
			
			break;

		case 2:
			if (c1.list_productInCart.size() == 0)
			{
				cout << "There is Nothing in the Cart";
			}
			else
			{
				a = readInt(1, c1.list_productInCart.size(), "Enter The items You want to add to Cart , Must Enter The Index") - 1;
				if (c1.list_productInCart[a]->index != a)
				{
					s1.addItemToStore(c1.list_productInCart[a]);
					c1.removeItemFromCart(a + 1);
				}
			}


			break;
		case 3: cout << "Going back " << endl;
			return;

		}
	} while (true);

}
//store function calling
void sto()
{
	vector<string> MenuOptions = { "View available items in the store","Place an item in the cart ","Add All the Items In the Cart","View Item By Index","Total Products In The Store","Go back" };
	ConsoleMenu mainMenu = ConsoleMenu("Store", "Please Choose From Option Above", MenuOptions);
	int userSelection;
	int a;
	int serialNumber;
	do
	{
		userSelection = mainMenu.displayAndGetSelection();
		
		switch (userSelection)
		{
		case 1: 
					cout << "ID" << "\t" << "Product Name "  << "\t \tBase Price"  << "    Index" << "     Poduct Type\n" ;
					for (int i = 0; i < s1.list_productInStore.size(); i++)
					{
						s1.list_productInStore[i]->baseDisplay();
						cout << "\n";
					}
			break;
		case 2: 
			 a= readInt(1, s1.list_productInStore.size(), "Enter The items You want to add to Cart , Must Enter The Index")-1;
			 if (s1.list_productInStore[a]->index != a)
			 {
				
				 c1.addItemToCart(s1.list_productInStore[a]);
				 s1.removeItemFromStore(a+1);
			 }
			 
			break;
		case 3: 
			for (int i = 0; i < s1.list_productInStore.size(); i++)
				{
		
					c1.addItemToCart(s1.list_productInStore[i]);
					
				}
			s1.removeAllItemFromStore();
			break;
		case 4:
			cout << "Enter The Product Serial Number That You Are looking For\n";
			cin >> serialNumber;
			if (s1.findProductBySerial(serialNumber) == -1)
			{
				cout << "No Poduct With Such a Serial Number\n";
			  }
			else
			{
				cout << "Product Found At: " << s1.findProductBySerial(serialNumber) << " Index\n";
			}
			break;
		case 5: 
			cout <<"Total Products in the Store: " <<  s1.getProductCountInStore() << endl;
			break;
		case 6:
			break;

		}
	} while (userSelection !=6);

}
void Checkout()
{
	pass.setFullName() = "Parth Vadera";
	cout <<"Dear "<<pass.getFullName()<<" Your bill is " << c1.getTotalBasePrice()<<"\n";
	cout << "With Additional Charges Like GST and QST You Have To pay: " << c1.getTotalFinalPrice() << "\n";
	cout << "Payment done on \t";
	d1.getToday().display();

}

void ShoppingController::runMyProgram()
{
	
	vector<string> MenuOptions = { "Manage cart","shop","Check out (Purchase everything in the cart and leave" };
	ConsoleMenu mainMenu = ConsoleMenu("Main Menu", "Please Choose From Option Above", MenuOptions);
	int userSelection;
	
	do
	{
		userSelection = mainMenu.displayAndGetSelection();
		
		switch (userSelection)
		{
		case 1: ca();
			break;
		case 2: sto();
			break;
		case 3: Checkout();
			break;
		
		}
	} while (userSelection!=3);
}


