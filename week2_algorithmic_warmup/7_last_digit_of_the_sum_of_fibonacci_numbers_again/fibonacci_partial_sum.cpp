#include <climits>

#include <array>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <utility>

typedef long long long2;

using matrix = std::array<long2, 4>;

constexpr matrix m_id = {1, 0, 0, 1};

constexpr long2 mod(long2 n) { return n % 10; }
constexpr long2 mod(long2 n, long2 m) { return mod(mod(n) + mod(m)); }

constexpr matrix operator*(const matrix &A, const matrix &B) {
    return {A[0] * B[0] + A[1] * B[2], A[0] * B[1] + A[1] * B[3],
            A[2] * B[0] + A[3] * B[2], A[2] * B[1] + A[3] * B[3]};
}

std::ostream &operator<<(std::ostream &os, const matrix p) {
    return os << p[0] << " " << p[1] << "\n"
              << p[2] << " " << p[3] << std::endl;
}

matrix power_naive(const matrix &A, long2 n) {
    if (n == 0)
        return m_id;

    matrix M = A;
    for (; n > 1; n--)
        M = M * A;
    return M;
}

matrix power_binpower_recursive(const matrix &A, long2 n) {
    if (n == 0)
        return m_id;
    const matrix M = power_binpower_recursive(A, n >> 1);
    return (n & 1) ? M * M * A : M * M;
}

matrix power_binpower(const matrix &A, long2 n) {
    matrix M = m_id, a = A;
    while (n) {
        if (n & 1)
            M = M * a;
        a = a * a;
        n >>= 1;
    }
    return M;
}

std::array<long2, 2> compute_fibonacci(long2 n) {
    const matrix Pn = power_binpower({0, 1, 1, 1}, n);
    return {Pn[2], Pn[3]};
}

long2 get_fibonacci_partial_sum(long2 n, long2 m) {
    std::array<long2, 2> fi = compute_fibonacci(n);
    int digit = n == m ? mod(fi[0]) : mod(fi[0], fi[1]);
    long2 i = n;

    while (true) {
        const int d = m - i;
        if (d <= 1) {
            if (d) {
                fi = compute_fibonacci(i + 1);
                digit = mod(digit, mod(fi[0], fi[1]));
            }
            break;
        }
        fi = compute_fibonacci(i += 2);
        digit = mod(digit, mod(fi[0], fi[1]));
    }
    return digit;
}

long2 get_fibonacci_partial_sum_naive(long2 from, long2 to) {
    long2 sum = 0;

    long2 current = 0;
    long2 next = 1;

    for (long2 i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long2 new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

template <class clock>
void test_loop(long2 n, std::function<matrix(const matrix &, long2)> fn,
               const std::string &m_id = "default") {
    // Define real time units
    typedef std::chrono::duration<unsigned long long, std::pico> picoseconds;
    // or:
    // typedef std::chrono::nanoseconds nanoseconds;

    // Define double-based unit of clock tick
    typedef std::chrono::duration<double, typename clock::period> Cycle;
    using std::chrono::duration_cast;

    // Do it
    const matrix P = {0, 1, 1, 1};

    std::cout << m_id << n << "  time: ";
    auto t0 = clock::now();
    auto m = fn(P, n);
    auto t1 = clock::now();
    auto ticks_per_iter = Cycle(t1 - t0);
    std::cout << duration_cast<std::chrono::seconds>(ticks_per_iter).count()
              << "s\n"
              << m << "\033[0m \n";
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    long2 from = 3, to = 7;
    // std::cin >> from >> to;

    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';

    // auto templ = [](auto fn, auto m_id) {
    //     long2 n = 2;
    //     while (n < LONG_LONG_MAX / 2)
    //         test_loop<std::chrono::system_clock>(n += n, fn, m_id);
    //     std::cout << m_id << " **** terminated **** " << std::endl;
    //     return true;
    // };
    // std::thread naive(templ, power_naive, "\033[31mn: Power naive ## ");
    // std::thread recursive(templ, power_binpower_recursive,
    //                       "\t\t\033[32mPower recursive @@");
    // std::thread optimal(templ, power_binpower, "\t\t\033[33mPower bin >> ");
    // naive.join();
    // recursive.join();
    // optimal.join();
    // getchar();
}
