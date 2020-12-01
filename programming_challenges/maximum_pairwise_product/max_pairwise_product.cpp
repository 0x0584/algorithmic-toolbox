#include <iostream>
#include <vector>

std::pair<std::size_t, std::size_t> max_pair(const std::vector<int> &A) {
    if (A.size() < 2)
        return {};
    std::size_t m1 = 0, m2 = 1;
    auto find_max = [&A](std::size_t &m1, const std::size_t m2) {
        for (auto k = 0u; k < A.size(); ++k)
            if (k != m1 and k != m2 and A[k] > A[m1])
                m1 = k;
    };
    find_max(m1, m2), find_max(m2, m1);
    return std::make_pair(m1, m2);
}

int main(int, char *[]) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    auto max = max_pair(v);
    long long r = static_cast<long long>(v[max.first]) * v[max.second];
    std::cout << r << "\n";
    return 0;
}
