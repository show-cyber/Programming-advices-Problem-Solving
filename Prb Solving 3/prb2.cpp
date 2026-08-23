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
void SumOfRows(int array[3][3],int RowCounter[3]) {
	int RowSum = 0;
	for (int x = 0 ; x <= 2 ; x++) {
		for (int a = 0 ; a<=2; a++) {
			RowSum = RowSum +array[x][a];
		}
		RowCounter[x]= RowSum;
		RowSum = 0;
	}
}
void PrintSumOfRows(int RowCounter[3]) {
	cout << "\nThe Following is the sum of each row in the matrix :"<<endl;
	for (int a = 0 ; a <= 2 ; a++) {
		cout <<setw(5) <<"   Row   "<< a << " : "<< RowCounter[a] <<endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int array[3][3];
	FillArray(array);
	int RowCounter[3];
	cout << "The Array Is : "<<endl;
	for (int x = 0 ; x <= 2 ; x++) {
		cout <<endl;
		for (int a = 0 ; a<= 2 ; a++) {
			cout <<setw(5)<<array[x][a];
		}
	}
	SumOfRows(array,RowCounter);
	PrintSumOfRows(RowCounter);
	return 0;
}