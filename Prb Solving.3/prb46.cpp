#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct UserInfo {
	string accountnumber;
	string accountpincode;
	string accountphonenumber;
	double accountballance;
	string accountusername;
};

void ReadUserInfo(UserInfo& Info) {
	cout << "Enter Account Number : "<<endl;
	getline(cin,Info.accountnumber);
	cout << "Enter Account Pin Code : "<<endl;
	getline(cin,Info.accountpincode);
	cout << "Enter Account Name : "<<endl;
	getline(cin,Info.accountusername);
	cout << "Enter Account Phone Number : "<<endl;
	getline(cin,Info.accountphonenumber);
	cout << "Enter Account Ballance : "<<endl;
	cin >>Info.accountballance;
}
string PrintUserInfoInOneLine(UserInfo *Ptr) {
	string seperater = " #//# ";
	string text = "";
	text += Ptr->accountnumber + seperater;
	text += Ptr->accountpincode + seperater;
	text += Ptr->accountusername + seperater;
	text += Ptr->accountphonenumber + seperater;
	text += to_string(Ptr->accountballance) ;

	return text;
}
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; 
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); 
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}
void ConvecrtLineIntoList(string text,UserInfo *Ptr)
{
    vector<string>Vtext;
     Vtext = SplitString(text," #//# ");
    Ptr->accountnumber = Vtext[0];
    Ptr->accountpincode = Vtext[1];
    Ptr->accountusername = Vtext[2];
    Ptr->accountphonenumber = Vtext[3];
    Ptr->accountballance = stod(Vtext[4]);
}
void PrintTheList(UserInfo *Ptr){
    cout << "\nAfter Converting to a list : "<<endl;
    cout << "Account Number : "<<Ptr->accountnumber<<endl;
	cout << "Account Pin Code : "<<Ptr->accountpincode<<endl;
	cout << "Account Name : "<<Ptr->accountusername<<endl;
	cout << "Account Phone Number : "<<Ptr->accountphonenumber<<endl;
	cout << "Account Ballance : "<<Ptr->accountballance<<endl;
}
int main()
{
	UserInfo Info;
	ReadUserInfo(Info);
	UserInfo *Ptr = &Info;
	cout << "\nClient Record for saving is : \n";
	string text = PrintUserInfoInOneLine(Ptr);
	cout << text ;
	ConvecrtLineIntoList(text,Ptr);
	PrintTheList(Ptr);
	return 0;
}