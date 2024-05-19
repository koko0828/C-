#include<iostream>
#include<string>
using namespace std;

class Subscriber {
public:
	Subscriber();                                   //constructor
	Subscriber(string name, int numChannels);
	void set_ChannelList();                         //set
	void print_subscriber();                        //print
	void clear_sub();                               //clear
	void replace(Subscriber sub);                   //replace
	int get_numChannels();                          //get
	string get_name();
	string get_channelList(int index);
private:
	string name;                                    //name
	int numChannels;                                //number of channels
	string *ChannelList;                            //channel list
};

Subscriber::Subscriber() : name("John"), numChannels(2){        //default constructor
	
}

Subscriber::Subscriber(string name, int numChannels) {          //constructor
	this->name = name;
	this->numChannels = numChannels;
	ChannelList = new string[numChannels];
	for (int i = 0; i < numChannels; i++) {
		ChannelList[i] = "Channel";
	}
}

void Subscriber::set_ChannelList() {                            //set list
	for (int i = 0; i < numChannels; i++) {
		cout << "Enter name of channel " << i + 1 << ":";
		cin >> ChannelList[i];
	}
}

void Subscriber::print_subscriber() {                           //output
	cout << "Subscriber's Name: " << name << endl;
	cout << "Number of Channels: " << numChannels << endl;
	cout << "Channels: " << endl;
	for (int i = 0; i < numChannels; i++) {
		cout << "Channel " << i + 1 << ": " << ChannelList[i] << endl;
	}
}

int Subscriber::get_numChannels() {                              //get
	return numChannels;
}

string Subscriber::get_name() {                                  //get
	return name;
}

string Subscriber::get_channelList(int index) {                  //get
	return (ChannelList[index]);
}

void Subscriber::clear_sub() {                                   //delete
	delete [] ChannelList;
}

void Subscriber::replace(Subscriber sub) {                       //replace
	ChannelList = new string[sub.get_numChannels()];
	name = sub.get_name();
	numChannels = sub.get_numChannels();
	for (int i = 0; i < numChannels; i++) {
		ChannelList[i] = sub.get_channelList(i);
	}
}

int main() {
	string input;
	int num_channel;
	cout << "Enter subscriber's name:";                          //input
	cin >> input;
	cout << "Enter number of channels :";
	cin >> num_channel;
	Subscriber sub(input, num_channel),sub2("John",2);           //set
	sub.set_ChannelList();                                     
	sub.print_subscriber();
	sub2.print_subscriber();
	sub2.clear_sub();
	sub2.replace(sub);
	sub2.print_subscriber();

	return 0;
}