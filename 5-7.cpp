#include<iostream>
using namespace std;
const int MAX_SIZE = 200;                                     //�̤jSIZE

void inputarray(int grade[], int &length) {                   //��J�}�C
	int input;                                                //�ŧi�ܼơA��J��
	cin >> input;                                             //��J
	while (input >= 0 && input <= 5 && length < MAX_SIZE) {   //��J�Ȭ�0~5�����A�}�C���׭n�C��200
		grade[length] = input;                                //��i�}�C��
		length++;                                             //����++
		cin >> input;                                         //��J
	}
}

int grade_count(int grade[], int length,int target) {         //��ؼЭȡA�íp�⦳�X��
	int count = 0;                                            //�ŧi�ܼ�count�A�X��
	for (int i = 0; i < length; i++) {                        //�q0�]��length
		if (grade[i] == target) {                             //�Y���ؼЭ�
			count++;                                          //count++
		}
	}
	return count;                                             //�^��count
}

int main() {  
	int grade[MAX_SIZE];                                      //�ŧi��ư}�C
	int length = 0;                                           //���׬�0
	int count = 0;                                            //�ƶq��0
	cout << "Enter your grades =>";            
	inputarray(grade, length);                                //�I�s�禡
	for (int i = 0; i <= 5; i++) {                            //�ؼФ��q0�]��5
		count = grade_count(grade, length,i);                 //�I�s�禡
		cout << count << " grade(s) of " << i << endl;        //��X
	}
	return 0;
}