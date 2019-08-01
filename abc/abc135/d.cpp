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
#include <bitset>

using namespace std;

using ll = long long;
using ull = unsigned long long;

static const int MOD = (1e+9) + 7;

int main()
{
    string S;
    cin >> S;

    vector<vector<ll>> dp(
        S.size() + 1, vector<ll>(13, 0)
    );

    dp[0][0] = 1;

    for (int i = 0; i < S.size(); ++i) {
        int c;
        if (S[i] == '?') {
            c = -1;
        } else {
            c = S[i] - '0';
        }

        for (int j = 0; j < 10; ++j) {
            if (c != -1 && c != j) {
                continue;
            }

            for (int k = 0; k < 13; ++k) {
                dp[i+1][(k * 10 + j) % 13] = (dp[i+1][(k * 10 + j) % 13] + dp[i][k]) % MOD;
            }
        }
    }

    ll ans = dp[S.size()][5];
    cout << ans << endl;

    return 0;
}
