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

ll gcd(ll x, ll y)
{
    if (x < y) {
        swap(x, y);
    }

    if (y == 0) {
        return x;
    }

    return gcd(y, x % y);
}

int main()
{
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> forward(N);
    forward[0] = A[0];
    for (int i = 1; i < N; ++i) {
        forward[i] = gcd(forward[i-1], A[i]);
    }

    vector<ll> backward(N);
    backward[N-1] = A[N-1];
    for (int i = N-2; i >= 0; --i) {
        backward[i] = gcd(backward[i+1], A[i]);
    }

    ll ans = 0;
    for (int i = 1; i < N-1; ++i) {
        ll g = gcd(forward[i-1], backward[i+1]);
        ans = max(ans, g);
    }

    // 0番目を書き換えた場合
    ans = max(ans, backward[1]);
    // N-1番目を書き換えた場合
    ans = max(ans, forward[N-2]);

    cout << ans << endl;

    return 0;
}
