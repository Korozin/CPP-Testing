#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    int n = str.length();
    bool isPalindrome = true;
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-i-1]) {
            isPalindrome = false;
            break;
        }
    }
    
    if (isPalindrome) {
        cout << str << " is a palindrome" << endl;
    } else {
        cout << str << " is not a palindrome" << endl;
    }
    
    return 0;
}
