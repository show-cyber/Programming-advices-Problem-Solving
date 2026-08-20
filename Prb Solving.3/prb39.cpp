#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
string ReadString() {
	string text;
	cout << "Please Enter Your String ?"<<endl;
	getline(cin, text);
	return text;
}
string TrimLeft(string text){
    char delim = ' ';
    for (char &x : text){
        if (x != delim){
            break;
        }else{
            text.erase(0,0);
        }
    };
    return text;
}
string TrimRigth(string text){
    bool delimfinish = false;
    char delim = ' ';
    for (int a = text.length() ; delimfinish == false ; a--){
        if (text[a] == delim){
            text.pop_back();
        } else {
            delimfinish = true;
        }
    }
    return text;
}
string Trim(string text){
    TrimLeft(text);
    TrimRigth(text);
    return text;
}
int main() {
    string text = ReadString();
    cout << "String Length = "<<setw(2)<<text.length()<<endl;
    cout << "Trim Left = "<<setw(2)<<TrimLeft(text)<<endl;
    cout << "Trim Rigth = "<<setw(2)<<TrimRigth(text)<<endl;
    cout << "Trim = "<<setw(2)<<Trim(text)<<endl;
	return 0;
}