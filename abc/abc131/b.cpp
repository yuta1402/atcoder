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
    int N, L;
    cin >> N >> L;

    int taste = 0;
    for (int i = 1; i <= N; ++i) {
        taste += L + i - 1;
    }

    int ans = 0;
    int min_diff = 1000000000;

    for (int j = 1; j <= N; ++j) {
        int t = 0;
        for (int i = 1; i <= N; ++i) {
            if (i == j) {
                continue;
            }

            t += L + i - 1;
        }

        int diff = abs(t - taste);
        if (diff < min_diff) {
            ans = t;
            min_diff = diff;
        }
    }

    cout << ans << endl;

    return 0;
}
