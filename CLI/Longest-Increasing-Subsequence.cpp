#include <iostream>
#include <vector>
#include <algorithm>

int longestIncreasingSubsequence(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> dp(n, 1);  // dp[i] = length of LIS ending at index i
    int maxLen = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLen = std::max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    std::vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << longestIncreasingSubsequence(nums) << std::endl;  // Output: 4
    return 0;
}
