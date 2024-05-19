#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class PrimeNumber {
public:
	PrimeNumber(int prime_number);                      //constructor
	PrimeNumber();
	int get_prime_number();                             //get
	PrimeNumber operator++();                           //operator ++ --
	PrimeNumber operator++(int num);
	PrimeNumber operator--();
	PrimeNumber operator--(int num);
private:
	int prime_number;                                   //prime number
};

PrimeNumber::PrimeNumber(int prime_number) {            //constructor
	this->prime_number = prime_number;
}

PrimeNumber::PrimeNumber() :prime_number(1){};          //default constructor

int PrimeNumber::get_prime_number() {                   //get
	return(prime_number);
}

PrimeNumber PrimeNumber::operator++() {                 //++a
	prime_number++;
	return PrimeNumber(prime_number);
}

PrimeNumber PrimeNumber::operator++(int num) {          //a++
	int prime_num = prime_number;
	prime_number++;
	return PrimeNumber(prime_num);
}

PrimeNumber PrimeNumber::operator--() {                 //--a
	prime_number--;
	return PrimeNumber(prime_number);
}

PrimeNumber PrimeNumber::operator--(int num) {          //a--
	int prime_num = prime_number;
	prime_number--;
	return PrimeNumber(prime_num);
}

int find_next_prime(PrimeNumber number) {               //find prime number
	PrimeNumber next_number;
	while (1) {
		next_number = ++number;
		int prime_number = next_number.get_prime_number();
		int num = sqrt(next_number.get_prime_number());
		int count = 0;
		for (int i = 2; i <= num; i++) {
			if (prime_number % i == 0) {
				count++;
				break;
			}
		}
		if (count == 0) {
			break;
		}
	}
	return (next_number.get_prime_number());
}

int find_last_prime(PrimeNumber number) {                  //find prime number
	PrimeNumber next_number;
	while (1) {
		next_number = --number;
		int prime_number = next_number.get_prime_number();
		int num = sqrt(next_number.get_prime_number());
		int count = 0;
		for (int i = 2; i <= num; i++) {
			if (prime_number % i == 0) {
				count++;
				break;
			}
		}
		if (count == 0) {
			break;
		}
	}
	return (next_number.get_prime_number());
}

int main() {
	int prime;
	cout << "Enter the prime number =>";
	cin >> prime;                      //input
	PrimeNumber number(prime);         //set prime number
	cout << "The next prime number is: " << find_next_prime(number) << endl;       //output
	cout << "The next prime number is: " << find_last_prime(number) << endl;
	return 0;
}