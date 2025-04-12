#include <cstddef>
#include <iostream>
#include "Header.h"
#include <iomanip>

using namespace std;



void printMenu() {
	cout << endl;
	cout << "Please Maximize the Window :)" <<endl;
	cout << "\t\t\t\t\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t\t\t|                                          | Menu Table |                                          |" << endl;
	cout << "\t\t\t\t\t\t\t+--------------------------------------------------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [1] - Insert Customer | [2] - Print Customer   | [3] - Delete Customer    | [4] - Edit Customer  |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+----------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [5] - Insert Supplier | [6] - Print Supplier   | [7] - Delete Supplier    | [8] - Edit Supplier  |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+----------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [9] - Insert Item     | [10] - Print Item      | [11] - Delete Item       | [12] - Edit Item     |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+----------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [13] - Receiving      | [14] - sale            | [15] - Clear the screen  |                      |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+----------------------+\n" << endl;
}
void receiving(Items_List& i1) {
	int barcode;
	int quantity;
	int totPrice;

	// Valid barcode to be an integer
	while (true) {
		cout << "\n\t\t\tBarcode                      : ";
		if (cin >> barcode) {
			break;  // Exit from the loop if a valid integer is entered
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the barcode." << endl;
			cin.clear();  // Remove the error 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
		}
	}

	// Valid quantity to be an integer
	while (true) {
		cout << "\t\t\tQuantity                     : ";
		if (cin >> quantity) {
			break;  // Exit from the loop if a valid integer is entered
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the quantity." << endl;
			cin.clear();  // Remove the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
		}
	}

	// Valid total Price to be an integer
	while (true) {
		cout << "\t\t\tTotal price of item (Rs/-)   : ";
		if (cin >> totPrice) {
			break;  // Exit from the loop if a valid integer is entered
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the total price." << endl;
			cin.clear();  // Remove the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
		}
	}

	cout << endl;
	i1.searchInReceiveItem(barcode, quantity, totPrice);
}
void sale(Items_List& i1) {
	int barcode;
	int quantity;
	int subTotal;

	// Valid barcode to be an integer
	while (true) {
		cout << "\n\t\t\tBarcode                          : ";
		if (cin >> barcode) {
			break;  // Exit from the loop if a valid integer is entered
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the barcode." << endl;
			cin.clear();  // Remove the error 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
		}
	}

	// Valid quantity to be an integer
	while (true) {
		cout << "\t\t\tQuantity                         : ";
		if (cin >> quantity) {
			break;  // Exit from the loop if a valid integer is entered
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the quantity." << endl;
			cin.clear();  // Remove the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
		}
	}

	cout << "\t\t\tSub Total price of item (Rs/-)   : " << i1.searchSellPrice(barcode) * quantity << endl;

	i1.searchInSaleItem(barcode, quantity);
}
void selectMenu(Transactions_List& t1, Transactions_List& t2, Items_List& i1) {
	string choice;
	cin >> choice;

	/* //# We handled the menu input errors such as wrong integer and strings
	switch (choice) {
	case 1:
		t1.insertCustomer(); break;
	case 2:
		t1.printCustomer(); break;
	case 3:
		int a;
		cout << "\n\t\t\t# Which customer do you want to delete enter position : ";
		cin >> a;
		t1.deleteCustomer(a-1); break;
	case 4:
		int b;
		cout << "\n\t\t\t# Which customer do you want to edit enter position : ";
		cin >> b;
		t1.editCustomer(b-1); break;
	case 5:
		t2.insertCustomer(); break;
	case 6:
		t2.printCustomer(); break;
	case 7:
		int c;
		cout << "\n\t\t\t# Which supplier do you want to delete enter position : ";
		cin >> c;
		t2.deleteCustomer(c-1); break;
	case 8:
		int d;
		cout << "\n\t\t\t# Which supplier do you want to edit enter position : ";
		cin >> d;
		t2.editCustomer(d-1); break;
	case 9:
		i1.insertItem(); break;
	case 10:
		i1.printItem_list(); break;
	case 11:
		int e;
		cout << "\n\t\t\t# Which item do you want to delete enter position : ";
		cin >> e;
		i1.deleteItem(e-1); break;
	case 12:
		int f;
		cout << "\n\t\t\t# Which item do you want to edit enter position : ";
		cin >> f;
		i1.editItem(f-1); break;
	case 13:
		receiving(i1); break;
	case 14:
		break;
	case 15:
		system("cls");
		printMenu(); break;
	default:
		cout << "\n\t\t# Invalid choice. Try again!\n";
	}

	cout << "\n\t\tChoose another option from above list :  ";
	selectMenu(t1, t2, i1);
}*/
	if (choice == "1") {
		t1.insertCustomer();
	}
	else if (choice == "2") {
		t1.printCustomer();
	}
	else if (choice == "3") {
		int a;
		cout << "\n\t\t\t# Which customer do you want to delete enter position : ";
		cin >> a;
		t1.deleteCustomer(a - 1);
	}
	else if (choice == "4") {
		int b;
		cout << "\n\t\t\t# Which customer do you want to edit enter position : ";
		cin >> b;
		t1.editCustomer(b - 1);
	}
	else if (choice == "5") {
		t2.insertSupplier();
	}
	else if (choice == "6") {
		t2.printSupplier();
	}
	else if (choice == "7") {
		int c;
		cout << "\n\t\t\t# Which supplier do you want to delete enter position : ";
		cin >> c;
		t2.deleteSupplier(c - 1);
	}
	else if (choice == "8") {
		int d;
		cout << "\n\t\t\t# Which supplier do you want to edit enter position : ";
		cin >> d;
		t2.editSupplier(d - 1);
	}
	else if (choice == "9") {
		i1.insertItem();
	}
	else if (choice == "10") {
		i1.printItem_list();
	}
	else if (choice == "11") {
		int e;
		cout << "\n\t\t\t# Which item do you want to delete enter position : ";
		cin >> e;
		i1.deleteItem(e - 1);
	}
	else if (choice == "12") {
		int f;
		cout << "\n\t\t\t# Which item do you want to edit enter BARCODE : ";
		cin >> f;
		i1.editItem(f);
	}
	else if (choice == "13") {
		receiving(i1);
	}
	else if (choice == "14") {
		sale(i1);
	}
	else if (choice == "15") {
		system("cls");
		printMenu();
	}
	else {
		cout << "\n\t\t# Invalid choice. Try again!\n";
	}

	cout << "\n\t\tChoose another option from the above list :  ";
	selectMenu(t1, t2, i1);
}

int main() {
	Transactions_List t1;	// This is for the customer object
	Transactions_List t2;	// This is for the supplier object
	Items_List i1;


	printMenu();
	cout << "\t\tGive the number from Menu table       :  ";;
	selectMenu(t1, t2, i1);
}