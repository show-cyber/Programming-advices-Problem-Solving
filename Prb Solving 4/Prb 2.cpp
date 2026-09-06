#include <iostream>
#include <string>
using namespace std;
bool isleapyear(int year){
    if (year % 400 == 0){return true;} 
    else if (year % 4 == 0 || year % 100 != 0){
        return true;
    };
    return false;
}
int ReadWNumber(){  
    int num = 0;
    cout << "Enter a year :";
    cin >> num;
    return num;
}

int main(){
    int year = ReadWNumber();  
    if (isleapyear(year)){
        cout << "Yes Its leap year !";
    } else  {
        cout << "its not a leap year !";
    }
    return 0;
}