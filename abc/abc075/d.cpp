#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<ll> x(N);
    vector<ll> y(N);

    vector<ll> x_sorted(N);
    vector<ll> y_sorted(N);

    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
        x_sorted[i] = x[i];
        y_sorted[i] = y[i];
    }

    sort(begin(x_sorted), end(x_sorted));
    sort(begin(y_sorted), end(y_sorted));

    ll ans = (x_sorted[N-1] - x_sorted[0]) * (y_sorted[N-1] - y_sorted[0]);

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                for (int l = k + 1; l < N; ++l) {
                    ll lx = x_sorted[i];
                    ll rx = x_sorted[j];

                    ll by = y_sorted[k];
                    ll uy = y_sorted[l];

                    int num = 0;

                    for (int m = 0; m < N; ++m) {
                        if (lx <= x[m] && x[m] <= rx && by <= y[m] && y[m] <= uy) {
                            ++num;
                        }
                    }

                    if (num >= K) {
                        ans = min(ans, (rx - lx) * (uy - by));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
