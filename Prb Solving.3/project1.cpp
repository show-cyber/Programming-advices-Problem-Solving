#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Bank
{
private:
	const string filename = "Clients.txt";
	struct UserInfo
	{
		string accountnumber;
		string accountpincode;
		string accountphonenumber;
		double accountballance;
		string accountusername;
		bool MarkForDelete = false;
	};

public:
	void MainMenu()
	{
		int Choise = 0;
		cout << "\033[2J\033[1;1H";
		cout << "--------------------------------------" << endl
			 << "         Main Menu Screen             " << endl
			 << "--------------------------------------" << endl
			 << "      [1] Show Clients List" << endl
			 << "      [2] Add New Client" << endl
			 << "      [3] Delete Client" << endl
			 << "      [4] Update Client Info" << endl
			 << "      [5] Find Client" << endl
			 << "      [6] Exit" << endl
			 << "======================================" << endl
			 << "Chose What Do You Want To Do [1 to 6]";
		cin >> Choise;
		switch (Choise)
		{
		case 1:
			ShowClientsList();
			break;
		case 2:
			AddNewClient();
			break;
		case 3:
			DeleteClient();
			break;
		case 4:
			UpdateClientInfo();
			break;
		case 5:
			FindClient();
			break;
		case 6:
			system("pause>0");
			break;
		default:
			cout << "Invalid Choise !" << endl;
			system("pause>0");
		}
	}
	// Start Show LIst client
	void ShowClientsList()
	{
		cout << "\033[2J\033[1;1H";
		vector<UserInfo> VClient;
		VClient = LoadDataFromFileToVector();
		PrintAllClientsData(VClient);
		cout << "\n Click Any Key To Return into Main Menu ...";
		cin.ignore();
		cin.get();
		MainMenu();
	}
	void FindClient()
	{
		vector<UserInfo> VClient;
		UserInfo Info;
		cout << "\033[2J\033[1;1H";
		VClient = LoadDataFromFileToVector();
		cout << "--------------------------------------\n"
			 << "       Finding Client ...\n"
			 << "--------------------------------------\n";
		string accnumber = ReadAccountNumber();
		if (FindUserById(accnumber, VClient, Info))
		{
			PrintTheList(Info);
		}
		cout << "\n Click Any Key To Return into Main Menu ...";
		cin.ignore();
		cin.get();
		MainMenu();
	}
	void UpdateClientInfo()
	{
		cout << "\033[2J\033[1;1H";
		vector<UserInfo> VClient;
		VClient = LoadDataFromFileToVector();
		cout << "--------------------------------------\n"
			 << "       Updating Client Info ...\n"
			 << "--------------------------------------\n";
		string accnumber = ReadAccountNumber();
		UpdateClient(accnumber, VClient);
		cout << "\n Click Any Key To Return into Main Menu ...";
		cin.ignore();
		cin.get();
		MainMenu();
	}
	void deleteandupdateuserinfile(string ID, vector<UserInfo> &VClient, UserInfo Info, string Filename)
	{
		fstream UserFile;
		UserFile.open(Filename, ios::out);
		if (UserFile.is_open())
		{
			for (UserInfo C : VClient)
			{
				if (C.accountnumber != ID)
				{
					string Text = PrintUserInfoInOneLine(C);
					UserFile << Text << endl;
				}
			}
		}
	}
	void UpdateClient(string ID, vector<UserInfo> &VClient)
	{
		UserInfo Info;
		char Choise = ' ';
		if (FindUserById(ID, VClient, Info))
		{
			PrintTheList(Info);
			cout << "\n Are You Sure you want to Update this Client ?[y/n]";
			cin >> Choise;
			if (Choise == 'Y' || Choise == 'y')
			{
				ReadUserInfo(Info);
				deleteandupdateuserinfile(ID, VClient, Info, filename);
				string text = PrintUserInfoInOneLine(Info);
				CreateFile(Info, filename);
			}
		}
		else
		{
			cout << "The User Has not Been Find In The Clients List .";
		}
	}
	vector<UserInfo> LoadDataFromFileToVector()
	{
		vector<UserInfo> VClient;
		fstream UserFile;
		UserFile.open(filename, ios::in);
		if (UserFile.is_open())
		{
			string line = "";
			UserInfo Info;
			while (getline(UserFile, line))
			{
				ConvertLineIntoList(line, Info);
				VClient.push_back(Info);
			}
		}
		return VClient;
	}
	void AddNewClient()
	{
		UserInfo Info;
		cout << "\033[2J\033[1;1H";
		cout << "--------------------------------------\n"
			 << "       Adding New Client ...\n"
			 << "--------------------------------------\n"; // AddNewClient
		ReadUserInfo(Info);
		CreateFile(Info, filename);
		cout << "Succesfuly Added The User ! " << endl;
		cout << "\n Click Any Key To Return into Main Menu ...";
		cin.ignore();
		cin.get();
		MainMenu();
	}
	void PrintAllClientsData(vector<UserInfo> VClient)
	{
		cout << "\n\t\t\t\t\tClient List (" << VClient.size() << ")Client(s).";
		cout
			<< "\n_______________________________________________________";
		cout << "_________________________________________\n"
			 << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n"
			 << endl;
		for (UserInfo Client : VClient)
		{
			PrintClientRecord(Client);
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n"
			 << endl;
	}
	// Finish Show Client Data
	void DeleteClient()
	{
		string ID = "";
		char Choise = ' ';
		cout << "\033[2J\033[1;1H";
		vector<UserInfo> VClient = LoadDataFromFileToVector();
		cout << "--------------------------------------\n"
			 << "       Deletting Clinet ...\n"
			 << "--------------------------------------\n";
		string accnumber = ReadAccountNumber();
		DeleteUserByaccnumber(accnumber, VClient);
		cout << "\n Click Any Key To Return into Main Menu ...";
		cin.ignore();
		cin.get();
		MainMenu();
	}
	void PrintTheList(UserInfo Info)
	{
		cout << "\nClient Data : " << endl;
		cout << "Account Number : " << Info.accountnumber << endl;
		cout << "Account Pin Code : " << Info.accountpincode << endl;
		cout << "Account Name : " << Info.accountusername << endl;
		cout << "Account Phone Number : " << Info.accountphonenumber << endl;
		cout << "Account Ballance : " << Info.accountballance << endl;
	}
	bool FindUserById(string ID, vector<UserInfo> VClient, UserInfo &Info)
	{
		for (UserInfo C : VClient)
		{
			if (C.accountnumber == ID)
			{
				Info = C;
				return true;
			}
		}
		return false;
	}
	void MarkAsForDelete(string ID, vector<UserInfo> &VClient)
	{
		for (UserInfo &C : VClient)
		{
			if (C.accountnumber == ID)
			{
				C.MarkForDelete = true;
			}
		}
	}
	void DeleteUserFromFile(string filename, vector<UserInfo> VClient)
	{
		fstream UserFile;
		UserFile.open(filename, ios::out);
		if (UserFile.is_open())
		{
			for (UserInfo C : VClient)
			{
				if (C.MarkForDelete == false)
				{
					string Text = PrintUserInfoInOneLine(C);
					UserFile << Text << endl;
				}
			}
		}
	}
	void DeleteUserByaccnumber(string ID, vector<UserInfo> &VClient)
	{
		UserInfo Info;
		char Choise = ' ';
		if (FindUserById(ID, VClient, Info))
		{
			PrintTheList(Info);
			cout << "\n Are You Sure you want to delete this Client ?[y/n]";
			cin >> Choise;
			if (Choise == 'Y' || Choise == 'y')
			{
				MarkAsForDelete(ID, VClient);
				DeleteUserFromFile(filename, VClient);
				VClient = LoadDataFromFileToVector();
				cout << "\nThe Client Has Been Deleted Succesfuly ...\n";
			}
		}
		else
		{
			cout << "The User Has not Been Find In THe Clients List .";
		}
	}
	string ReadAccountNumber()
	{
		string accnumber = "";
		cout << "Enter Account Number :";
		cin >> accnumber;
		return accnumber;
	}
	void ConvertLineIntoList(string text, UserInfo &Info)
	{
		vector<string> VClient;
		VClient = SplitString(text, " #/# ");
		Info.accountnumber = VClient[0];
		Info.accountpincode = VClient[1];
		Info.accountusername = VClient[2];
		Info.accountphonenumber = VClient[3];
		Info.accountballance = stod(VClient[4]);
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
	void PrintClientRecord(UserInfo Info)
	{
		cout << "| " << setw(15) << left << Info.accountnumber;
		cout << "| " << setw(10) << left << Info.accountpincode;
		cout << "| " << setw(40) << left << Info.accountusername;
		cout << "| " << setw(12) << left << Info.accountphonenumber;
		cout << "| " << setw(12) << left << Info.accountballance;
	}
	void ReadUserInfo(UserInfo &Info)
	{
		cout << "Enter Account Number : " << endl;
		getline(cin >> ws, Info.accountnumber);
		cout << "Enter Account Pin Code : " << endl;
		getline(cin, Info.accountpincode);
		cout << "Enter Account Name : " << endl;
		getline(cin, Info.accountusername);
		cout << "Enter Account Phone Number : " << endl;
		getline(cin, Info.accountphonenumber);
		cout << "Enter Account Ballance : " << endl;
		cin >> Info.accountballance;
	}
	string PrintUserInfoInOneLine(UserInfo Info)
	{
		string seperater = " #/# ";
		string text = "";
		text += Info.accountnumber + seperater;
		text += Info.accountpincode + seperater;
		text += Info.accountusername + seperater;
		text += Info.accountphonenumber + seperater;
		text += to_string(Info.accountballance);

		return text;
	}
	void CreateFile(UserInfo Info, string filename)
	{
		fstream UserFile;
		UserFile.open(filename, ios::out | ios::app);
		if (UserFile.is_open())
		{
			UserFile << PrintUserInfoInOneLine(Info) << endl;
			UserFile.close();
		}
	}
};
int main()
{
	Bank MyBank;
	MyBank.MainMenu();

	return 0;
}