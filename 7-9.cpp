#include<iostream>
#include<cmath>
using namespace std;

class zip_code {                                  //class
public:           
	zip_code(int enter_zip_code);                 //change zip code to bar code
	zip_code(string enter_bar_code);              //change bar code to zip code
private:
	int zip_code_str = 0;                         //zip code integer
	string bar_code_str;                          //bar code string
	int number[5] = {};
};

zip_code::zip_code(string enter_bar_code): bar_code_str(enter_bar_code){      //change bar code to zip code
	cout << "Your bar code is " << bar_code_str << endl;                      //output bar code
	int count = 0;
	int index = 1;
	int num[5];
	for (int j = 0; j < 5; j++) {
		while (count < 5) {                                                   //change string to integer
			num[count] = bar_code_str[index] - '0';                           //change 5 character to integer
			index++;
			count++;
		}
		count = 0;
		for (int i = 0; i < 5; i++) {                                         //change bar code to zip code
			if (i == 0) {                                                     //(7,4,2,1,0)
				number[j] += num[i] * 7;
			}
			else if (i < 4){
				number[j] += num[i] * pow(2, 3 - i);
			}
			else {
				number[j] += 0;
			}
		}
		if (number[j] == 11) {                                                //if zip code = 11
			number[j] = 0;                                                    //zip code = 0
		}
	}
	for (int i = 0; i < 5; i++) {
		zip_code_str += number[i] * pow(10, 4 - i);                           //change to the integer
	}
	cout << "Your zip code is " << zip_code_str << endl;                      //output
} 

zip_code::zip_code(int enter_zip_code) : zip_code_str(enter_zip_code) {       //change zip_code to bar code
	cout << "Your zip code is " << zip_code_str << endl;                      //output zip_code
	int count = 4;
	while (zip_code_str > 0) {                                                //change integer to array
		number[count] = zip_code_str % 10;
		count--;
		zip_code_str /= 10;
	}
	cout << "Your bar code is " << "1";
	for (int i = 0; i < 5; i++) {                                             //change zip_code to bar code
		switch (number[i]) {
		case 0:
			bar_code_str = "11000";
			break;
		case 1:
			bar_code_str = "00011";
			break;
		case 2:
			bar_code_str = "00101";
			break;
		case 3:
			bar_code_str = "00110";
			break;
		case 4:
			bar_code_str = "01001";
			break;
		case 5:
			bar_code_str = "01010";
			break;
		case 6:
			bar_code_str = "01100";
			break;
		case 7:
			bar_code_str = "10001";
			break;
		case 8:
			bar_code_str = "10010";
			break;
		case 9:
			bar_code_str = "10100";
			break;
		}
		cout << bar_code_str;                                                //output
	}
	cout << "1" << endl;
}

int main() {
	char type;
	cout << "What type you want to input (zip code or bar code)(z or b)=>";
	cin >> type;                                        //input you want to input(zip code or bar code)
	if (type == 'z') {
		int enter_zip_code;
		cout << "Enter the zip code =>";
		cin >> enter_zip_code;                          //input zip code
		zip_code code(enter_zip_code);
	}
	else if (type == 'b') {
		string enter_bar_code;
		cout << "Enter the bar code =>";
		cin >> enter_bar_code;                          //input bar code
		zip_code code2(enter_bar_code);
	}
	else {                                              //input error
		cout << "Enter error!!" << endl;
	}
	return 0;
}