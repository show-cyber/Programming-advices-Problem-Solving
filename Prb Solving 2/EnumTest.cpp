#include <iostream>

using namespace std;

enum Gender {Male, Famele};
enum FavoritColor {Red, Blue, Green};
enum type {Married, single};

struct MyInfo
{
    string Name;
    int age;
    string City;
    string Country;
    int MonthlySalary;
};

int main()
{
    MyInfo Info ;
    Info.Name = "Mohamed Abu-Hadhoud";
    Info.age = 44 ;
    Info.City = "Amman";
    Info.Country = "Jordan" ;
    Info.MonthlySalary = 5000;
    
    Gender Mygender;
    FavoritColor Mycolor;
    type Mytype;
    
    Mygender = Gender::Male ;
    Mycolor = FavoritColor::Green ;
    Mytype =  type::Married ;
    
    cout <<"***************************************************"<<endl;
    cout <<"My Name : "<< Info.Name<<endl ;
    cout <<"My age : "<< Info.age<<endl ;
    cout <<"My City : "<<Info.City<<endl;
    cout <<"My Country : "<<Info.Country<<endl;
    cout <<"My MonthlySalary : "<<Info.MonthlySalary<<endl;
    cout <<"My Gender : "<<Mygender<<endl;
    cout <<"My FavoritColor : "<< Mycolor<<endl;
    cout <<"My Type : "<<Mytype <<endl;
    cout <<"****************************************************"<<endl;
    return 0;
    
    
}