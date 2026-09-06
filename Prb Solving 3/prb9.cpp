/*
 File: prb9.cpp
 Description: A small C++ program for practicing fundamentals.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
int GenerateRandNum(int FROM,int TO) {
	return rand() % (TO - FROM + 1) + FROM;
}
void FirstMatrix(int array1[3][3]) {
	for (int x = 0 ; x <= 2 ; x++) {
		for (int a = 0 ; a<=2; a++) {
			array1[x][a] = GenerateRandNum(1,10);
		}
	}
}
void PrintFirstMatrix(int array1[3][3]) {
	cout << "Matrix1 :"<<endl;
	for (int x = 0 ; x <= 2 ; x++) {
		cout <<endl;
		for (int a = 0 ; a<= 2 ; a++) {
			cout << setfill('0') << setw(2) << array1[x][a]<<"    ";
		}
	}
}
void PrintMidleRowAndColone(int array1[3][3]){
    cout << "\nMiddle Colone Of Matrix Is : "<<endl;
    for (int a = 0 ; a<= 2 ;a++){ // row
        cout << setfill('0')<<setw(2)<<array1[1][a] <<"    ";    
    }
    cout <<endl;
    cout << "Middle Row Of Matrix Is : "<<endl;
    for (int a = 0 ; a<= 2 ;a++){ // row
        cout << setfill('0')<<setw(2)<<array1[a][1] <<"    ";    
    }
}
int main()
{
	srand((unsigned)time(NULL));
	int array1[3][3];
	
	FirstMatrix(array1);
	PrintFirstMatrix(array1);
	PrintMidleRowAndColone(array1);
	return 0;
}