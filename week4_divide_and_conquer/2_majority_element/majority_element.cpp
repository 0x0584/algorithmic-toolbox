#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<int, int> count;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        size_t tmp;
        cin >> tmp;
        count[tmp]++;
    }
    const int half = floor(n / 2) + 1;
    const auto majority = [&half](pair<int, int> e) {
        return e.second >= half;
    };
    cout << any_of(begin(count), end(count), majority) << '\n';
}
