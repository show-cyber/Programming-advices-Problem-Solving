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
	cout << "\nMatrix2 :"<<endl;
	for (int x = 0 ; x <= 2 ; x++) {
		cout <<endl;
		for (int a = 0 ; a<= 2 ; a++) {
			cout << setfill('0') << setw(2) << array2[x][a]<<"    ";
		}
	}
}
void MultipleMatrixs(int array1[3][3],int array2[3][3],int array3[3][3]){
    for(int a = 0 ; a <= 2;a++){
        for (int x = 0 ; x<= 2 ;x++){
            array3[a][x] = array1[a][x] * array2[a][x];
        }
    }
}
void PrintTheMultipleOfMatrixs(int array3[3][3]){
    cout << "\nThe Multiple Of Matrixes is : "<<endl;
    for(int a = 0 ; a <= 2;a++){
        for (int x = 0 ; x<= 2 ;x++){
            cout << setfill('0') << setw(2) << array3[a][x] <<"    ";
        }
        cout <<endl;
    }
}
int main()
{
	srand((unsigned)time(NULL));
	int array1[3][3];
	int array2[3][3];
	int array3[3][3];
	FirstMatrix(array1);
	PrintFirstMatrix(array1);
	SecondMatrix(array2);
	PrintSecondMatrix(array2);
	MultipleMatrixs(array1,array2,array3);
	PrintTheMultipleOfMatrixs(array3);
	return 0;
}