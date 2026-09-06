/*
 File: prb29.cpp
 Description: A C++ challenge designed to improve logic skills.
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
void Counter(string text,int &CapitalCounter,int &SmallCounter){
    for (int x = 0 ; x < text.length() ; x++){
        (isupper(text[x]) ? CapitalCounter++ :  SmallCounter++);
    }
}
void PrintStatus(string text,int &CapitalCounter,int &SmallCounter){
    cout << "\nString length is : " << text.length()<<endl;
    cout << "String Capital Letters : "<< CapitalCounter <<endl;
    cout << "String Small Letters : "<<SmallCounter <<endl;
}
int main(){
    int CapitalCounter = 0 , SmallCounter = 0;
    string text = ReadString();
    Counter(text,CapitalCounter,SmallCounter);
    PrintStatus(text,CapitalCounter,SmallCounter);
    return 0;
}