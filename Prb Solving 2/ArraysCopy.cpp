/*
 File: ArraysCopy.cpp
 Description: Copies elements from one array to another using C++ logic.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;


    int ReadNumber(int& number){
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
    }
    
   }
   
   
    void tempe (int number ,int arr[100]){
        int arr2[100];
        int temp;
        
        for (int g = 0 ; g <= number ;g++){
            arr2[g] = arr[g];
        }
        cout <<endl<< "Array 2 copy : ";
        for (int b = 0 ; b<= number - 1; b++){
            cout << arr2[b] << " " ;
        }
    }
   
   
int main()
{
    srand((unsigned)time(NULL));
    int number;
    int arr[100];
    int arr2[100];
   int n = ReadNumber(number);
   cout << "Array Element : ";
   GenerateRandNum(n, arr);
   
   tempe(number , arr);
    return 0;
}
