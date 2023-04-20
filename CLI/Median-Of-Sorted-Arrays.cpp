#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    int i = 0, j = 0, k = 0;
    int merged[n];

    while (i < n1 && j < n2) {
        if (nums1[i] <= nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = nums1[i++];
    }

    while (j < n2) {
        merged[k++] = nums2[j++];
    }

    if (n % 2 == 0) {
        return (double)(merged[n / 2] + merged[n / 2 - 1]) / 2;
    } else {
        return (double)merged[n / 2];
    }
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "Median of combined array is " << median << endl;

    return 0;
}
