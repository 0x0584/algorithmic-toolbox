#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<int> &a, int x) {
    int lo = 0, hi = int(a.size());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            hi = mid;
        else
            lo = mid + 1;
    }
    return -1;
}

// int linear_search(const vector<int> &a, int x) {
//   for (size_t i = 0; i < a.size(); ++i) {
//     if (a[i] == x) return i;
//   }
//   return -1;
// }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
        cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    for (int i = 0; i < m; ++i)
        cout << binary_search(a, b[i]) << (i + 1 == m ? '\n' : ' ');
}
