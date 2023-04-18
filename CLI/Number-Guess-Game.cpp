#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    int secret_number = rand() % 100 + 1;
    int guess;

    do {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        if (guess < secret_number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secret_number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations, you guessed the number!" << endl;
        }
    } while (guess != secret_number);

    return 0;
}
