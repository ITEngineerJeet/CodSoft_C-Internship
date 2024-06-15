
/*  TASK-1 : THE NUMBER GUESSING GAME 

Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//The Function to Play the Guess the Number Game 

void playgame(int maxTries) 
{
    srand(static_cast<unsigned int>(time(0))); // seed the random number generator
    int secretNumber = rand() % 100 + 1; // generate secret number between 1 and 100
    int guess; // The user will guess the number 
    
    cout << "\nWelcome to GuessTheNumber game!\n";
    cout << "Guess a number between 1 and 100. You have " << maxTries << " tries.\n";

    for (int tries = 1; tries <= maxTries; ++tries) 
	{
        cout << "\nEnter guess " << tries << ": ";
        cin >> guess;

        if (guess == secretNumber) 
		{
            cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << tries << " tries!\n";
            return;
        } else if (guess < secretNumber) 
		{
            cout << "Too low. ";
        } else 
		{
            cout << "Too high. ";
        }
        cout << "Try again.\n";
    }

    cout << "Out of tries. The secret number was " << secretNumber << ". Game over!\n";
}

//The Function to Guess the Number 

void guess_the_number()
{
	int difficulty;
    
    while (true) 
	{
        cout << "\nChoose difficulty level:\n";
        cout << "1. Easy (10 tries)\n";
        cout << "2. Medium (7 tries)\n";
        cout << "3. Hard (5 tries)\n";
        cout << "0. Quit\n";
        cout << "Enter your choice: ";
        cin >> difficulty;

        switch (difficulty) 
		{
            case 1:
                playgame(10);
                break;
            case 2:
                playgame(7);
                break;
            case 3:
                playgame(4);
                break;
            case 0:
                cout << "Thanks for playing. Goodbye!\n";
            default:
                cout << "Invalid choice. Please enter a number between 0 and 3.\n";
        }
    }
}

//The Main Function 

int main() 
{
    guess_the_number();
    return 0;
}

