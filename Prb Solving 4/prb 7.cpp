#include <iostream>
#include <string>
#include <cmath>
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
	} while(!(num >= 0 || num <= 12));
	return num;
}
short ReadDay(){
    short day = 0 ;
    do {
        cout << "\nEnter a day :";
        cin >> day;
    }while (day > 31 || day <= 0);
    return day;
}
string PrintDate(short year,short month,short day){
    char sep = '/';
    string a =  to_string(year) + sep+ to_string(month) + sep + to_string(day);
    return a;
}
short GetDayOrder(short year,short month,short day){
    auto a = 0,y = 0,m = 0;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12*a) - 2;
    return (day + y +(y/4)-(y/100)+(y/400)+((31*m) / 2)) % 7;
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
        default: return 0; break;
    }
    return 0;
}
int main()
{
	short year = ReadYear();
	short month = ReadMonth();
    short day = ReadDay();
    cout << "\n\nDate : "<<PrintDate(year,month,day);
    short dayorder = GetDayOrder(year,month,day);
    cout <<"\n\nDay Order : "<< dayorder ;
    cout<< "\n\nDay Name : "<< GetDayName(dayorder);
	return 0;
}