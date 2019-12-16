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
    ll N, K, Q;
    cin >> N >> K >> Q;

    vector<ll> v(N, 0);

    for (int i = 0; i < Q; ++i) {
        int Ai;
        cin >> Ai;
        Ai--;

        v[Ai]++;
    }

    for (int i = 0; i < N; ++i) {
        if (K - Q + v[i] > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
