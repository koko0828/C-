#include<iostream>
#include<cmath>
using namespace std;

void enter_rate(int rating_number[], int rating[]) {               //��J����
	for (int i = 0; i < 3; i++) {                                  //��J�T���q�v������
		cin >> rating_number[i] >> rating[i];                      //��J
		rating_number[i] -= 100;
	}
}

int distance(int table[4][6], int rating_number[], int rating[]) {       //�p��̱��i������
	int sum[4] = {0};                                                    //�ŧi�}�C�A�`�M
	int index = 0;                                                       //�ŧi��ơA���ޭ�
	for (int i = 0; i < 3; i++) {                                        //�p��Z�����`�M
		for (int j = 0; j < 4; j++) {
			sum[j] += pow(rating[i] - table[j][rating_number[i]], 2);
		}
		
	}
	double sqrt_sum[4];                                                  //�ŧi�}�C�A�}�ڸ��L���`�M
	for (int i = 0; i < 4; i++) {                                        //�p��}�ڸ��L���`�M
		sqrt_sum[i] = sqrt((double)sum[i]);
	}                                    
	for (int j = 1; j < 4; j++) {                                        //���̤p��
		if (sqrt_sum[j] < sqrt_sum[index]) {
			index = j;
		}
	}
	return index;                                                        //�^�ǳ̤p�Ȫ����ޭ�
}

int main() {
	int table[4][6] = { {3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{5,1,4,2,4,2} };             //���f������
	int rating_number[3];                                                                      //�ŧi�}�C�A����
	int rating[3];
	int index;                                                                                 //�ŧi��ơA���ޭ�
	cout << "Enter your want to rating number and rating =>";
	enter_rate(rating_number, rating);                                                         //�I�s�禡
	index = distance(table, rating_number, rating);                                            
	for (int i = 0; i < 6; i++) {
		if (i != rating_number[0] && i != rating_number[1] && i != rating_number[2]) {
			cout << "a rating of " << table[index][i] << " for movie " << 100 + i << endl;     //��X�P�ۤv�̱���������f���Ѿl�q�v����
		}
	}
	return 0;
}