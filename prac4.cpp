#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

int linarySearch(std::vector<ll>& array, ll x, ll& comp) {
    int i = 0;

    while (array[i] != x) {
        ++i;
    }

    return i;
}

void test(ll n) {
    std::vector<ll> a(n + 1);
    ll comp = 0;

    for (ll &val : a) {
        val = rand();
        std::cout << val << ' ';
    }

    std::cout << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();
    ll x = rand() % n;
    a[n] = a[x];
    std::cout << a[x] << std::endl;
    std::cout << linarySearch(a, a[x], comp) << std::endl;
    


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<ld> duration = end - begin;

    std::cout << "T(n) = ";
    std::cout << std::fixed << std::setprecision(10) << duration.count() << std::endl;

    std::cout << "f(C) = ";
    std::cout << n << std::endl;

    std::cout << "C = ";
    std::cout << comp << std::endl;
}

int main() {
    srand(time(0));

    ll n; std::cin >> n;
    test(n);
    
    return 0;
}
