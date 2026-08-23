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
void FindFirstLetterOfWords(string text){
    bool Isfirstletter = true ;
    for (int x = 0 ; x < text.length() ; x++){
        if (text[x] != ' ' && Isfirstletter){
            cout <<text[x] <<endl;
        }
        Isfirstletter = (text[x] == ' ' ? true : false);
    }
}
int main(){
    string text;
    FindFirstLetterOfWords(ReadString());
    return 0;
}