#include <iostream>
#include <vector>
#include <string>
using namespace std;
char ReadString(){
    char text;
    cout << "Please Enter Your String ?"<<endl;
    cin >>text;
    return text;
}
void IsAVowels(char text){
    (text == 'a' ||text == 'e' ||text == 'i' ||text == 'u' ||text == 'o' ? cout << "Yes Its a vowel :)" : cout << " No Its Not :(");
}
int main(){
    char text = ReadString();
    IsAVowels(text);
    return 0;
}