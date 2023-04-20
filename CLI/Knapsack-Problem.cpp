#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    int W = 50; // Knapsack capacity
    vector<int> val = {60, 100, 120}; // Value of each item
    vector<int> wt = {10, 20, 30}; // Weight of each item
    int n = val.size(); // Number of items

    cout << "Maximum value that can be obtained = " << knapsack(W, wt, val, n) << endl;

    return 0;
}
