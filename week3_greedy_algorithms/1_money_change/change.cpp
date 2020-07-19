#include <iostream>

int get_change(int m) {
    int n = 0;
    auto until = [&](int l) {
        while (m >= l)
            n += 1, m -= l;
    };
    until(10);
    until(5);
    return n + m;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
