#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // target not found
}

int main() {
    // example input
    vector<int> nums = {1, 2, 4, 7, 9, 11};
    int target = 4;

    int index = binarySearch(nums, target);

    if (index == -1) {
        cout << "Target not found" << endl;
    } else {
        cout << "Target found at index " << index << endl;
    }

    return 0;
}
