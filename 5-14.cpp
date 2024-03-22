#include<iostream>
#include<cmath>
using namespace std;

void enter_rate(int rating_number[], int rating[]) {               //輸入評分
	for (int i = 0; i < 3; i++) {                                  //輸入三部電影的評分
		cin >> rating_number[i] >> rating[i];                      //輸入
		rating_number[i] -= 100;
	}
}

int distance(int table[4][6], int rating_number[], int rating[]) {       //計算最接進的評分
	int sum[4] = {0};                                                    //宣告陣列，總和
	int index = 0;                                                       //宣告整數，索引值
	for (int i = 0; i < 3; i++) {                                        //計算距離的總和
		for (int j = 0; j < 4; j++) {
			sum[j] += pow(rating[i] - table[j][rating_number[i]], 2);
		}
		
	}
	double sqrt_sum[4];                                                  //宣告陣列，開根號過的總和
	for (int i = 0; i < 4; i++) {                                        //計算開根號過的總和
		sqrt_sum[i] = sqrt((double)sum[i]);
	}                                    
	for (int j = 1; j < 4; j++) {                                        //取最小值
		if (sqrt_sum[j] < sqrt_sum[index]) {
			index = j;
		}
	}
	return index;                                                        //回傳最小值的索引值
}

int main() {
	int table[4][6] = { {3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{5,1,4,2,4,2} };             //評審的評分
	int rating_number[3];                                                                      //宣告陣列，評分
	int rating[3];
	int index;                                                                                 //宣告整數，索引值
	cout << "Enter your want to rating number and rating =>";
	enter_rate(rating_number, rating);                                                         //呼叫函式
	index = distance(table, rating_number, rating);                                            
	for (int i = 0; i < 6; i++) {
		if (i != rating_number[0] && i != rating_number[1] && i != rating_number[2]) {
			cout << "a rating of " << table[index][i] << " for movie " << 100 + i << endl;     //輸出與自己最接近評分評審的剩餘電影評分
		}
	}
	return 0;
}