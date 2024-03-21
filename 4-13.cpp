#include<iostream>
using namespace std;

double convertToMPH(int minute ,int second) {                //minutes and seconds per mile轉成mph
	double hour;                                             //宣告浮點數
	hour = ((double)minute * 60 + (double)second) / 3600;    //把幾分幾秒，換成小時
	return hour;                                             //回傳小時
}

double convertToMPH(double kph) {                            //kph轉mph
	return (kph / 1.61);
}

int main() {
	int minute, second;                                      //宣告變數，分鐘、秒
	double kph;                                              //宣告浮點數，kph
	double mph;                                              //宣告浮點數，mph
	char again;                                              //宣告字元，是否再一次
	do {
		cout << "Enter your minutes and seconds per mile =>";
		cin >> minute >> second;                             //輸入minutes and seconds per mile
		mph = convertToMPH(minute, second);                  //呼叫convertToMPH，overload funcyion
		cout << "Your MPH is: " << mph << endl;              //輸出
		cout << "Enter your hour per kilometer =>";
		cin >> kph;                                          //輸入hour per kilometer
		mph = convertToMPH(kph);                             //呼叫convertToMPH，overload funcyion
		cout << "Your MPH is: " << mph << endl;              //輸出
		cout << "you want do again? =>";
		cin >> again;                                        //是否再一次
	} while (again == 'Y');
	return 0;
}