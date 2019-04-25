#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> F(
        N, vector<int>(10, 0)
    );

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> F[i][j];
        }
    }

    vector<vector<int>> P(
        N, vector<int>(11, 0)
    );

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> P[i][j];
        }
    }

    int ans = -INT_MAX;

    for (int b = 1; b < (1 << 10); ++b) {
        int cc = 0;

        for (int i = 0; i < N; i++) {
            int c = 0;

            for (int j = 0; j < 10; j++) {
                if ((b >> j & 1) && F[i][j]) {
                    ++c;
                }
            }

            cc += P[i][c];
        }

        ans = max(ans, cc);
    }

    cout << ans << endl;

    return 0;
}
