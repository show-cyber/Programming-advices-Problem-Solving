#include <iostream>
using namespace std;

int main()
{
    string word;
    int counter = 0;
    string password;
    
    cout << "Enter a strong password witch 3 lettres !"<<endl;
    cin >> password ;
    
    for (int x = 65 ; x < 90 ; x++){
        for (int  k = 65 ; k < 90 ; k++){
            for (int a = 65 ; a < 90 ; a++){
                counter++;
                word = word + char(x);
                word = word + char(k);
                word = word + char(a);
                
                if (password == word){
                    cout << "Trial [" <<  counter << "] : "<< word <<endl;                 
                    cout << "password is : "<< word <<endl;
                    cout << "Founed after : " << counter << " Trial(s)";
                    return 1 ;
                    break;
                    
                } else {
                    cout << "Trial [" << counter << "] :"<< word <<endl; 
                }
                word = "";
            }
        }
    }

    return 0;
}