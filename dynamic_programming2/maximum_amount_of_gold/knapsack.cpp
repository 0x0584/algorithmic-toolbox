#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int> &A) {
    const int n = A.size();
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int wi = A[i - 1];
        for (int w = 1; w <= W; ++w) {
            dp[w][i] = dp[w][i - 1];
            if (wi <= w) {
                int tmp = dp[w - wi][i - 1] + wi;
                if (dp[w][i] < tmp)
                    dp[w][i] = tmp;
            }
        }
    }
    return dp[W][n];
}

int main() {
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    // int W = 10;
    // vector<int> w = {1, 4, 8};
    cout << knapsack(W, w) << endl;
}
