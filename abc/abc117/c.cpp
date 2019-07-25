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
    int N, M;
    cin >> N >> M;

    vector<int> X(M);
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
    }

    sort(begin(X), end(X));

    vector<int> d(M);
    d[0] = 0;
    for (int i = 1; i < M; ++i) {
        d[i] = X[i] - X[i-1];
    }

    sort(begin(d), end(d));

    int ans = 0;
    for (int i = 0; i < M-N+1; ++i) {
        ans += d[i];
    }

    cout << ans << endl;

    return 0;
}
