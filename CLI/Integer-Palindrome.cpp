#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int reversed = 0;
    int original = x;
    while (original > 0) {
        reversed = reversed * 10 + original % 10;
        original /= 10;
    }
    return x == reversed;
}

int main() {
    // example inputs
    int x1;
    cout << "Enter a number: ";
    cin >> x1;

    // check if x1 is a palindrome
    if (isPalindrome(x1)) {
        cout << x1 << " is a palindrome" << endl;
    } else {
        cout << x1 << " is not a palindrome" << endl;
    }

    return 0;
}
