#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

struct Heap {
    std::vector<ll> heap;

    ll size = 0;
    ll comp = 0;
    ll per = 0;

    void init(ll sz) {
        size = sz;
        heap.resize(sz);
    }

    ll pop_heap() {
        ll ans = heap[0];
        ll pos = 0;
        heap[0] = heap[size - 1];

        while (2 * pos + 2 < size) {
            ll max_son_index = 2 * pos + 1;

            comp += 1;

            if (heap[2 * pos + 2] > heap[max_son_index])
                max_son_index = 2 * pos + 2;
            
            comp += 1;

            if (heap[pos] < heap[max_son_index]) {
                std::swap(heap[pos], heap[max_son_index]);
                pos = max_son_index;
                per += 1;
            }

            else
                break;
        }

        size -= 1;

        return ans;
    }

    void heapify() {
        ll i = size - 1;

        while (i >= 0) {
            ll pos = i;
            while (2 * pos + 2 < size) {
                ll max_son_index = 2 * pos + 1;

                comp += 1;

                if (heap[2 * pos + 2] > heap[max_son_index])
                max_son_index = 2 * pos + 2;

                comp += 1;

                if (heap[pos] < heap[max_son_index]) {
                    std::swap(heap[pos], heap[max_son_index]);
                    pos = max_son_index;
                    per += 1;
                }

                else
                    break;
            }


            if (2 * pos + 1 < size && heap[pos] < heap[2 * pos + 1]) {
                std::swap(heap[pos], heap[2 * pos + 1]);
                pos = 2 * pos + 1;
                per += 1;
                comp += 1;
            }
            

            i -= 1;
        }
    }
};

void heapSort(Heap& h, ll& comp, ll& per) {
    h.heapify();

    for (ll i = h.heap.size() - 1; i >= 0; i--) {
        h.heap[i] = h.pop_heap();
    }

    comp = h.comp;
    per = h.per;
}

void test(ll n) {
    Heap h;
    h.init(n);

    ll comp = 0;
    ll per = 0;

    for (ll& val : h.heap) {
        val = rand();
        std::cout << val << ' ';
    }

    std::cout << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();

    heapSort(h, comp, per);

    for (ll& val : h.heap) {
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
