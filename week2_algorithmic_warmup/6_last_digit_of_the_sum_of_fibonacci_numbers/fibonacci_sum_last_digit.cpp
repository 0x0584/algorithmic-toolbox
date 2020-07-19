#include <iostream>

int fibonacci_sum(long long n) {
    int digit = 1;
    int u = 0, v = 1;
    for (int step = 2; step <= n; ++step) {
        int tmp = u;
        u = v;
        v = (tmp + v) % 10;
        digit = (digit + v) % 10;
    }
    return digit;
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main() {
    long long n;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << std::endl;
    std::cout << fibonacci_sum(n) << std::endl;
}
