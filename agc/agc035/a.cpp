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
    int n;
    cin >> n;

    unordered_map<int, int> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }

    bool all_zero = all_of(begin(a), end(a), [](const auto& ai){ return ai == 0; });
    bool any_zero = any_of(begin(a), end(a), [](const auto& ai){ return ai == 0; });

    // 0: n
    if (all_zero) {
        cout << "Yes" << endl;
        return 0;
    }

    if (n % 3 != 0) {
        cout << "No" << endl;
        return 0;
    }

    // 0: n/3, x: 2*n/3
    if (any_zero) {
        auto it = find_if(begin(a), end(a), [](const auto& ai){ return ai != 0; });
        int x = *it;
        if (m[x] == 2*n/3 && m[0] == n/3) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // x: n/3, y: n/3, z: n/3
    auto it = find_if(begin(a), end(a), [](const auto& ai){ return ai != 0; });
    int x = *it;

    auto it2 = find_if(begin(a), end(a), [&](const auto& ai){ return ai != x; });
    int y = *it2;

    int z = x ^ y;

    if (m[x] == n/3 && m[y] == n/3 && m[z] == n/3) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
