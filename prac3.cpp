#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

void merge(std::vector<ll>& array, ll& l, ll& r, ll& m, ll& comp, ll& per) {
    ll p1 = l;
    ll p2 = m;
    ll i = 0;
    std::vector<ll> ans(r - l);

    while (p1 < m && p2 < r) {
        comp += 1;
        per += 1;
        if (array[p1] < array[p2])
            ans[i++] = array[p1++];

        else
            ans[i++] = array[p2++];
    }

    while (p1 < m) {
        ans[i++] = array[p1++];
        per += 1;
    }

    while (p2 < r) {
        ans[i++] = array[p2++];
        per += 1;
    }

    for (ll i = l; i < r; i++) {
        per += 1;
        array[i] = ans[i - l];
    }
}

void mergeSort(std::vector<ll>& array, ll l, ll r, ll& comp, ll& per) {
    if (r - l < 2)
        return;

    ll m = (l + r) / 2;
    
    mergeSort(array, l, m, comp, per);
    mergeSort(array, m, r, comp, per);

    merge(array, l, r, m, comp, per);
}

void test(ll n) {
    std::vector<ll> a(n);
    ll comp = 0;
    ll per = 0;

    for (ll &val : a) {
        val = rand();
        std::cout << val << ' ';
    }

    std::cout << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();

    mergeSort(a, 0, n, comp, per);

    for (ll &val : a) {
        std::cout << val << ' ';
    }

    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<ld> duration = end - begin;

    std::cout << "T(n) = ";
    std::cout << std::fixed << std::setprecision(10) << duration.count() << std::endl;

    std::cout << "f(C + M) = ";
    std::cout << static_cast<ll>(n * log2(n)) << std::endl;

    std::cout << "C + M = ";
    std::cout << comp + per << std::endl;
}

int main() {
    srand(time(0));

    ll n; std::cin >> n;
    test(n);

    return 0;
}
