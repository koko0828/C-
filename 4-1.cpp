#include<iostream>
using namespace std;

void input(int &hour, int &minute) {                  //輸入
	cout << "Enter your time =>(hour,minute)";             
	cin >> hour >> minute;                            //輸入時間(小時 分鐘)
}

void conversion(int &hour, int &minute, char &time) { //轉換
	if (hour >= 12) {                                 //若小時數大於12
		hour -= 12;                                   //小時減12
		time = 'P';                                   //字元time，設為P
	}
	else if (hour < 12) {                             //小於12
		time = 'A';                                   //字元time，設為A
	}
}

void output(int hour, int minute, char time) {        //輸出
	cout << "your time is " << hour << ":" << minute << time << endl;
}

int main() {
	int hour, minute;                    //宣告變數，小時、分鐘
	char time;                           //宣告字元，上午或下午
	char again = 'Y';                    //是否再次執行
	while (again == 'Y') {               //直到輸入不是Y為止
		input(hour, minute);             //呼叫函式
		conversion(hour, minute, time);
		output(hour, minute, time);
		cout << "again? =>(Y or N)";            
		cin >> again;                    //是否再一次
	}
	return 0;
}