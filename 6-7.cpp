#include<iostream>
using namespace std;

class Pizza {                                       //class
public:
	void inputDescription();                        //ipnut the pizza type ,size and toppings 
	void outputDescription();                       //output the pizza type ,size and toppings
	void computePrice();                            //output the pizza price
private:
	int type;                                       //pizza type
	int size;                                       //pizza size
	int number_topping;                             //how many topping you want to add in pizza
};

void Pizza::inputDescription() {
	cout << "track type(1 = deep_dish,2 = hand_tossed, 3 = pan)" << endl;
	cin >> type;                                    //input the type
	if (type == 1 || type == 2 || type == 3) {      //1 = deep_dish,2 = hand_tossed, 3 = pan
		cout << "input succes!" << endl;
	}
	else {                                          //not 1~3 output fail
		cout << "input fail." << endl;
		exit(1);
	}
	cout << "pizza size(1 = small,2 = medium, 3 = large)" << endl;
	cin >> size;                                    //input the size
	if (size == 1 || size == 2 || size == 3) {      //1 = small,2 = medium, 3 = large
		cout << "input succes!" << endl;
	}
	else {
		cout << "input fail." << endl;              //not 1~3 output fail
		exit(1);
	}
	cout << "number of topping = 1~100" << endl;
	cin >> number_topping;                          //input the topping number
	if (number_topping > 0 && number_topping <= 100) {
		cout << "input succes!" << endl;            //0~100
	}
	else {                                          //not 0~100 output fail
		cout << "input fail." << endl;
		exit(1);
	}
}

void Pizza::outputDescription(){                    //output the pizza type ,size and toppings
	if (type == 1) {
		cout << "Your track type is deep dish" << endl;
	}
	else if (type == 2) {
		cout << "Your track type is hand tossed" << endl;
	}
	else if (type == 3) {
		cout << "Your track type is pan" << endl;
	}
	else {
		cout << "Your track type input fail." << endl;
	}

	if (size == 1) {
		cout << "Your pizza size is small" << endl;
	}
	else if (size == 2) {
		cout << "Your pizza size is medium" << endl;
	}
	else if (size == 3) {
		cout << "Your pizza size is large" << endl;
	}
	else {
		cout << "Your pizza size input fail." << endl;
	}

	if (number_topping > 0 && number_topping <= 100) {
		cout << "Your number of toppings is " << number_topping << endl;
	}
	else {
		cout << "Your number of toppings input fail." << endl;
	}
}

void Pizza::computePrice() {               //compute price and output the price
	int price = 0;
	if (size == 1) {
		price += 10;
	}
	else if (size == 2) {
		price += 14;
	}
	else if (size == 3) {
		price += 17;
	}
	else {
		cout << "Your pizza size input fail." << endl;
	}

	if (number_topping > 0 && number_topping <= 100) {
		price += (number_topping * 2);
	}
	else {
		cout << "Your number of topping input fail." << endl;
	}

	cout << "Your price is " << price << endl;
}

int main() {
	Pizza pizza;
	cout << "enter the pizza description =>" << endl;
	pizza.inputDescription();
	pizza.outputDescription();
	pizza.computePrice();
	return 0;
}