#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

int binarySearch(std::vector<ll>& array, ll x, ll& comp) {
    ll l = 0;
    ll r = array.size() - 1;

    while (l <= r) {
        ll m = (l + r) / 2;
        comp += 1;

        if (x == array[m])
            return m;

        else if (x > array[m])
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

void test(ll n) {
    std::vector<ll> a(n);
    ll comp = 0;

    for (ll &val : a)
        val = rand();

    auto begin = std::chrono::high_resolution_clock::now();

    binarySearch(a, a[rand() % n], comp);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<ld> duration = end - begin;

    std::cout << "T(n) = ";
    std::cout << std::fixed << std::setprecision(10) << duration.count() << std::endl;

    std::cout << "f(C) = ";
    std::cout << static_cast<ll>(log2(n)) << std::endl;

    std::cout << "C = ";
    std::cout << comp << std::endl;
}

int main() {
    srand(time(0));

    ll n; std::cin >> n;
    test(n);

    return 0;
}
