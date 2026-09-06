/*
 File: prb47.cpp
 Description: A logic exercise involving strings and program flow.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;
const string filename = "Clients.txt";
struct UserInfo {
	string accountnumber;
	string accountpincode;
	string accountphonenumber;
	double accountballance;
	string accountusername;
};

void ReadUserInfo(UserInfo& Info) {
	cout << "Enter Accouwnt Number : "<<endl;
	getline(cin,Info.accountnumber);
	cout << "Enter Account Pin Code : "<<endl;
	getline(cin,Info.accountpincode);
	cout << "Enter Account Name : "<<endl;
	getline(cin,Info.accountusername);
	cout << "Enter Account Phone Number : "<<endl;
	getline(cin,Info.accountphonenumber);
	cout << "Enter Account Ballance : "<<endl;
	cin >>Info.accountballance;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
string PrintUserInfoInOneLine(UserInfo *Ptr) {
	string seperater = " #/# ";
	string text = "";
	text += Ptr->accountnumber + seperater;
	text += Ptr->accountpincode + seperater;
	text += Ptr->accountusername + seperater;
	text += Ptr->accountphonenumber + seperater;
	text += to_string(Ptr->accountballance) ;

	return text;
}
void CreateFile(UserInfo *Ptr,string filename){
    fstream UserFile;
    UserFile.open(filename, ios::out | ios::app);
    if (UserFile.is_open()){
        UserFile << PrintUserInfoInOneLine(Ptr) <<endl;
        UserFile.close();
    }
    cout << "Succesfuly Added The User ! "<<endl;
}
/*vector<string> SplitString(string S1, string Delim)
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
}*/
/*void PrintTheList(UserInfo *Ptr){
    cout << "\nAfter Converting to a list : "<<endl;
    cout << "Account Number : "<<Ptr->accountnumber<<endl;
	cout << "Account Pin Code : "<<Ptr->accountpincode<<endl;
	cout << "Account Name : "<<Ptr->accountusername<<endl;
	cout << "Account Phone Number : "<<Ptr->accountphonenumber<<endl;
	cout << "Account Ballance : "<<Ptr->accountballance<<endl;
}*/
int main()
{
	UserInfo Info;
	char Choise ;
	UserInfo *Ptr = &Info;
	do {
	ReadUserInfo(Info);
	CreateFile(Ptr, filename);
	cout << "\n\nDo You Want To Enter More Users ?"<<endl;
	cin >> Choise;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (Choise == 'Y' || Choise == 'y');
	return 0;
}