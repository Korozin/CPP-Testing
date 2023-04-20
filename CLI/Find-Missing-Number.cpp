#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = ((n + 1) * (n + 2)) / 2; // sum of first n natural numbers
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    return sum - actualSum;
}

int main() {
    vector<int> nums = {1, 2, 4, 5, 6};
    int missingNumber = findMissingNumber(nums);
    cout << "The missing number is " << missingNumber << endl;
    return 0;
}
