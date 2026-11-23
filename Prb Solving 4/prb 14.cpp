#include <iostream>
#include <string>
using namespace std;
struct Date {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};
Date ReadDate(Date &date1){
    cout << "Enter a Year :";
    cin >> date1.Year;
    cout << "\nEnter a Month :";
    cin >> date1.Month;
    cout << "\nEnter a Day :";
    cin >> date1.Day;
    return date1;
}
bool DateIsEqualToDate2(Date date1, Date date2){
    return (date1.Year == date2.Year) ? ((date1.Month == date2.Month) ? ((date1.Day == date2.Day) ? return false : return false) : return false) : return false ;
}
int main (){
    Date date1,date2;
    date1 = ReadDate(date1);
    date2 = ReadDate(date2);
    if (DateIsEqualToDate2(date1,date2){
        cout << "\n they are equals";
    } else { cout << "\n not equals"; }
    return 0;
}