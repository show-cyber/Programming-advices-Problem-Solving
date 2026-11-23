#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
bool isleapyear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short ReadYear()
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
	} while(num < 1 || num > 12);
	return num;
}
short GetDayOrder(short year,short month,short day){
    auto a = 0,y = 0,m = 0;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12*a) - 2;
    return (day + y +(y/4)-(y/100)+(y/400)+((31*m) / 12)) % 7;
}
string GetDayName(short d){
    switch(d){
        case 0: return "Sun"; break;
        case 1: return "Mon"; break;
        case 2: return "Tue"; break;
        case 3: return "Wed"; break;
        case 4: return "Thu"; break;
        case 5: return "Fri"; break;
        case 6: return "Sat"; break;
        default: return "Unknown";
    }
}
short NumberOfDaysInMonth(short year,short month) {
	return (month == 2)
	?(isleapyear(year) ? 29:28)
	: (month == 1 || month == 3 || month == 5 ||month == 7 || month ==8||month==10||month==12) ? 31 : 30;
}
string GetMonthName(short month) {
    string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return months[month - 1];
}
void CreateCalender(short year, short month){
    int currentDay = GetDayOrder(year, month, 1);
    int numberOfDays = NumberOfDaysInMonth(year, month);

    cout << "\n  _________________" << GetMonthName(month) << " " << "_________________\n";
    cout << "    Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    cout << "  ---------------------------------\n  ";

    int i = 0;
    for (i = 0; i < currentDay; i++) {
        cout << "     ";
    }

    for (int day = 1; day <= numberOfDays; day++) {
        cout << setw(5) << day;
        i++;
        
        if (i % 7 == 0 && day != numberOfDays) {
            cout << "\n  ";
        }
    }

    cout << "\n  _________________________________\n\n";
}
void PrintYearCalender(short year){
    cout << "----------------"<<year<<"-----------------\n---------------------------------\n\n";
    for (short x = 1 ; x <= 12 ; x++) CreateCalender(year,x);
}
int main()
{
	short year = ReadYear();
	short month = ReadMonth();
    CreateCalender(year,month);
    PrintYearCalender(year);
	return 0;
}