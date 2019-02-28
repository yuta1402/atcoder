#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

static const ll INF = 1e+18;

int main()
{
    int A, B, Q;
    cin >> A >> B >> Q;

    vector<ll> s(A);
    for (auto&& si : s) {
        cin >> si;
    }

    s.insert(s.begin(), -INF);
    s.insert(s.end(), +INF);

    vector<ll> t(B);
    for (auto&& ti : t) {
        cin >> ti;
    }

    t.insert(t.begin(), -INF);
    t.insert(t.end(), +INF);

    for (int i = 0; i < Q; ++i) {
        ll xi;
        cin >> xi;

        auto it_s = lower_bound(s.begin(), s.end(), xi);
        ll s_a = *it_s;
        ll s_b = *(it_s-1);

        auto it_t = lower_bound(t.begin(), t.end(), xi);
        ll t_a = *it_t;
        ll t_b = *(it_t-1);

        ll ans = INF;

        for(auto&& sj : { s_a, s_b }) {
            for(auto&& tj : { t_a, t_b }) {
                ll len = min(abs(sj - xi), abs(tj - xi)) + abs(sj - tj);
                ans = min(len ,ans);
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
