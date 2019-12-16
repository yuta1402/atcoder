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
    int N, M;
    cin >> N >> M;

    priority_queue<ll> q;

    for (int i = 0; i < N; ++i) {
        int Ai;
        cin >> Ai;

        q.push(Ai);
    }

    for (int i = 0; i < M; ++i) {
        int t = q.top();
        q.pop();

        t = t / 2;

        q.push(t);
    }

    ll ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }

    cout << ans << endl;

    return 0;
}
