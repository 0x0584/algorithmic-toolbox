#include <algorithm>
#include <iostream>
#include <vector>

struct knap_item {
    int w, v;
    knap_item(int w, int v) : w(w), v(v) {}
    double value() const { return static_cast<double>(v) / w; }
    static bool cmp(const knap_item &a, const knap_item &b) {
        return a.value() > b.value();
    }
};

double get_optimal_value(int c, std::vector<int> W, std::vector<int> V) {
    std::vector<knap_item> sack;

    sack.reserve(W.size());
    for (int i = 0; i < int(W.size()); ++i)
        sack.emplace_back(knap_item(W[i], V[i]));
    std::sort(begin(sack), end(sack), knap_item::cmp);

    double value = 0.0;
    for (knap_item &k : sack) {
        if (c == 0)
            return value;
        int min = std::min(k.w, c);
        value += min * k.value();
        k.w -= min;
        c -= min;
    }

    return value;
}

int main() {
    int n;
    int capacity;

    std::cin >> n >> capacity;

    std::vector<int> values(n);
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
