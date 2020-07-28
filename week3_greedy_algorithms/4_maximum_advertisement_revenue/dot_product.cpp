#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define half(val) (val / 2)

constexpr long long mul(const int &a, const int &b) {
    return static_cast<long long>(a) * static_cast<long long>(b);
}

long long max_dot_product(vector<int> &a, vector<int> &b) {
    const int size = a.size();
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    long long sum = (size & 1) ? mul(a[half(size)], b[half(size)]) : 0;
    for (int i = 0; i < half(size); ++i) {
        sum += mul(a[i], b[i]) + mul(a.back(), b.back());
        a.pop_back(), b.pop_back();
    }
    return sum;
}

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++)
        cin >> a[i];
    for (size_t i = 0; i < n; i++)
        cin >> b[i];
    cout << max_dot_product(a, b) << endl;

    // vector<int> v = {39}, w = {23};
    // cout << max_dot_product(v, w) << endl;
}
