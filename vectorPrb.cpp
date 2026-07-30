#include <vector>
#include <iostream>
using namespace std;
struct Employee{
    string Name;
    int Age;
    int MonthlySalary;
};
void ReadEmployee(vector <Employee>&vEmployee){
    Employee Emp;
    char Choise;
    do {
        cout << "Enter your name : ";
        cin >> Emp.Name;
        cout << "\nEnter your age : ";
        cin >> Emp.Age ;
        cout << "\nEnter your MonthlySalary : ";
        cin >> Emp.MonthlySalary;
        vEmployee.push_back(Emp);
        cout << "\n\nDo You want to Enter Another Employee ?"<<endl;
        cin >> Choise;
    } while (Choise == 'Y'||Choise == 'y');
}
void PrintVector(const vector<Employee>&vEmployee){
    cout << "\n\nVector  Composent : \n";
    for (const Employee & num : vEmployee){
        cout <<"\nName : "<<num.Name <<" "
             <<"\nAge : "<<num.Age << " "
             <<"\nMonthlySalary : "<<num.MonthlySalary<<endl;
    };
}
int main(){
    vector<Employee>vEmployee;
    ReadEmployee(vEmployee);
    PrintVector(vEmployee);
    return 0;
}