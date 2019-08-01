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
    int N;
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    int ans = 0;
    while (true) {
        bool is_end = all_of(begin(h), end(h), [](const auto& hi){ return hi == 0; });
        if (is_end) {
            break;
        }

        int l = 0;
        while (l < N && h[l] == 0) {
            ++l;
        }

        int r = l;
        while (r < N && h[r] != 0) {
            h[r]--;
            ++r;
        }

        ++ans;
    }

    cout << ans << endl;

    return 0;
}
