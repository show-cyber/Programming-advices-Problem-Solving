#include <iostream>
#include <string>
using namespace std;
struct Date {
    short Year = 0;
    short Month = 0;
    short Day = 0;
}
void ReadDate(Date &date1,Date &date2){
    cout << "Enter a Year :";
    cin >> date1.Year;
    cout << "\nEnter a Month :";
    cin >> date1.Month;
    cout << "\nEnter a Day :";
    cin >> date1.Day;
    cout << "\n\nEnter a Year :";
    cin >> date2.Year;
    cout << "\nEnter a Month :";
    cin >> date2.Month;
    cout << "\nEnter a Day :";
    cin >> date2.Day;
}
bool Date1IsLessThenDate2(Date date1,Date date2){
    return (date1.Year < date2.Year) ? return true : ((date1.Month < date2.Month) ? true : (date1.Day < date2.Day) ? true : false); 
}
int main (){
    Date date1,date2;
    ReadDate(date1,date2);
    Date1IsLessThenDate2(date1,date2);
    return 0;
}