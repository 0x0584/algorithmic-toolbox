#include <iostream>
#include <vector>

std::vector<long long> fib_mods(long long m) {
    std::vector<long long> w = {0, 1};
    for (long long u = 0, v = 1, tmp; w.front() != w.back(); w.push_back(v))
        tmp = u, u = v, v = (tmp + v) % m;
    w.pop_back();
    return w;
}

long long get_fibonacci_huge_mods(long long n, long long m) {
    return fib_mods(m)[n % m];
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_mods(n, m) << std::endl;
}
