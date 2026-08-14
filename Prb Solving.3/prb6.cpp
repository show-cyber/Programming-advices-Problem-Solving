#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
int GenerateRandNum(int FROM,int TO) {
	return rand() % (TO - FROM + 1) + FROM;
}
void FillArrayWitchOrderNumbers(int array[3][3]) {
    int counter = 1;
	for (int x = 0 ; x <= 2 ; x++) {
		for (int a = 0 ; a<=2; a++) {
			array[x][a] = counter;
			counter++;
		}
	}
}
void PrintarrayWitchOrdNumbers(int array[3][3]){
    cout << "The Array Is : "<<endl;
	for (int x = 0 ; x <= 2 ; x++) {
		cout <<endl;
		for (int a = 0 ; a<= 2 ; a++) {
			cout <<setw(5)<<array[x][a];
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int array[3][3];
	FillArrayWitchOrderNumbers(array);
	PrintarrayWitchOrdNumbers(array);
	return 0;
}