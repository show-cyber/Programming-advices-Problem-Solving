#include <vector>
#include <iostream>
using namespace std;
voidgit  ReadNumber(vector <int>&vNumber){
    int num = 0;
    char Choise;
    do {
        cout << "Please Enter a Number ?"<< endl;
        cin >> num;
       vNumber.push_back(num);
       cout << "\nDo You Want To Enter Another Number ?"<<endl;
       cin >> Choise; 
    } while (Choise == 'Y'||Choise == 'y');
}
void PrintVector(vector <int>vNumber){
    cout << "Vector  Composent : ";
    for (int &num : vNumber){
        cout <<num <<" ";
    }
}
int main(){
    vector <int>vNumber;
    ReadNumber(vNumber);
    PrintVector(vNumber);
    return 0;
}