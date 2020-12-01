#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
    const vector<int> coins = {1, 3, 4};
    vector<int> dp(m + 1, 1e6);

    dp[0] = 0;
    for (int i = 1; i <= m; ++i)
        for (int c : coins)
            if (i >= c)
                dp[i] = min(dp[i], dp[i - c] + 1);
    return dp[m];
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
