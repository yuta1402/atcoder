#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
using ll = long long;

int N;

ll func(const vector<ll>& a, ll b)
{
    ll res = 0;

    for(int i = 0; i < N; ++i) {
        res += abs(a[i] - b);
    }

    return res;
}

int main()
{
    cin >> N;

    vector<ll> a;

    for(int i = 0; i < N; ++i) {
        ll ai;
        cin >> ai;
        a.emplace_back(ai - (i+1));
    }

    sort(begin(a), end(a));

    ll b;

    if(N % 2 == 0) {
        b = (a[N / 2 - 1] + a[N / 2]) / 2.0;
    } else {
        b = a[N / 2];
    }

    ll ans1 = func(a, b - 1);
    ll ans2 = func(a, b - 0);
    ll ans3 = func(a, b + 1);

    ll ans = min(ans1, min(ans2, ans3));

    cout << ans << endl;

    return 0;
}
