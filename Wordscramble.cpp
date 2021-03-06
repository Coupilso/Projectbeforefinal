// Wordscramble.cpp : Defines the entry point for the console application.
//
//Variables that we are going to be used through out the program

#include "stdafx.h"
#include "iostream"
#include "string"
#include "cstdlib"
#include "ctime"

using namespace std;



int main()
{
	char playAgain; // picks if the user wants to play again or not
	enum fields { WORD, HINT, NUM_FIELDS }; // Enumerator
	const int NUM_WORDS = 10; // Number of words that are being used  
							  //Words and Hints  
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "Remote","Something you change the TV with " },
	{ "Boston","Where the most hated Football is" },
	{ "Overwatch","Blizards first FPS game" },
	{ "Car","VROM VROM" },
	{ "Field Goal","And the Extra " },
	{ "Raptor","A type of dinosaur" },
	{ "Churro","A Deliousus Mexican Treat " },
	{ "Broom","Sweap the floor " },
	{ "Defence","What crowds at sports games yell really loud " },
	{ "Picture","To help keep the memory" }
	};
	//Start of randomazation
	srand(static_cast<unsigned int>(time(0)));
	//Welcoming user to the Program 
	cout << "\nWelcome to Unscramble the Word!\n";
	cout << "\nThe end goal is to Unscramble the 3 words that are going to apear.\n";
	cout << "\nGood Luck!\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	do // Do at least once, restart point if user wants to play again.
	{
		int word1Attempts = 0; //Attempts for the first word 
		int word2Attempts = 0; //Attempts for the second word 
		int word3Attempts = 0; //Attempts for the third word 

							   // This runs the program 3 times, and resets the variables each time a new word is choosen
		for (int goodAnswers = 0; goodAnswers < 3; goodAnswers++)
		{
			// Chooses a random word from the list of words 
			int choice = (rand() % NUM_WORDS);
			// Word(s) to guess 
			string theWord = WORDS[choice][WORD];
			// TO ask for hint for word 
			string theHint = WORDS[choice][HINT];
			// jumpled version of Word
			string jumble = theWord;
			// Size of the word 
			int length = jumble.size();
			// Loop jumbles the word 
			for (int i = 0; i < length; ++i)
			{
				// This makes index1 a random number 
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}
			// Stores users input
			string guess;
			// Displays jumbled word
			cout << "The jumbled word is " << jumble << "\n";
			cout << "\n\nYour guess:";
			// Guess User enters 
			cin >> guess;

			//This changes between words, and stores the number of guesses that the user has done 
			if (goodAnswers == 0)
			{
				word1Attempts++;
			}
			else if (goodAnswers == 1)
			{
				word2Attempts++;
			}
			else if (goodAnswers == 3)
			{
				word3Attempts++;
			}
			// Main loop for program
			while ((guess != theWord) && (guess != "quit"))
			{
				//If user use hint for to hint for word
				if (guess == "hint")
				{
					//Displays hint
					cout << theHint;
				}
				else // if answer isn't correct
				{
					cout << "Sorry, that's not it.\n Try again";
				}
				cout << "\n\nYour guess:";
				//Inserts Guess
				cin >> guess;
				if (goodAnswers == 0) // go here if you are on first word
				{
					word1Attempts++; // Add 1 to number of attempts
				}
				else if (goodAnswers == 1) // go here if you are on second word
				{
					word2Attempts++; // Add 1 to number of attempts
				}
				else if (goodAnswers == 2) // go here if you are on third word
				{
					word3Attempts++; // Add 1 to number of attempts
				}
			}
			//This changes between words, and stores the number of guesses that the user has done if the answer is correct 
			if (guess == theWord)
			{
				cout << "\nCongrats! You guessed it!\n";
				if (goodAnswers == 0)
				{
					cout << "It took you " << word1Attempts << " to unscramble this word.\n\n";
				}
				else if (goodAnswers == 1)
				{
					cout << "It took you" << word2Attempts << " to unscramble this word.\n\n";
				}
				else if (goodAnswers == 2)
				{
					cout << "It took you" << word3Attempts << " to unscramble this word.\n\n";
				}
			}
		}
		//End of the program 
		cout << "You have Unscrambled the 3 words\n";
		cout << "Guess Per Word: \n" << "Word 1: " << word1Attempts << "\nWord 2: " << word2Attempts << "\nWord 3: " << word3Attempts << endl; \
			cout << "Would you like to play again (Y/N)?\n";
		cin >> playAgain; // user choses if they want to play again
		while ((playAgain != 'Y') && (playAgain != 'y') && (playAgain != 'N') && (playAgain && 'n'))
		{
			cout << "Invalid Input\nWould you like to play again (Y/N)?";
			cin >> playAgain;
		}
	} while (playAgain == 'y' || playAgain == 'Y');
	cout << "Thanks for playing!\n";

	system("pause");
    return 0;
}

