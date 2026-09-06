/*
 File: ScisorPaperStonGame.cpp
 Description: Creates a simple rock-paper-scissors game.
 Purpose: This program was written to practice C++ logic, problem solving, and coding fundamentals.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
enum GameType {
	Scissor = 0,
	Ston = 1,
	Paper = 2
};
int ReadRounds() {
	int Rounds = 0;
	do {
		cout << "_______________________________________\n How Many Rounds You Want to Play ?"<<endl;
		cin >> Rounds;
	} while (Rounds <= 0);
	return Rounds;
}
int GetCompInput() {
	int CompInput = rand() % 3;
	return CompInput;
}
void StartRound(int Rounds) {
	int ComCounter = 0;
	int Counter = 0;
	int PlayerInput;
	for (int f = 0 ; f < Rounds ; f++) {
	    int CompInput = GetCompInput();
		cout << "*************************************"<<endl;
		cout << "\t\tRound "<< f + 1 << endl;
		cout << "Chose : Scissor = 0 , Ston = 1 , Paper = 2 !"<<endl;
		cin >> PlayerInput;
		switch (PlayerInput) {
		case Scissor :
			if (CompInput == Scissor) {
				cout << "The Computer Chose : Scissor\a\n No One Win"<<endl;
				break;
			}
			if (CompInput == Ston) {
				cout << "The Computer Chose : Ston \a\n The Computer Win"<<endl;
				ComCounter++;
				break;
			}
			if (CompInput == Paper) {
				cout << "The Computer Chose : Paper \a\n You Win"<<endl;
				Counter++;
				break;
			}
		case Ston :
			if (CompInput == Scissor) {
				cout << "The Computer Chose : Scissor\a\n You Win"<<endl;
				Counter++;
				break;
			}
			if (CompInput == Ston) {
				cout << "The Computer Chose : Ston \a\n No One Win"<<endl;
				break;
			}
			if (CompInput == Paper) {
				cout << "The Computer Chose : Paper \a\n The Computer Win"<<endl;
				ComCounter++;
				break;
			}
		case Paper :
			if (CompInput == Scissor) {
				cout << "The Computer Chose : Scissor\a\n The Computer Win"<<endl;
				ComCounter++;
				break;
			}
			if (CompInput == Ston) {
				cout << "The Computer Chose : Ston \a\n You Win"<<endl;
				Counter++;
				break;
			}
			if (CompInput == Paper) {
				cout << "The Computer Chose : Paper \a\n No One Win"<<endl;
				break;
			}
		}
	}
	cout << "\t \t \tGame Result  Is : \n Computer : "<< ComCounter << "\n You : "<<Counter<<endl;
}
void AskIfRepeat() {
	char Choise = 0;
	cout << "\tDo You Want to Play Again[ Y,y / N,n ]?????????????";
	cin >> Choise;
	if (Choise == 'Y' || Choise == 'y') {

	}
}
int main() {
	char Choice;
	do
	{
	    int NumberOfRounds = ReadRounds();
		StartRound(NumberOfRounds);

		cout << "\nDo You Want to Play Again? [Y/y - N/n]: ";
		cin >> Choice;

	} while (Choice == 'Y' || Choice == 'y');
	return 0;
}