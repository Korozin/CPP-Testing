#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    string word_bank[] = {"apple", "banana", "cherry", "grape", "orange", "peach", "pear", "pineapple", "watermelon"};
    int num_words = sizeof(word_bank) / sizeof(word_bank[0]);
    string secret_word = word_bank[rand() % num_words];
    int num_guesses = 0;
    int max_guesses = secret_word.length() * 2;

    string guessed_letters(secret_word.length(), '_');

    cout << "Welcome to the Word Guessing Game!" << endl;
    cout << "You have " << max_guesses << " guesses to guess the word." << endl;

    while (num_guesses < max_guesses) {
        cout << "Current word: " << guessed_letters << endl;
        cout << "Guess a letter: ";
        char guess;
        cin >> guess;

        bool found_letter = false;
        for (int i = 0; i < secret_word.length(); i++) {
            if (secret_word[i] == guess) {
                guessed_letters[i] = guess;
                found_letter = true;
            }
        }

        if (found_letter) {
            cout << "Good guess!" << endl;
        } else {
            cout << "Sorry, that letter is not in the word." << endl;
            num_guesses++;
        }

        if (guessed_letters == secret_word) {
            cout << "Congratulations, you guessed the word!" << endl;
            return 0;
        }
    }

    cout << "Sorry, you did not guess the word. The word was " << secret_word << "." << endl;
    return 0;
}
