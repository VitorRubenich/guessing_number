#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "guessing_game.h"

using namespace std;



int main()
{
	int exit_game = false;
	int dificulty_choice;
	int guess;
	
	/*  Allow the user to play multiple rounds of the game (i.e., keep playing until the user decides to quit). 
		You can do this by asking the user if they want to play again after each round.
	*/
	do{
		//reset
		int choices_left = 0;
		bool win = false;
		welcome_message();
		
		//The computer should randomly select a number between 1 and 100.
		srand(time(NULL));
		int rand_number = (rand() % 100) + 1;
		
		// User should select the difficulty level (easy, medium, hard) which will determine the number of chances they get to guess the number.
		do{
			cout << "Enter your choice: ";
			cin >> dificulty_choice;
		}while(dificulty_choice < 1 || dificulty_choice > 3);
		choices_left = dificulty_choice_message(dificulty_choice);
	
		
		do{
			//TODO The user should be able to enter their guess.
			cout << "\nEnter your guess: ";
			cin >> guess;
			choices_left--;
			win = check(guess, rand_number, choices_left, dificulty_choice);
			if(win){
				choices_left = 0;
			}
		}while(choices_left >= 1 || !win);
		
		
		// do you want to play again?
		cout << "Do you wanna play another game? (0 -> No - 1 -> Yes)";
		cin >> exit_game;
		
	}while(exit_game);

}

// When the game starts, it should display a welcome message along with the rules of the game.
void welcome_message(){
	cout << "\n\nWelcome to the Number Guessing Game!\nI'm thinking of a number between 1 and 100.\n";

	cout << "Please select the difficulty level:\n1. Easy (10 chances)\n2. Medium (5 chances)\n3. Hard (3 chances)\n\n";
}
/*  Check if game is end 
	return the result of the check (if game is win)
*/
bool check(int guess, int rand_number, int choices_left, int dificulty){
	if(guess == rand_number){
		// If the user’s guess is incorrect, the game should display a message indicating whether the number is greater or less than the user’s guess.
		int aux = 0;
		switch(dificulty){
			case 1:
				aux = 10;
				break;
			case 2:
				aux = 5;
				break;
			case 3:
				aux = 3;
				break;
			default: break;
		}
		cout << "Congratulations! You guessed the correct number with " << (aux - choices_left) << " attempts.";
		return true;
	}else{
		cout << "Incorrect! The number is " << (guess > rand_number ? "less than " : "greater than ") << guess << ".\n";
		// If the user’s guess is incorrect, the game should display a message indicating whether the number is greater or less than the user’s guess.
		return false;
	}
}
/*  Receive a input thats correspond the game dificulty
*/
int dificulty_choice_message(int choice){
	switch(choice){
		case 1:
			cout << "Great! You have selected the Easy difficulty level.\n";
			return 10;
			break;
		case 2:
			cout << "Great! You have selected the Medium difficulty level.\n";
			return 5;
			break;
		case 3:
			cout << "Great! You have selected the Hard difficulty level.\n";
			return 3;
			break;
		default: break;	
	}
	cout << "Let's start the game!";
}
