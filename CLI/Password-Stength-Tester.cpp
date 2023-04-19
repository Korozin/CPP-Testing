#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct PasswordStrengthResult {
    string password;
    int length;
    double entropy;
    string strength;
    string time_to_crack;
};

PasswordStrengthResult evaluate_password_strength(string password) {
    // calculate the length of the password
    int length = password.length();

    // calculate the entropy of the password
    double entropy = 0;
    for (char c : password) {
        if (islower(c)) {
            entropy += log2(26);
        } else if (isupper(c)) {
            entropy += log2(26);
        } else if (isdigit(c)) {
            entropy += log2(10);
        } else if (ispunct(c)) {
            entropy += log2(32);
        }
    }

    // calculate the estimated time to crack the password
    double seconds_to_crack = pow(2, entropy) / 1e9; // assuming 1 billion guesses per second

    // convert the estimated time to crack to a human-readable format
    string time_to_crack;
    if (seconds_to_crack < 60) {
        time_to_crack = to_string(seconds_to_crack) + " seconds";
    } else if (seconds_to_crack < 60 * 60) {
        time_to_crack = to_string(seconds_to_crack / 60) + " minutes";
    } else if (seconds_to_crack < 60 * 60 * 24) {
        time_to_crack = to_string(seconds_to_crack / (60 * 60)) + " hours";
    } else {
        time_to_crack = to_string(seconds_to_crack / (60 * 60 * 24)) + " days";
    }

    // determine the strength of the password
    string strength;
    if (entropy < 28) {
        strength = "very weak";
    } else if (entropy < 36) {
        strength = "weak";
    } else if (entropy < 60) {
        strength = "reasonable";
    } else if (entropy < 128) {
        strength = "strong";
    } else {
        strength = "very strong";
    }

    // return a struct containing the password evaluation results
    return { password, length, entropy, strength, time_to_crack };
}

int main() {
    // prompt the user for a password to evaluate
    string password;
    cout << "Enter a password to evaluate: ";
    cin >> password;

    // evaluate the password and print the results
    PasswordStrengthResult result = evaluate_password_strength(password);
    cout << "Password: " << result.password << endl;
    cout << "Length: " << result.length << endl;
    cout << "Entropy: " << result.entropy << endl;
    cout << "Strength: " << result.strength << endl;
    cout << "Time to crack: " << result.time_to_crack << endl;

    return 0;
}
