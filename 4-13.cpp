#include<iostream>
using namespace std;

double convertToMPH(int minute ,int second) {                //minutes and seconds per mile�নmph
	double hour;                                             //�ŧi�B�I��
	hour = ((double)minute * 60 + (double)second) / 3600;    //��X���X��A�����p��
	return hour;                                             //�^�Ǥp��
}

double convertToMPH(double kph) {                            //kph��mph
	return (kph / 1.61);
}

int main() {
	int minute, second;                                      //�ŧi�ܼơA�����B��
	double kph;                                              //�ŧi�B�I�ơAkph
	double mph;                                              //�ŧi�B�I�ơAmph
	char again;                                              //�ŧi�r���A�O�_�A�@��
	do {
		cout << "Enter your minutes and seconds per mile =>";
		cin >> minute >> second;                             //��Jminutes and seconds per mile
		mph = convertToMPH(minute, second);                  //�I�sconvertToMPH�Aoverload funcyion
		cout << "Your MPH is: " << mph << endl;              //��X
		cout << "Enter your hour per kilometer =>";
		cin >> kph;                                          //��Jhour per kilometer
		mph = convertToMPH(kph);                             //�I�sconvertToMPH�Aoverload funcyion
		cout << "Your MPH is: " << mph << endl;              //��X
		cout << "you want do again? =>";
		cin >> again;                                        //�O�_�A�@��
	} while (again == 'Y');
	return 0;
}