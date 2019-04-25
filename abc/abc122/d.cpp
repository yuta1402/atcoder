#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

int dp[101][4][4][4];

int mod = 1'000'000'007;

int main()
{
    int N;
    cin >> N;

    // 長さ0の文字列は1である
    dp[0][3][3][3] = 1;

    for (int len = 0; len < N; len++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (dp[len][i][j][k] == 0) {
                        continue;
                    }

                    for (int a = 0; a < 4; a++) {
                        if (a == 2 && i == 1 && j == 0) {
                            continue;
                        }
                        if (a == 2 && i == 0 && j == 1) {
                            continue;
                        }
                        if (a == 1 && i == 2 && j == 0) {
                            continue;
                        }
                        if (a == 2 && i == 1 && k == 0) {
                            continue;
                        }
                        if (a == 2 && j == 1 && k == 0) {
                            continue;
                        }

                        dp[len+1][a][i][j] += dp[len][i][j][k];
                        dp[len+1][a][i][j] %= mod;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                ans += dp[N][i][j][k];
                ans %= mod;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
