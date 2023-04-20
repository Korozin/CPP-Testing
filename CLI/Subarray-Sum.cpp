#include <iostream>
#include <vector>

using namespace std;

vector<int> findSubarray(vector<int>& arr, int target) {
    int n = arr.size();
    int start = 0, end = 0, sum = 0;
    vector<int> result;

    while (end < n) {
        sum += arr[end];
        while (sum > target) {
            sum -= arr[start];
            start++;
        }
        if (sum == target) {
            result.push_back(start);
            result.push_back(end);
            return result;
        }
        end++;
    }
    result.push_back(-1); // If no subarray is found
    result.push_back(-1);
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int target = 12;

    vector<int> result = findSubarray(arr, target);

    if (result[0] == -1) {
        cout << "No subarray found";
    } else {
        cout << "Subarray found from index " << result[0] << " to " << result[1];
    }
    return 0;
}
