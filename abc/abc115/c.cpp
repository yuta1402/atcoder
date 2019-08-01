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
    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    sort(begin(h), end(h));

    int ans = h[K-1] - h[0];
    for (int i = 1; i < N-K+1; ++i) {
        ans = min(ans, h[i+K-1] - h[i]);
    }

    cout << ans << endl;

    return 0;
}
