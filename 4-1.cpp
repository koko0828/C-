#include<iostream>
using namespace std;

void input(int &hour, int &minute) {                  //��J
	cout << "Enter your time =>(hour,minute)";             
	cin >> hour >> minute;                            //��J�ɶ�(�p�� ����)
}

void conversion(int &hour, int &minute, char &time) { //�ഫ
	if (hour >= 12) {                                 //�Y�p�ɼƤj��12
		hour -= 12;                                   //�p�ɴ�12
		time = 'P';                                   //�r��time�A�]��P
	}
	else if (hour < 12) {                             //�p��12
		time = 'A';                                   //�r��time�A�]��A
	}
}

void output(int hour, int minute, char time) {        //��X
	cout << "your time is " << hour << ":" << minute << time << endl;
}

int main() {
	int hour, minute;                    //�ŧi�ܼơA�p�ɡB����
	char time;                           //�ŧi�r���A�W�ȩΤU��
	char again = 'Y';                    //�O�_�A������
	while (again == 'Y') {               //�����J���OY����
		input(hour, minute);             //�I�s�禡
		conversion(hour, minute, time);
		output(hour, minute, time);
		cout << "again? =>(Y or N)";            
		cin >> again;                    //�O�_�A�@��
	}
	return 0;
}