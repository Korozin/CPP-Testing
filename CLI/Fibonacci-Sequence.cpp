#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter a number to generate the Fibonacci sequence up to: ";
    cin >> n;

    int prev = 0;
    int curr = 1;

    while (prev + curr <= n) {
        int next = prev + curr;
        cout << next << " ";

        prev = curr;
        curr = next;
    }

    return 0;
}
