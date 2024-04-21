#include<iostream>
using namespace std;

class Money {                                       //class
public:
	void inputmoney();                              //input your money (dollars and cents)
	void outputmoney();                             //output your money to dollars
private:
	int dollars;
	int cents;
};

void Money::inputmoney() {
	cout << "Enter dollars =>";
	cin >> dollars;                                 //input 
	cout << "Enter cents =>";
	cin >> cents;                                   //input
} 

void Money::outputmoney() {
	double money = 0;
	money += dollars;                               
	money += ((double)cents / 100);                 //change the cents to dollars
	cout << "the total money is " << money << endl; //output
}

int main() {
	Money enter_1,enter_2;                          //two different class
	cout << "Enter the first money =>" << endl;
	enter_1.inputmoney();
	enter_1.outputmoney();
	cout << "Enter the second money =>" << endl;
	enter_2.inputmoney();
	enter_2.outputmoney();
	return 0;
}