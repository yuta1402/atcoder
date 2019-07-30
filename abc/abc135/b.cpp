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
#include <bitset>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            auto q = p;
            swap(q[i], q[j]);

            bool ok = true;
            for (int k = 0; k < N-1; ++k) {
                ok = ok && (q[k] <= q[k+1]);
            }

            if (ok) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
