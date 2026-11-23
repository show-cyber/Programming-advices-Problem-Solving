#include <iostream>
#include <string>
using namespace std;
struct Date {
	short Year = 0;
	short Month = 0;
	short Day = 0;
};
Date ReadDate(Date &date1) {
	cout << "Enter a Year :";
	cin >> date1.Year;
	cout << "\nEnter a Month :";
	cin >> date1.Month;
	cout << "\nEnter a Day :";
	cin >> date1.Day;
	return date1;
}
bool isleapyear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short NumberOfDaysInMonth(short year,short month) {
	return (month == 2) ? (isleapyear(year) ? 29:28): (month == 1 || month == 3 || month == 5 ||month == 7 || month ==8||month==10||month==12) ? 31 : 30;
}
bool IsLastMonthInYear(Date date1) {
	return (date1.Month == 12) ?  true :  false ;
}
bool IsLastDayInMonth(Date date1) {
	short TotalDaysInMonth = NumberOfDaysInMonth(date1.Year,date1.Month);
	return (date1.Day == TotalDaysInMonth) ?  true :  false;
}
int main () {
	Date date1;
	date1 = ReadDate(date1);
    if (IsLastMonthInYear(date1)){
        cout << "\nYes Its the last Month in the year ";
    }
    if (IsLastDayInMonth(date1)){
        cout << "\n Yes Its the last day in the month";
    }
	return 0;
}

