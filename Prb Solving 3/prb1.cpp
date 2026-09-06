/*
 File: prb1.cpp
 Description: A simple problem-solving exercise in C++.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
#include <cstdlib>
using namespace std;
int GenerateRandNum(int FROM,int TO){
    return rand() % (TO - FROM + 1) + FROM;
}
void FillArray(int array[3][3]){
    for (int x = 0 ; x <= 2 ; x++){
        for (int a = 0 ;a<=2;a++){
            array[x][a] = GenerateRandNum(0,100);
        }
    }    
}
int main()
{
    srand((unsigned)time(NULL));
    int array[3][3];
    FillArray(array);
    cout << "The Array Is : "<<endl;
    for (int x = 0 ; x <= 2 ; x++){
        cout <<endl;
        for (int a = 0 ; a<= 2 ; a++){
            cout <<"  " <<array[x][a];
        }
    }  
    return 0;
}