#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

class BoxOfProduce {                           //class
private: 
	string box[3];                             //box contain
public:
	void setboxproduce(string list[]);         //set the box contain(random)
	void changeboxproduce();                   //change the box produce
	void outputbox();                          //output the box contain
};

string randombox(string list[]) {              //random to set the box contain
	return (list[rand() % 5]);                 //return
}

void BoxOfProduce::setboxproduce(string list[]) {
	for (int i = 0; i < 3; i++) {              //set the box cintain
		box[i] = randombox(list);
	}
}

void BoxOfProduce::changeboxproduce() {        //change
	int change;
	cout << "What's you want to change(1,2,3) =>";
	cin >> change;                             //what's produce you want to change
	switch (change) {                          
	case 1:
		cout << "You want to change " << box[0] << "to? =>";
		cin >> box[0];                         //input you want to change 
		break;
	case 2:
		cout << "You want to change " << box[1] << "to? =>";
		cin >> box[1];                         //input you want to change
		break;
	case 3:
		cout << "You want to change " << box[2] << "to? =>";
		cin >> box[2];                         //input you want to change
		break;
	default:
		cout << "Enter error" << endl;         //output error
	}
}

void BoxOfProduce::outputbox() {               //output
	cout << "Your box contain :" << endl;
	for (int i = 0; i < 3; i++) {
		cout << box[i] << endl;            
	}
}

void setarray(string list[]) {                 //file open to set array
	fstream inputfile;      
	inputfile.open("input.txt");               //open file
	if (inputfile.fail()) {
		cout << "open file fail." << endl;     //if fail, output fail
	}
	else {
		for (int i = 0; i < 5; i++) {          //set array
			inputfile >> list[i];
		}
	}
}

int main() {
	srand(time(NULL));                         //rand seed
	string list[5];
	char change;
	BoxOfProduce fruit_vegetable;
	setarray(list);
	fruit_vegetable.setboxproduce(list);       //set box produce
	fruit_vegetable.outputbox();               //output box contain
	cout << "Do you want to change any fruit or vegetable? =>";
	cin >> change;                             //change
	if (change == 'Y' || change == 'y') {
		do {
			fruit_vegetable.changeboxproduce();//change
			fruit_vegetable.outputbox();
			cout << "Do you want to change again? =>";
			cin >> change;                     //change again?
		} while (change == 'Y' || change == 'y');
	}
	fruit_vegetable.outputbox();               //output the final box contain
	return 0;
}