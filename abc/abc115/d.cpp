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

ll f(ll i, ll l, const vector<ll>& lnum, const vector<ll>& pnum)
{
    if (l == 0) {
        return 1;
    }

    if (i == 1) {
        return 0;
    } else if (2 <= i && i <= lnum[l-1] + 1) {
        return f(i - 1, l - 1, lnum, pnum);
    } else if (i == lnum[l-1] + 2) {
        return pnum[l-1] + 1;
    } else if (lnum[l-1] + 3 <= i && i <= 2*lnum[l-1] + 3) {
        return pnum[l-1] + 1 + f(i - lnum[l-1] - 2, l - 1, lnum, pnum);
    } else {
        return 2*pnum[l-1] + 1;
    }
}

int main()
{
    ll N, X;
    cin >> N >> X;

    vector<ll> lnum(N+1);
    lnum[0] = 1;
    for (int i = 0; i < N; ++i) {
        lnum[i+1] = 2*lnum[i] + 3;
    }

    vector<ll> pnum(N+1);
    pnum[0] = 1;
    for (int i = 0; i < N; ++i) {
        pnum[i+1] = 2*pnum[i] + 1;
    }

    ll ans = f(X, N, lnum, pnum);
    cout << ans << endl;

    return 0;
}
