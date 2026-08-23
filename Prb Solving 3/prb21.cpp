#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
void Printfibonacciserie(int s) {
	int prv1 = 1, prv2 = 1;
	int num = 0;
	cout << prv1<< " "<<prv2<<" ";
	for (int x = 0 ; x < s - 2; x++) {
		num = prv1 + prv2;
		cout <<num<<" ";
		prv1 = prv2;
		prv2 = num;
	}
}
int main()
{
	Printfibonacciserie(10);
    system("pause>0");
}