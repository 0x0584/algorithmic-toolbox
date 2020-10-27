#include <iostream>
#include <vector>

using namespace std;

int lcs2(const vector<int> &a, const vector<int> &b) {
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 1; i <= int(a.size()); ++i) {
        for (int j = 1; j <= int(b.size()); ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[a.size()][b.size()];
}

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    size_t m;
    cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << lcs2(a, b) << endl;
}
