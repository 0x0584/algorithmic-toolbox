#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit(const string &s1, const string &s2, int n, int m) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    for (int i = 0; i <= int(s1.size()); ++i)
        dp[i][0] = i;
    for (int i = 0; i <= int(s2.size()); ++i)
        dp[0][i] = i;
    for (int i = 1; i <= int(s1.size()); ++i) {
        for (int j = 1; j <= int(s2.size()); ++j) {
            int del = dp[i - 1][j] + 1, ins = dp[i][j - 1] + 1,
                mat = dp[i - 1][j - 1], mismat = dp[i - 1][j - 1] + 1;
            dp[i][j] = min({ins, del, s1[i - 1] == s2[j - 1] ? mat : mismat});
        }
    }
    return dp[s1.size()][s2.size()];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit(str1, str2, str1.size(), str2.size()) << endl;
    return 0;
}
