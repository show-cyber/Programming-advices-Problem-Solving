/*
 File: prb27.cpp
 Description: A practice file for learning C++ fundamentals.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
char ReadString(){
    char letter;
    cout << "Please Enter a Letter ?"<<endl;\
    cin >>letter;
    return letter;
}
char InvertLetter(char letter){
    return (isupper(letter) ? tolower(letter) : toupper(letter));
}
int main(){
    char letter = ReadString();
    cout << InvertLetter(letter);
    return 0;
}