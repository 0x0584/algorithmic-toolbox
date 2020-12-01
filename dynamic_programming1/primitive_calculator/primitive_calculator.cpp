#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_sequence(int n) {
    vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence = optimal_sequence(n);
    cout << sequence.size() - 1 << endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
    }
}
