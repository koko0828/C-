#include<iostream>
using namespace std;
const int MAX_SIZE = 200;                                     //最大SIZE

void inputarray(int grade[], int &length) {                   //輸入陣列
	int input;                                                //宣告變數，輸入值
	cin >> input;                                             //輸入
	while (input >= 0 && input <= 5 && length < MAX_SIZE) {   //輸入值為0~5之間，陣列長度要低於200
		grade[length] = input;                                //丟進陣列裡
		length++;                                             //長度++
		cin >> input;                                         //輸入
	}
}

int grade_count(int grade[], int length,int target) {         //找目標值，並計算有幾個
	int count = 0;                                            //宣告變數count，幾次
	for (int i = 0; i < length; i++) {                        //從0跑到length
		if (grade[i] == target) {                             //若為目標值
			count++;                                          //count++
		}
	}
	return count;                                             //回傳count
}

int main() {  
	int grade[MAX_SIZE];                                      //宣告整數陣列
	int length = 0;                                           //長度為0
	int count = 0;                                            //數量為0
	cout << "Enter your grades =>";            
	inputarray(grade, length);                                //呼叫函式
	for (int i = 0; i <= 5; i++) {                            //目標分從0跑到5
		count = grade_count(grade, length,i);                 //呼叫函式
		cout << count << " grade(s) of " << i << endl;        //輸出
	}
	return 0;
}