#pragma once
#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>


using namespace std;

class TempCustomer {
public:
	string name;
	int ctNo;
	TempCustomer* next;

	TempCustomer() { // Default constructor
		name = "";
		ctNo = 0;

	}
	TempCustomer(string name, int ctNo) { // Overloaded constructor
		this->name = name;
		this->ctNo = ctNo;
	}
};

class TempSupplier {
public:
	string name;
	int ctNo;
	TempSupplier* next;

	TempSupplier() { // Default constructor
		name = "";
		ctNo = 0;
	}
	TempSupplier(string name, int ctNo) { // Overloaded constructor
		this->name = name;
		this->ctNo = ctNo;
	}
};

class Transactions_List {
private:
	TempCustomer* head;
	TempCustomer* tail;
	int size;

	TempSupplier* supplierHead;
	TempSupplier* supplierTail;
	int supplierSize;

public:
	Transactions_List() {
		head = NULL;
		tail = NULL;
		size = 0;

		supplierHead = NULL;
		supplierTail = NULL;
		supplierSize = 0;
	}
	void insertCustomer() {

		string Name;
		int Ctno;

		cout << "\n\t\t\tCustomer name           : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
		getline(cin, Name);

		// Validate Ctno to be a 10-digit integer including zero so, lenght == 9
		while (true) {
			cout << "\t\t\tCustomer contact number : ";
			if (cin >> Ctno && to_string(Ctno).length() == 9) {
				break;  // Exit the loop if a valid 10-digit integer is entered
			}
			else {
				cout << "\t\t\tInvalid input. Please enter a 10-digit integer." << endl;
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
			}
		}


		TempCustomer* temp = new TempCustomer(Name, Ctno);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}

	void printCustomer() {

		TempCustomer* current = head;
		if (head == NULL) {
			cout << "\n\t# There is no customer to print." << endl;
		}
		else {
			cout << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\t\t|     [CUSTOM NAME]    |    [CONTACT NUMBER]    |" << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			for (int i = 0; i < size; i++) {
				cout << "\t\t\t\t\t\t\t" << "|" << setw(21) << current->name << " |           " << setw(12) << current->ctNo << " |" << endl;  // Ctno should be less than 12
				cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
				current = current->next;
			}
			cout << endl;
		}
	}

	void deleteCustomer(int pos) {
		TempCustomer* temp = head;
		if (head == NULL) {
			cout << "\n\t# No customer to delete." << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no customer at this position." << endl;
		}
		else if (pos == 0) {
			head = head->next;
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}

	void editCustomer(int pos) {
		if (head == NULL) {
			cout << "\n\t# No customer to edit." << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no customer at this position." << endl;
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			string new_Name;
			cout << "\n\t\t# Give the new customer name for : " << current->name << " : ";
			cin >> new_Name;
			current->name = new_Name;
			cout << "\n\t\t# Give the new custom contact no : ";
			cin >> current->ctNo;
		}
	}

	// Add the supplier-related methods
	void insertSupplier() {
		string Name;
		int Ctno;

		cout << "\n\t\t\tSupplier name           : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
		getline(cin, Name);

		// Validate Ctno to be a 10-digit integer including zero so, length == 9
		while (true) {
			cout << "\t\t\tSupplier contact number : ";
			if (cin >> Ctno && to_string(Ctno).length() == 9) {
				break;  // Exit the loop if a valid 10-digit integer is entered
			}
			else {
				cout << "\t\t\tInvalid input. Please enter a 10-digit integer." << endl;
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
			}
		}


		TempSupplier* temp = new TempSupplier(Name, Ctno);
		if (supplierHead == NULL) {
			supplierHead = temp;
			supplierTail = temp;
			supplierSize++;
		}
		else {
			supplierTail->next = temp;
			supplierTail = temp;
			supplierSize++;
		}
	}

	void printSupplier() {
		TempSupplier* current = supplierHead;
		if (supplierHead == NULL) {
			cout << "\n\t# There is no supplier to print." << endl;
		}
		else {
			cout << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\t\t|    [SUPPLIER NAME]    |    [CONTACT NUMBER]    |" << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			for (int i = 0; i < supplierSize; i++) {
				cout << "\t\t\t\t\t\t\t" << "|" << setw(21) << current->name << " |           " << setw(12) << current->ctNo << " |" << endl;
				cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
				current = current->next;
			}
			cout << endl;
		}
	}

	void deleteSupplier(int pos) {
		TempSupplier* temp = supplierHead;
		if (supplierHead == NULL) {
			cout << "\n\t# No supplier to delete." << endl;
		}
		else if (pos < 0 || pos >= supplierSize) {
			cout << "\n\t# Invalid position. There is no supplier at this position." << endl;
		}
		else if (pos == 0) {
			supplierHead = supplierHead->next;
		}
		else {
			TempSupplier* current = supplierHead;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			temp = current->next;
			current->next = temp->next;
			delete temp;
			supplierSize--;
		}
	}

	void editSupplier(int pos) {
		if (supplierHead == NULL) {
			cout << "\n\t# No supplier to edit." << endl;
		}
		else if (pos < 0 || pos >= supplierSize) {
			cout << "\n\t# Invalid position. There is no supplier at this position." << endl;
		}
		else {
			TempSupplier* current = supplierHead;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			string new_Name;
			cout << "\n\t\t# Give the new supplier name for : " << current->name << " : ";
			cin >> new_Name;
			current->name = new_Name;
			cout << "\n\t\t# Give the new supplier contact no : ";
			cin >> current->ctNo;
		}
	}
};

class TempItem {
public:
	string name;
	int barcode;
	float costPrice;
	float sellPrice;
	int quantity;
	TempItem* next;

	TempItem() { // Default  constructor
		name = "";
		quantity = 0;
	}
	TempItem(string name, int barcode, float sellPrice) { // Overloaded constructor
		this->name = name;
		this->barcode = barcode;
		this->sellPrice = sellPrice;

	}
};

class Items_List {
private:
	TempItem* head;
	TempItem* tail;
	int size;

public:
	Items_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertItem() {
		string name;
		int barcode;
		float sellPrice;  // Changed the data type to int

		cout << "\n\t\t\tItem name              : ";
		cin >> name;

		// Validate barcode to be an integer
		while (true) {
			cout << "\t\t\tItem barcode           : ";
			if (cin >> barcode) {
				break;  // Exit the loop if a valid integer is entered
			}
			else {
				cout << "\t\t\tInvalid input. Please enter an integer for the barcode." << endl;
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Validate sellPrice to be an integer
		while (true) {
			cout << "\t\t\tItem sellPrice (Rs/-)  : ";
			if (cin >> sellPrice) {
				break;  // Exit the loop if a valid integer is entered
			}
			else {
				cout << "\t\t\tInvalid input. Please enter an integer for the sellPrice." << endl;
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		TempItem* temp = new TempItem(name, barcode, sellPrice);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void printItem_list() {
		TempItem* temp = head;
		if (head == NULL) {
			cout << "\n\t# No item to print." << endl;
		}
		else {
			cout << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------------------------------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\t\t|     [ITEM NAME]     |    [BARCODE]   |  [COST PRICE  (Rs/-)]  |  [SELL PRICE  (Rs/-)]   |   [QUANTITY]    | " << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------------------------------------------------------------------+" << endl;
			for (int i = 0; i < size; i++) {
				cout << "\t\t\t\t\t\t\t" << "|" << setw(20) << temp->name << " |   " << setw(12) << temp->barcode << " |             " << setw(10) << temp->costPrice << " |              " << setw(10) << temp->sellPrice << " |    " << setw(12) << temp->quantity << " |" << endl;
				cout << "\t\t\t\t\t\t\t+-----------------------------------------------------------------------------------------------------------+" << endl;

				temp = temp->next;
			}
			cout << endl;
		}
	}
	void deleteItem(int pos) {
		TempItem* temp = head;
		if (head == NULL) {
			cout << "\n\t# No item to delete." << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no item at this position." << endl;
		}
		else if (pos == 0) {
			head = head->next;
		}
		else {
			TempItem* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}
	void editItem(int code) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				string new_Name;
				float newSellPrice;
				cout << "\n\t\t# Give the new item name for " << current->name << "   : ";
				cin >> new_Name;
				current->name = new_Name;
				cout << "\t\t# Give the item Sell price          : ";
				cin >> newSellPrice;
				current->sellPrice = newSellPrice;
				break;
			}
			else {
				current = current->next;
			}
		}
	}

	void searchInReceiveItem(int code, int quant, int totalPrice) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				// Update quantity
				current->quantity += quant;

				// Update cost price
				current->costPrice = ((current->costPrice * (current->quantity - quant)) + totalPrice) / current->quantity;

				break;
			}
			else {
				current = current->next;
			}
		}
	}

	void searchInSaleItem(int code, int quant) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				current->quantity -= quant; // update quantity
				break;
			}
			else {
				current = current->next;
			}
		}
	}

	float searchSellPrice(int code) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				return current->sellPrice;
			}
			else {
				current = current->next;
			}
		}
	}
	bool searchItemCode(int code) {
		TempItem* current = head;
		if (current != NULL) {
			while (current != NULL) {
				if (current->barcode == code) {
					return true;
				}
				else {
					current = current->next;
				}
			}
		}
		else {
			return false;
		}
	}
};
