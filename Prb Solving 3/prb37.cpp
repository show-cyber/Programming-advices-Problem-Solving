#include <iostream>
#include <vector>
#include <string>
using namespace std;
string ReadString() {
	string text;
	cout << "Please Enter Your String ?"<<endl;
	getline(cin, text);
	return text;
}

vector<string>SplitString(string text, string delim) {
	vector<string>VSplit;
	int token = 0;
	int pos = 0;
	string point;
	while ((pos = text.find(delim)) != text.npos) {
		point = text.substr(0,pos);
		if (point != "") {
			VSplit.push_back(point);
		}
		text.erase(0,pos + delim.length());
	}
			point = text.substr(0,pos);
	if (text != ""){
	    VSplit.push_back(point);
	}
	return VSplit;
}
int main() {
	vector<string>VSplit;
	VSplit = SplitString(ReadString()," ");
	cout << "\nTokens : "<<VSplit.size()<<endl;
	for (string& x : VSplit){
	    cout <<x<<endl;
	}
	return 0;
}