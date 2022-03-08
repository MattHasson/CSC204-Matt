/*--------------------------
	TO DO:
		GENERAL:
		Probably incorporate vectors instead of lists
		Add way to change from employee to customer
		Add error checking
		CUSTOMER:
		Use vectors to be able to edit cart (add/remove games) 
		add checkout function for customer
		EMPLOYEE:
		Make games a vector
		add way to edit game data
		add way to add games to the store
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
//Declare a cart price for use at end of program
float cartTotal;

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
			break;
		case '3':
			break;
		case '4':
			break;
		default:
			cout << "Please enter a valid input! ";
			break;	
	}
	cout << cartTotal << endl;
}

void search(int type) {
	string input;
	char pur;
	game ret;
	ret.name = "null";

	cout << "Please enter the title of the game you are looking for. ";
	getline(cin.ignore(), input);
	
	//Looks through stock array to find the game based on title
	while (ret.name == "null") {
		if (input == "exit") { ret.name = "null"; break; }
		for (int i = 0; i < sizeof(stock)/sizeof(stock[0]); i++) {
			if (input == stock[i].name) {
				ret.name = stock[i].name;
				ret.cost = stock[i].cost;
				ret.inventory = stock[i].inventory;

			}
		}
		//Makes sure the user inputs a valid game title
		if (ret.name == "null") { 
			cout << "Please enter a valid game name. To exit, enter 'exit': ";
			getline(cin, input);
		}
	}
	//If the user didn't enter exit, print out game information, and check if user would like to purchase
	if (ret.name != "null") {
		cout << "Game info: " << endl << "Game name: " << ret.name << endl << "Game cost: " << ret.cost << endl << "Game inventory: " << ret.inventory << endl;
		cout << "Would you like to purchase this game? (Y/N) ";
		cin >> pur;
		switch (toupper(pur)) {
			case 'Y':
				ret.inventory -= 1;
				cartTotal += ret.cost;	
				cout << "Thank you for your purchase!" << endl;		
				break;
			case 'N':
				break;
			default: 
				cout << "Please enter a valid option! ";
				break;
		}	
	}
	
}
