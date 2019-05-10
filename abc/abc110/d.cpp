#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

static const int MOD = 1e+9 + 7;

unordered_map<int, int> fact(int x)
{
    unordered_map<int, int> prime_counts;

    int size = (int)sqrt(x) + 1;
    for (int i = 2; i <= size; ++i) {
        while (x % i == 0) {
            x /= i;
            ++prime_counts[i];
        }
    }

    if (x > 1) {
        ++prime_counts[x];
    }

    return prime_counts;
}

template<class T>
T modpow(T base, T exp, T mod)
{
    base %= mod;
    T res = 1;

    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }

        base = (base * base) % mod;
        exp >>= 1;
    }

    return res;
}

ll comb(int n, int k)
{
    ll x = 1;

    for (int i = n; i >= n - k + 1; --i) {
        x = (x * i) % MOD;
    }

    for (int i = 1; i <= k; ++i) {
        x = (x * modpow<ll>(i, MOD-2, MOD)) % MOD;
    }

    return x;
}

int main()
{
    int N, M;
    cin >> N >> M;

    auto f = fact(M);

    int ans = 1;

    for(auto&& fi : f) {
        int b = fi.second;

        ans = (ans * comb(b + N - 1, b)) % MOD;
    }

    cout << ans << endl;

    return 0;
}
