#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

typedef long long long2;

using namespace std;

bool is_op(char c) { return c == '\0' || c == '*' || c == '-' || c == '+'; }

long2 eval(long2 a, long2 b, char op) {

    cout << " >>> " << a << op << b << endl;
    if (op == '*')
        return a * b;
    else if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    assert(0);
}

pair<long2, long2> min_max(int i, int j, const vector<pair<long2, char>> &ops,
                           const vector<vector<pair<long2, long2>>> &v) {
    long2 _m = numeric_limits<long2>::max();
    long2 _M = numeric_limits<long2>::min();

    for (int k = i; k < j; ++k) {
        char op = ops[k].second;
        _m = min({_m, eval(v[i][k].first, v[k + 1][j].first, op),
                  eval(v[i][k].second, v[k + 1][j].first, op),
                  eval(v[i][k].first, v[k + 1][j].second, op),
                  eval(v[i][k].second, v[k + 1][j].second, op)});
        _M = max({_M, eval(v[i][k].first, v[k + 1][j].first, op),
                  eval(v[i][k].second, v[k + 1][j].first, op),
                  eval(v[i][k].first, v[k + 1][j].second, op),
                  eval(v[i][k].second, v[k + 1][j].first, op)});

        cout << _m << " | " << _M << endl;
    }

    return {_m, _M};
}

vector<pair<long2, char>> parse_input(const string &s) {
    vector<pair<long2, char>> expr;

    for (int i = 0; i < int(s.size()); ++i) {
        int j = i;
        while (not is_op(s[j]))
            j++;
        expr.push_back({stoll(s.substr(i, j - i)), s[j]});
        i = j;
    }

    return expr;
}

long2 get_maximum_value(const string &exp) {
    vector<pair<long2, char>> expr = parse_input(exp);
    vector<vector<pair<long2, long2>>> v(
        expr.size(), vector<pair<long2, long2>>(expr.size()));

    for (auto e : expr)
        cout << e.first << " " << e.second << "\n";

    for (int k = 0; k < int(v.size()); ++k) {
        v[k][k] = {expr[k].first, expr[k].first};
    }

    for (int s = 0; s < v.size(); ++s) {
        for (int i = 0; i < v.size() - s; ++i) {
            int j = i + s;
            v[i][j] = min_max(i, j, expr, v);
        }
    }
    return v[0][expr.size() - 1].second;
}

int main() {
    string s;
    // std::cin >> s;

    cout << get_maximum_value("1+5") << '\n';
}
