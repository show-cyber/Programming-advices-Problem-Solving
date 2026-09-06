/*
 File: Calculator.cpp
 Description: Implements a basic calculator using arithmetic operators.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
using namespace std;

void MYcalculator()
{
    int Num1, Num2;
    char Operator;
    cout << "Enter The Operator : /  -  +  *  "<<endl;
    cin >> Operator ;
    cout <<"Enter First Number : " <<endl;
    cin >> Num1 ;
    cout << "Enter Second Number : "<<endl;
    cin >> Num2 ;
    switch (Operator)
{
    case '/':
    cout << Num1 / Num2 ;
    break;
    case '*':
    cout << Num1 * Num2 ;
    break;
    case '-':
    cout << Num1 - Num2 ;
    break;
    case '+':
    cout << Num1 + Num2 ;
    break;
    default :
    cout << "Incorrect Oprator !";
}
}
int main()
{
    MYcalculator();
    return 0;
}