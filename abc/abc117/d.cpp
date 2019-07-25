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
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 40; i >= -1; --i) {
        if (i != -1 && !(K & (1LL << i))) {
            continue;
        }

        ll tmp = 0;
        for (int j = 40; j >= 0; --j) {
            ll mask = (1LL << j);

            ll c = 0;
            for (int k = 0; k < N; ++k) {
                if (A[k] & mask) {
                    ++c;
                }
            }

            if (j > i) {
                if (K & mask) {
                    tmp += mask * (N-c);
                } else {
                    tmp += mask * c;
                }
            } else if (j == i) {
                tmp += mask * c;
            } else {
                tmp += mask * max(c, N-c);
            }
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
