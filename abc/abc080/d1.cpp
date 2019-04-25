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

    vector<int> v(T+2, 0);

    for (int nc = 0; nc < C; ++nc) {
        vector<int> u(T+2, 0);

        for (int i = 0; i < N; ++i) {
            if (c[i] == nc) {
                ++u[s[i]];
                --u[t[i] + 1];
            }
        }

        for (int i = 0; i < T; ++i) {
            u[i+1] += u[i];
        }

        for (int i = 0; i <= T; ++i) {
            if (u[i] > 0) { 
                ++v[i];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= T; ++i) {
        ans = max(ans, v[i]);
    };

    cout << ans << endl;

    return 0;
}
