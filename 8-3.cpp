#include<iostream>
#include<cstdlib>
using namespace std;

class Complex {
public:
	Complex();                                          //constructor
	Complex(double real, double imaginary);
	friend Complex operator +(const Complex& number1 ,const Complex& number2);       //operator
	friend Complex operator -(const Complex& number1, const Complex& number2);
	friend Complex operator *(const Complex& number1, const Complex& number2);
	friend bool operator == (const Complex& number1, const Complex& number2);
	friend istream& operator >>(istream& inputStream , Complex& number);   
	friend ostream& operator <<(ostream& outputStream, const Complex& number);
private:
	double real;                      //real number
	double imaginary;                 //imaginary number
};

Complex::Complex() : real(0), imaginary(0) {}

Complex::Complex(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

istream& operator >>(istream& inputStream, Complex& number) {              //input
	inputStream >> number.real;
	inputStream >> number.imaginary;
	return inputStream;
}

ostream& operator <<(ostream& outputStream,const Complex& number) {        //output
	double absreal = abs(number.real);
	double absimaginary = abs(number.imaginary);
	if (number.real < 0) {
		outputStream << "-";
	}
	outputStream << absreal;

	if (number.imaginary < 0) {
		outputStream << " - ";
	}
	else {
		outputStream << " + ";
	}
	outputStream << absimaginary;
	outputStream << "i" << endl;
	return outputStream;
}

bool operator == (const Complex& number1, const Complex& number2) {         //equal
	if (number1.real == number2.real && number1.imaginary == number2.imaginary) {
		return true;
	}
	else {
		return false;
	}
}

Complex operator +(const Complex& number1, const Complex& number2) {          //plus
	double plusreal = number1.real + number2.real;
	double plusimaginary = number1.imaginary + number2.imaginary;
	Complex plus(plusreal, plusimaginary);
	return plus;
}

Complex operator -(const Complex& number1, const Complex& number2) {          //minus
	double minusreal = number1.real - number2.real;
	double minusimaginary = number1.imaginary - number2.imaginary;
	Complex minus(minusreal, minusimaginary);
	return minus;
}

Complex operator *(const Complex& number1, const Complex& number2) {          //multiply
	double multiplyreal = number1.real * number2.real - number1.imaginary * number2.imaginary;
	double multiplyimaginary = number1.real * number2.imaginary + number1.imaginary * number2.real;
	Complex multiply(multiplyreal, multiplyimaginary);
	return multiply;
}


int main() {
	Complex number1, number2, computenumber;
	cout << "Enter your first complex number =>";
	cin >> number1;                                              //input
	cout << "Enter your second complex number =>";
	cin >> number2;

	cout << "Your first complex number is " << number1;          //output
	cout << "Your second complex number is " << number2;
	if (number1 == number2) {                                    //equal
		cout << "The first complex number and the second complex number are equal." << endl;
	}
	else {
		cout << "The first complex number and the second complex number are not equal." << endl;
	}
	computenumber = number1 + number2;                       //compute and output
	cout << "The first complex number plus the second complex number is "<< computenumber ;
	computenumber = number1 - number2;
	cout << "The first complex number minus the second complex number is " << computenumber ;
	computenumber = number1 * number2;
	cout << "The first complex number multiply by the second complex number is " << computenumber ;
	
	return 0;
}