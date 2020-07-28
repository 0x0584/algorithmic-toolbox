#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int d, int r, const vector<int> &gas) {
    const int size = gas.size();

    // for (int g : gas)
    //     cout << g << endl;
    // cout << endl;

    int c = 0, n = 0;
    int prev = -1;
    while (c < size) {
        if (prev == -1) {
            while (c < size and gas[c] < r) {
                c++;
            }
            c--;
        } else {
            while (c + 1 < size and gas[c + 1] - gas[prev] < r) {
                c++;
            }
        }

        if (prev == c)
            return -1;
        if (c < size)
            n++;
        else if (prev != -1 and gas[prev] + r < d)
            return -1;
        prev = c++;
    }
    return n;
}

int main() {
    int d, m, n;
    cin >> d >> m >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << compute_min_refills(d, m, v) << endl;

    // cout << compute_min_refills(950, 400, {200, 375, 550, 750}) << "\n";
    // cout << "\n\n";
    // cout << compute_min_refills(750, 400, {200, 375, 550}) << "\n";
    // cout << "\n\n";
    // cout << compute_min_refills(500, 200, {100, 200, 270, 380, 450, 550,
    // 700})
    //      << "\n";

    return 0;
}
