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

int main()
{
    int N, K;
    cin >> N >> K;

    unordered_map<int, vector<ll>> m;

    for (int i = 0; i < N; ++i) {
        int t, d;
        cin >> t >> d;
        m[t].emplace_back(d);
    }

    for (auto&& p : m) {
        auto&& v = p.second;
        sort(rbegin(v), rend(v));
    }

    priority_queue<int> best, remain;
    for (const auto& p : m) {
        const auto& v = p.second;

        best.emplace(v[0]);

        for (size_t i = 1; i < v.size(); ++i) {
            remain.emplace(v[i]);
        }
    }

    vector<ll> bsum = { 0 };
    while (!best.empty()) {
        bsum.emplace_back(bsum.back() + best.top());
        best.pop();
    }

    vector<ll> rsum = { 0 };
    while (!remain.empty()) {
        rsum.emplace_back(rsum.back() + remain.top());
        remain.pop();
    }

    ll ans = 0;
    for (ll x = 1; x <= K; ++x) {
        if (x >= bsum.size()) {
            continue;
        }

        if (K-x >= rsum.size()) {
            continue;
        }

        ans = max(ans, bsum[x] + rsum[K-x] + x*x);
    }

    cout << ans << endl;

    return 0;
}
