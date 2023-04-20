#include <iostream>
#include <string>

using namespace std;

bool containsDigit(int number, int digit) {
    while (number > 0) {
        if (number % 10 == digit) {
            return true;
        }
        number /= 10;
    }
    return false;
}

int main() {
    for (int i = 1; i <= 100; i++) {
        string output = "";
        if (i % 3 == 0 || containsDigit(i, 3)) {
            output += "Fizz";
        }
        if (i % 5 == 0 || containsDigit(i, 5)) {
            output += "Buzz";
        }
        if (output == "") {
            output = to_string(i);
        }
        cout << i << ": " << output << endl;
    }
    return 0;
}
