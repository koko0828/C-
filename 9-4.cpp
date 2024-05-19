#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void copy(string input, string& output, int index) {
	int count = 0;
	while (input[index] != '\0') {
		if (isalpha(input[index])) {             //if the letter is alphabet
			count++;
			output += input[index];              //output += input
		}
		else if(count == 4){                     //if the letter is alphabet, and count = 4
			if (index - 4 == 0) {                //switch the word to love
				output[index - 4] = 'L';
			}
			else {
				output[index - 4] = 'l';
			}
			output[index - 3] = 'o';
			output[index - 2] = 'v';
			output[index - 1] = 'e';
			output += input[index];
			count = 0;                           //count = 0
		}
		else {
			output += input[index];              //output += input
			count = 0;
		}
		index++;
	}
}

int main() {
	string input, output;
	int index = 0;
	while (1) {
		cout << "Enter a line of text (or type 'quit' to exit): ";
		getline(cin, input);                             //getline
		if (input == "quit") {                           //quit
			cout << "The end." << endl;
			break;
		}
		copy(input, output, index);                      //input copy to output, and switch four letter word to love
		cout << "Your new string is: " << output << endl;
	}
	return 0;
}