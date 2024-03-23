#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int random() {                                     //隨機取數:1~3
	return (rand() % 3 + 1);                       //回傳
}

int main() {
	srand(time(NULL));                             //依時間設置種子碼
	int num[10] = { 0 };                           //宣告陣列，隨機數陣列
	int PIN_number = 12345;                        //宣告整數，PIN_number = 12345
	int new_pin = 0;                               //新密碼
	int response = 0;                              //輸入新驗證碼

	for (int i = 0; i < 10; i++) {
		num[i] = random();                              //10個隨機數丟進陣列
	}           
	cout << endl << "PIN : ";
	for (int i = 0; i < 10; i++) {                      //輸出0~9對應的對應數字
		cout << i << " ";
	}
	cout << endl << "NUM : ";                         
	for (int i = 0; i < 10; i++) {                      //輸出對應數字
		cout << num[i] << " ";
	}
	cout << endl;
	int count = 0;
	while (PIN_number > 0) {                                 //計算新密碼
		new_pin += num[PIN_number % 10] * pow(10,count);
		PIN_number /= 10;
		count++;
	}
	cout << "Enter your New PIN number =>";
	cin >> response;                                         //輸入新密碼
	if (response == new_pin) {                               //若正確，輸出currect
		cout << "Your enter currect!" << endl;
	}
	else {                                                   //錯誤則wrong
		cout << "Enter wrong!" << endl;
	}
	return 0;
}