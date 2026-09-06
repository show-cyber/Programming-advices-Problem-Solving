/*
 File: prb4.cpp
 Description: A basic C++ exercise focused on logic and output.
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
void FillArray(int array[3][3]) {
	for (int x = 0 ; x <= 2 ; x++) {
		for (int a = 0 ; a<=2; a++) {
			array[x][a] = GenerateRandNum(0,100);
		}
	}
}
void SumOfColones(int array[3][3],int ColonesCounter[3]) {
	int ColonesSum = 0;
	for (int x = 0 ; x<= 2 ; x++){
	    for (int a = 0 ; a <= 2 ;a++){
	        ColonesSum = ColonesSum + array[a][x];
	    }
		ColonesCounter[x]= ColonesSum;
		ColonesSum = 0;
	}
}
void PrintSumOfColones(int RowCounter[3]) {
	cout << "\nThe Following is the sum of each Colone in the matrix :"<<endl;
	for (int a = 0 ; a <= 2 ; a++) {
		cout <<setw(5) <<"   Colone   "<< a << " : "<< RowCounter[a] <<endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int array[3][3];
	FillArray(array);
	int ColonesCounter[3];
	cout << "The Array Is : "<<endl;
	for (int x = 0 ; x <= 2 ; x++) {
		cout <<endl;
		for (int a = 0 ; a<= 2 ; a++) {
			cout <<setw(5)<<array[x][a];
		}
	}
	SumOfColones(array,ColonesCounter);
	PrintSumOfColones(ColonesCounter);
	return 0;
}