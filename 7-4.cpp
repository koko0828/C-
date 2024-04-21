#include<iostream>
using namespace std;

class HotDogStand {                                    //class
public:
	HotDogStand(int ID, int sold_num);                 //set the initail value
	void JustSold(int number);                         //compute total sold and stand sold
	int get_sold();                                    //get the stand sold
	static int get_soldnumber();                       //get the total sold
private:
	int ID_number;                                     //stand ID
	int sold = 0;                                      //stand sold
	static int sold_number;                            //total sold
};

int HotDogStand::sold_number = 0;                      //total sold = 0

HotDogStand::HotDogStand(int ID , int sold_num) : ID_number(ID) , sold(sold_num){
	sold_number += sold_num;                           //set initial value
}

void HotDogStand::JustSold(int number) {               //compute sold
	sold_number += number;
	sold += number;
}

int HotDogStand::get_sold() {                          //get sold
	return sold;
}

int HotDogStand::get_soldnumber() {                    //get total sold
	return sold_number;
}

int main() {
	HotDogStand ID1(101,2), ID2(102,3), ID3(103,4);    //set the initial value
	int ID;
	int number;
	int count; 
	cout << "101 stand sold " << ID1.get_sold() << " hotdogs" << endl;                //output one time
	cout << "102 stand sold " << ID2.get_sold() << " hotdogs" << endl;
	cout << "103 stand sold " << ID3.get_sold() << " hotdogs" << endl;
	cout << "Today you sold " << HotDogStand::get_soldnumber() << " hotdogs" << endl;
	do {
		cout << "which stand that you go to buy the hotdog (input -1 to end)=>(101,102,103)";
		cin >> ID;                                     //which stand ID you go to buy
		if (ID != -1) {
			cout << "How many hotdog you buy =>";
			cin >> number;                             //how many
			switch (ID) {
			case 101:
				ID1.JustSold(number);                  //compute
				break;
			case 102:
				ID2.JustSold(number);                  //compute
				break;
			case 103:
				ID3.JustSold(number);                  //compute
				break;
			default:
				cout << "Enter error." << endl;
				break;
			}
		}
		else {
			cout << "end" << endl;
		}
	} while (ID != -1);
	cout << "101 stand sold " << ID1.get_sold() << " hotdogs" << endl;                  //output the final sold number
	cout << "102 stand sold " << ID2.get_sold() << " hotdogs" << endl;
	cout << "103 stand sold " << ID3.get_sold() << " hotdogs" << endl;
	cout << "Today you sold " << HotDogStand::get_soldnumber() << " hotdogs" << endl;
	return 0;
}