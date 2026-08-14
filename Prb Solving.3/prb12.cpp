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
void SecondMatrix(int array2[3][3]) {
	for (int x = 0 ; x <= 2 ; x++) {
		for (int a = 0 ; a<=2; a++) {
			array2[x][a] = GenerateRandNum(1,10);
		}
	}
}
void PrintSecondMatrix(int array2[3][3]) {
	cout << "\n\nMatrix2 :"<<endl;
	for (int x = 0 ; x <= 2 ; x++) {
		cout <<endl;
		for (int a = 0 ; a<= 2 ; a++) {
			cout << setfill('0') << setw(2) << array2[x][a]<<"    ";
		}
	}
}
void CompareMatrixs(int array1[3][3],int array2[3][3]){
    int Counter  = 0;
    int Counter2 = 0;
    for (int a = 0 ; a<= 2 ;a++){
        for (int x = 0 ; x<= 2 ; x++){
            if (array1[x][a] != array2[x][a]){
                cout << "\nMatrix Are Not equal :("<<endl;
                return;
            }
        }
    }
}
int main()
{
	srand((unsigned)time(NULL));
	int array1[3][3];
	int array2[3][3];
	
	FirstMatrix(array1);
	PrintFirstMatrix(array1);
	SecondMatrix(array2);
	PrintSecondMatrix(array2);
	CompareMatrixs(array1,array2);
	return 0;
}