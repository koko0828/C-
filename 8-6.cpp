#include<iostream>
using namespace std;

class MyInteger {
public:
	MyInteger();                         //constructor
	MyInteger(int integer);
	int& operator [](int index);         //operator

private:
	int integer;
	int length = 0;
	int array[10];                       //array to get integer
};

MyInteger::MyInteger() :integer(0) {};   //default constructor

MyInteger::MyInteger(int integer) {
	while(integer > 0 && length < 10){
		array[length] = integer % 10;    //put integer to the array 
		integer /= 10;
		length++;
	}
	array[length] = -1;
}

int& MyInteger::operator [](int index) { //operator
	if (index < length) {
		return array[index];             
	}
	else {
		return array[length];
	}
}

int main() {
	MyInteger x(418);
	for (int i = 0; i < 10; i++) {
		cout <<"x["<<i<<"] = " << x[i] << endl;      //output
		if (x[i] == -1) {                   
			break;
		}
	}
	return 0;
}