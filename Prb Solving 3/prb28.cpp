/*
 File: prb28.cpp
 Description: A small algorithmic exercise in C++.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

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
string Converter(string text){
    for (int x = 0 ; x < text.length() ; x++){
        (isupper(text[x]) ? text[x] = tolower(text[x]) :text[x] = toupper(text[x]));
    }
    return text;
}
void PrintStringWitchConvertLetters(string text){
    cout << "\nString after conversion Letters : "<<endl;
    cout << text ;
}
int main(){
    string text = ReadString();
    PrintStringWitchConvertLetters(Converter(text));
    return 0;
}