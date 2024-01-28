
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Array of words to be guessed
string words[] = {"apple", "banana", "orange", "grape", "strawberry", "kiwi"};

// Function to randomly choose a word from the array
string chooseWord() {
    srand(time(NULL));
    int randomIndex = rand() % (sizeof(words) / sizeof(words[0]));
    return words[randomIndex];
}

int main() {
    string wordToGuess = chooseWord();
    int length = wordToGuess.length();
    string guessedWord(length, '-'); // A string of dashes of the same length as the word to be guessed
    int attempts = 0;
    bool guessed = false;

    cout << "Welcome to the Guess the Word Game!\n";
    cout << "Try to guess the word. It has " << length << " letters.\n";
    
    while (!guessed && attempts < 10) {
        cout << "Word: " << guessedWord << endl;
        cout << "Attempts left: " << 10 - attempts << endl;
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        
        bool letterGuessed = false;
        for (int i = 0; i < length; ++i) {
            if (wordToGuess[i] == guess) {
                guessedWord[i] = guess;
                letterGuessed = true;
            }
        }
        
        if (!letterGuessed) {
            cout << "Incorrect guess!\n";
            attempts++;
        }
        
        if (wordToGuess == guessedWord) {
            guessed = true;
        }
    }
    
    if (guessed) {
        cout << "Congratulations! You guessed the word: " << wordToGuess << endl;
    } else {
        cout << "Sorry, you ran out of attempts. The word was: " << wordToGuess << endl;
    }

    return 0;
}