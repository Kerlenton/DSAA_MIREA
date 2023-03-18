#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

void selectionSort(std::vector<ll>& array, ll& comp, ll& per) {

    for (ll i = 0; i < array.size(); ++i) {
        ll min = i;

        for (ll j = i + 1; j < array.size(); ++j) {
            if (array[j] < array[min]) {
                min = j;
            }

            comp += 1;
        }

        ll temp = array[i];
        array[i] = array[min];
        array[min] = temp;

        per += 1;
    }
}

void test(ll n) {
    std::vector<ll> a(n);
    ll comp = 0;
    ll per = 0;

    for (ll &val : a)
        val = rand();

    auto begin = std::chrono::high_resolution_clock::now();

    selectionSort(a, comp, per);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<ld> duration = end - begin;

    std::cout << "T(n) = ";
    std::cout << std::fixed << std::setprecision(10) << duration.count() << std::endl;

    std::cout << "f(C + M) = ";
    std::cout << n * n << std::endl;

    std::cout << "C + M = ";
    std::cout << comp + per << std::endl;    
}

int main() {
    srand(time(0));

    ll n; std::cin >> n;
    test(n);

    return 0;
}
