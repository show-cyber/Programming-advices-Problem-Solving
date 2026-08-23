#include <iostream>
#include <vector>
#include <string>
using namespace std;
string ReadString(){
    string text;
    cout << "Please Enter Your String ?"<<endl;
    getline(cin , text);
    return text;
}
string touppercase(string text){
    bool Isfirstletter = true ;
    for (int x = 0 ; x < text.length() ; x++){
        if (text[x] != ' '){
            
            text[x] = toupper(text[x]);
            
        }
    }
    return text;
}
void PrintStringWitchUpperLetters(string text){
    cout << "\nString after conversion to upper letters : "<<endl;
    cout << text ;
}
string tolowercase(string text){
    bool Isfirstletter = true ;
    for (int x = 0 ; x < text.length() ; x++){
        if (text[x] != ' '){
            
            text[x] = tolower(text[x]);
            
        }
    }
    return text;
}
void PrintStringWitchlowwerLetters(string text){
    cout << "\nString after conversion to lowwer letters : "<<endl;
    cout << text ;
}
int main(){
    string text = ReadString();
    PrintStringWitchUpperLetters(touppercase(text));
    PrintStringWitchlowwerLetters(tolowercase(text));
    return 0;
}