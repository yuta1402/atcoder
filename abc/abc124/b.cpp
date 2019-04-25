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
    int N;
    cin >> N;

    vector<int> h(N);

    for (auto&& hi : h)  {
        cin >> hi;
    }

    int ans = 1;

    for (int i = 1; i < N; ++i) {
        bool ok = true;
        for (int j = 0; j < i; ++j) {
            if (h[j] > h[i]) {
                ok = false;
            }
        }
        if (ok) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
