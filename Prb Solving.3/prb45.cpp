#include <iostream>
#include <string>
#include <limits>
using namespace std;
struct UserInfo {
	int accountnumber;
	int accountpincode;
	int accountphonenumber;
	int accountballance;
	string accountusername;
};

void ReadUserInfo(UserInfo& Info) {
	cout << "Enter Account Number : "<<endl;
	cin >>Info.accountnumber;
	cout << "Enter Account Pin Code : "<<endl;
	cin >>Info.accountpincode;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter Account Name : "<<endl;
	getline(cin,Info.accountusername);
	cout << "Enter Account Phone Number : "<<endl;
	cin >>Info.accountphonenumber;
	cout << "Enter Account Ballance : "<<endl;
	cin >>Info.accountballance;
}
void PrintUserInfoInOneLine(UserInfo *Ptr) {
	string seperater = " #//# ";
	cout << "Client Record For Saving is : "<<endl;
	cout << Ptr->accountnumber << seperater<< Ptr->accountpincode <<seperater<< Ptr->accountphonenumber << seperater<< Ptr->accountballance << seperater<< Ptr->accountusername <<endl;
}
int main()
{
	UserInfo Info;
	ReadUserInfo(Info);
	UserInfo *Ptr = &Info;
	PrintUserInfoInOneLine(Ptr);
	return 0;
}
. 