#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm_naive(int a, int b) {
    return ((long long)a * (long long)b) / gcd(a, b);
}

int main() {
    int a = 6, b = 8;
    // std::cin >> a >> b;
    std::cout << lcm_naive(a, b) << std::endl;
    // std::cout << lcm(a, b) << std::endl;
    return 0;
}
