#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int random() {                                     //�H������:1~3
	return (rand() % 3 + 1);                       //�^��
}

int main() {
	srand(time(NULL));                             //�̮ɶ��]�m�ؤl�X
	int num[10] = { 0 };                           //�ŧi�}�C�A�H���ư}�C
	int PIN_number = 12345;                        //�ŧi��ơAPIN_number = 12345
	int new_pin = 0;                               //�s�K�X
	int response = 0;                              //��J�s���ҽX

	for (int i = 0; i < 10; i++) {
		num[i] = random();                              //10���H���ƥ�i�}�C
	}           
	cout << endl << "PIN : ";
	for (int i = 0; i < 10; i++) {                      //��X0~9�����������Ʀr
		cout << i << " ";
	}
	cout << endl << "NUM : ";                         
	for (int i = 0; i < 10; i++) {                      //��X�����Ʀr
		cout << num[i] << " ";
	}
	cout << endl;
	int count = 0;
	while (PIN_number > 0) {                                 //�p��s�K�X
		new_pin += num[PIN_number % 10] * pow(10,count);
		PIN_number /= 10;
		count++;
	}
	cout << "Enter your New PIN number =>";
	cin >> response;                                         //��J�s�K�X
	if (response == new_pin) {                               //�Y���T�A��Xcurrect
		cout << "Your enter currect!" << endl;
	}
	else {                                                   //���~�hwrong
		cout << "Enter wrong!" << endl;
	}
	return 0;
}