/*
 File: ArraysSum.cpp
 Description: Calculates and prints the sum of values in an array.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


    int ReadNumber(int number){
        do {
            cout << "Enter Positive number !"<<endl;
            cin >> number ;
        } while (number <= 0);
        return number;
    }
    
    
   void GenerateRandNum(int number, int arr[100]){
       int counter = 0;
    for (int x = 0 ; x <= number - 1 ; x++){
        arr[x] = rand() % (100 - 1 + 1) + 1 ;
        cout << arr[x]<< " ";
        counter += arr[x];
    }
    cout <<endl<< "Sum of Numbers is : "<<counter;
   }
   

int main()
{
    srand((unsigned)time(NULL));
    int number;
    int arr[100];
   int n = ReadNumber(number);
   cout << "Array Element : ";
   GenerateRandNum(n, arr);
    return 0;
}