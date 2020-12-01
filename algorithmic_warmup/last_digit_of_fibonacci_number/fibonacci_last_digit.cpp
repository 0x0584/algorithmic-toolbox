#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int step = 2; step <= n; ++step) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_naive(n) << std::endl;
}
