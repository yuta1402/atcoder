#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<ll> ones;
    vector<ll> zeros;

    ll count = 1;
    char current = S[0];

    for (int i = 1; i < N; ++i) {
        if (current == S[i]) {
            ++count;
            continue;
        }

        // current 1= S[i]

        if (current == '0') {
            zeros.emplace_back(count);
        } else {
            ones.emplace_back(count);
        }

        current = S[i];
        count = 1;
    }

    if (current == '0') {
        zeros.emplace_back(count);
    } else {
        ones.emplace_back(count);
    }

    if (S[0] == '0') {
        ones.insert(begin(ones), 0);
    }

    if (S[S.size()-1] == '0') {
        ones.emplace_back(0);
    }

    // 0の塊がK個以下なら全て反転させればよいのでSの長さが答え
    if (zeros.size() <= K) {
        cout << S.size() << endl;
        return 0;
    }

    ll sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += zeros[i];
        sum += ones[i];
    }
    sum += ones[K];

    ll ans = sum;
    for (int i = 0; i + K < zeros.size(); ++i) {
        sum -= zeros[i];
        sum -= ones[i];
        sum += zeros[i+K];
        sum += ones[i+K+1];

        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
