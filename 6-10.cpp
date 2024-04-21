#include<iostream>
using namespace std;

class Weight {
public:
	void setWeightPounds();                                      //Pounds convert to pound
	void setWeightKilograms();                                   //kilogram convert to pound
	void setWeightOunces();                                      //Ounces convert to pound
private:
	double pounds;
};

void Weight::setWeightKilograms() {                              //kilogram convert to pound
	double kilogram;
	cout << "Enter your weight (kilogram) =>";
	cin >> kilogram;                                             //input kilogram
	pounds = kilogram * 2.21;
	cout << "your weight is " << pounds << " pounds" << endl;    //output pounds
}

void Weight::setWeightOunces() {                                 //Ounces convert to pound
	double ounces;
	cout << "Enter your weight (ounces) =>";
	cin >> ounces;                                               //input Ounces
	pounds = ounces / 16;
	cout << "your weight is " << pounds << " pounds" << endl;    //output pounds
}

void Weight::setWeightPounds() {                                 //pound
	cout << "Enter your weight (pounds) =>";
	cin >> pounds;                                               //input pound
	cout << "your weight is " << pounds << " pounds" << endl;    //output pounds
}

int main() {
	Weight input;
	char weight;
	cout << "Enter you want to convert to pound =>" << endl;
	cout << "(k = kilogram -> pound, o = Ounces -> pound, p = pound)" << endl;
	cin >> weight;                                  //k = kilogram -> pound, o = Ounces -> pound, p = pound
	if (weight == 'k') {
		input.setWeightKilograms();                 //kilogram convert to pound
	}
	else if (weight == 'o') {
		input.setWeightOunces();                    //Ounces convert to pound
	}
	else if (weight == 'p') { 
		input.setWeightPounds();                    //pound convert to pound
	}
	else {
		cout << "Input fail." << endl;              //input fail
	}
	return 0;
}