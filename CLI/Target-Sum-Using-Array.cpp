#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, target;
    cout << "Enter the number of integers: ";
    cin >> n;
    int nums[n];
    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the target integer: ";
    cin >> target;
    unordered_map<int, int> indices;
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (indices.count(complement)) {
            cout << "Indices: " << indices[complement] << " " << i << endl;
            return 0;
        }
        indices[nums[i]] = i;
    }
    cout << "No two numbers in the array add up to the target integer." << endl;
    return 0;
}
