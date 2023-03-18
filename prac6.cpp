#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

const ll MOD = static_cast<ll>(1e9 + 7);
const ll p = 211ll;

ll modpow(ll x, ll y, ll MD) {
    if (y == 0)
        return 1ll;

    else if (y % 2 == 0) {
        ll tmp = modpow(x, y / 2, MD);
        return (tmp * tmp) % MD;
    }

    else
        return ((x % MD) * modpow(x, y - 1, MD)) % MD;
}

ll findSubstr(std::string& s, std::string& t, ll& comp, ll& per) {
    std::vector<ll> pr(s.size() + 1);
    ll x = 0;

    for (ll i = 0; i < s.size(); i++)
        pr[i + 1] = (pr[i] * p + s[i]) % MOD;

    for (ll i = 0; i < t.size(); i++) {
        x = (x * p + t[i]) % MOD;
    }

    for (ll l = 0; l <= s.size() - t.size(); l++) {
        per += 1;
        ll r = l + t.size();
        ll y = (pr[r] - (pr[l] * modpow(p, r - l, MOD) % MOD) + MOD) % MOD;
        
        comp += 1;
        if (x == y) {
            return l;
        }
    }

    return -1;
}

void test() {
    std::ifstream inp("test3.txt", std::ios::in);
    std::string s, t, tmp;
    ll comp = 0;
    ll per = 0;
    
   while (inp >> tmp) {
        s = s + tmp;
   }

    //std::cout << s << std::endl;
    //getline(std::cin, s);
    getline(std::cin, t);

    //std::cout << int('б') << int('в') << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();

    std::cout << findSubstr(s, t, comp, per) << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<ld> duration = end - begin;

    std::cout << "T(n) = ";
    std::cout << std::fixed << std::setprecision(10) << duration.count() << std::endl;

    std::cout << "f(C + M) = ";
    std::cout << s.size() << std::endl;

    std::cout << "C + M = ";
    std::cout << comp + per << std::endl;
}

int main(void) {
    srand(time(0));

    test();

    return 0;
}
