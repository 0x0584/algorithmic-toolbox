#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int part_size = 3;

bool dfs(vector<int> &sum, const vector<int> &A, int at, int part_sum) {
    if (at == int(A.size()))
        return all_of(begin(sum), end(sum),
                      [&](int part) { return part == part_sum; });
    for (int &part : sum) {
        if (part + A[at] > part_sum)
            continue;
        part += A[at];
        if (dfs(sum, A, at + 1, part_sum))
            return true;
        part -= A[at];
    }
    return false;
}

bool partition3(vector<int> &A) {
    if (A.size() < part_size)
        return false;
    int total = 0, max_el = 0;
    for (int e : A)
        total += e, max_el = max(max_el, e);
    if (total % part_size != 0 or max_el > total / part_size)
        return false;
    vector<int> sum(part_size, 0);
    sort(begin(A), end(A));
    return dfs(sum, A, 0, total / part_size);
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i)
        cin >> A[i];
    // vector<int> A = {1, 2, 3, 4, 5, 5, 7, 7, 8, 10, 12, 19, 25};
    cout << partition3(A) << '\n';
}
