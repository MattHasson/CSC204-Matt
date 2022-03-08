/*--------------------------
	TO DO:
		CHANGE
		GENERAL:
		Implement lists into the program
		Both stock and cart should be lists
		CUSTOMER:
		Get the search functions running. Function should check either ID number or game name (Maybe 
		customer can't search by ID number?)
		Use lists to be able to edit cart (add/remove games) 
		addcheckout function for customer
		EMPLOYEE:
		Figure out how to work with lists and structs. If unable to, make game a class
		Add games to stock list
		Search should be same as customer, maybe add functionality that differs between customer and employee
		Add way to edit game data
----------------------------*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

//Declare a struct of 'game', with values for name, cost, and stock
struct game {
	string name;
	float cost;
	int inventory;
};

void employee();
void customer();
void search(int type);
//Declare an array of games, with a max of 25. (It is a small game store after all!)
game stock[25];

int main() {
	char in;
	//First element of stock
	stock[0].name = "Super Mario Bros.";
	stock[0].cost = 4.99;
	stock[0].inventory = 8;
	//Second element of stock	
	stock[1].name = "Portal 2";
	stock[1].cost = 19.99;
	stock[1].inventory = 102;
	/*Final program will have an employee and a customer mode.
	The employee will be able to add and remove games from stock, and change data values.
	The customer will only be able to search games and buy them. 
	Buying games will change the inventory value.
	*/
	cout << "Are you an employee or a customer? \n\t1) Employee\n\t2) Customer\n";
	cin >> in;
	if (in == '1') { employee(); } 
	else if (in == '2') { customer(); } 
	else { cout << "\nInvalid Input!"; }
}

void employee() {
	cout << "Hello, World!";
}

void customer() {
	float cartTotal;
	char in;

	//Give customer a list of options, then react accordingly
	cout << "What would you like to do?\n\t1) Search for game by title\n\t2) View cart\n\t3) Finish order\n\t4) Exit" << endl;
	cin >> in;

	//Make sure customer enters a valid input
	while (in != '1' && in != '2' && in != '3' && in != '4' && in != '5') {
		cout << "Invalid Input! Please try again. " << endl;
		cin >> in;
	}

	//Check what input the customer put in.
	switch (in) {
		case '1':
			search(1);
			break;
		case '2':
			search(1);
			break;
		case '3':
			search(1);
			break;
		case '4':
			search(1);
			break;
		case '5':
			search(1);
			break;
		
	}
}

void search(int type) {
	string input;
	char pur;
	game ret;
	ret.name = "null";

	cout << "Please enter the title of the game you are looking for. ";
	cin >> input;
	
	//Looks through stock array to find the game based on title
	while (ret.name = "null") {
		if (tolower(input) == "exit") { ret.name = "exit"; break; }
		for (int i = 0; i < stock.length; i++) {
			if (tolower(input) == tolower(stock[i].name)) {
				ret = stock[i];
			}
		}
		if (ret.name = "null") { 
			cout << "Please enter a valid game name. To exit, enter 'exit': ";
			cin >> input;
		}
	}
	if (ret.name != "exit") {
		cout << "Game info: " << endl << "Game name: " << ret.name << endl << "Game cost: " << ret.cost << "Game inventory: " << ret.inventory << endl;
		cout << "Would you like to purchase this game?";
	}
	
}
