#include <iostream>
#include <string>
using namespace std;
bool isleapyear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short ReadNumber()
{
	short num = 0;
	cout << "Enter a year :";
	cin >> num;
	return num;
}
short ReadMonth() {
	short num = 0;
	do {
		cout << "\nEnter a Month :";
		cin >> num;
	} while(!(num >= 0 || num <= 12));
	return num;
}
short NumberOfDaysInMonth(short year,short month) {
	return (month == 2)
	?(isleapyear(year) ? 29:28)
	: (month == 1 || month == 3 || month == 5 ||month == 7 || month ==8||month==10||month==12) ? 31 : 30;
}
int main()
{
	short year = ReadNumber();
	short month = ReadMonth();
	cout << "\nNumber Of Days In This Month is : "<<  NumberOfDaysInMonth(year,month);
	return 0;
}