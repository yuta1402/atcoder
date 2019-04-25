#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;
using ll = long long;

int main()
{
    int N, C;
    cin >> N >> C;

    vector<int> s(N);
    vector<int> t(N);
    vector<int> c(N);

    int T = 0;

    for (int i = 0; i < N; ++i) {
        cin >> s[i] >> t[i] >> c[i];
        --c[i];

        T = max(T, t[i]+1);
    }

    vector<vector<int>> v(
        C, vector<int>(T+1, 0)
    );

    for (int nc = 0; nc < C; ++nc) {
        for (int i = 0; i < N; ++i) {
            if (c[i] == nc) {
                for (int j = s[i]; j <= t[i]; ++j) {
                    v[nc][j] = 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= T; ++i) {
        int count = 0;
        for (int nc = 0; nc < C; ++nc) {
            count += v[nc][i];
        }
        ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}
