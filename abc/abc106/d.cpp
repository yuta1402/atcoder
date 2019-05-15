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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> dp(510, vector<int>(510, 0));
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;

        for (int j = 1; j <= L; ++j) {
            dp[j][R]++;
        }
    }

    for (int i = 1; i <= 500; i++) {
        for (int j = i; j <= 500; j++) {
            dp[i][j] += dp[i][j-1];
        }
    }

    for (int i = 0; i < Q; i++) {
        int p, q;
        cin >> p >> q;
        cout << dp[p][q] << endl;
    }

    return 0;
}
