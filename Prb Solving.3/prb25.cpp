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
string FindFirstLetterOfWords(string text){
    bool Isfirstletter = true ;
    for (int x = 0 ; x < text.length() ; x++){
        if (text[x] != ' ' && Isfirstletter){
            
            text[x] = tolower(text[x]);
            
        }
        Isfirstletter = (text[x] == ' ' ? true : false);
    }
    return text;
}
void PrintStringWitchUpperLetters(string text){
    cout << "\nString after conversion : "<<endl;
    cout << text ;
}
int main(){
    PrintStringWitchUpperLetters(FindFirstLetterOfWords(ReadString()));
    return 0;
}