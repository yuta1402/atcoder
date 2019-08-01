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

    vector<int> A(N+1);
    vector<int> B(N);

    for (int i = 0; i < N+1; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    ll ans = 0;

    for (int i = 0; i < N; ++i) {
        int kill_i = min(A[i], B[i]);
        A[i] -= kill_i;
        B[i] -= kill_i;

        int kill_ii = min(A[i+1], B[i]);
        A[i+1] -= kill_ii;
        B[i] -= kill_ii;

        ans += kill_i + kill_ii;
    }

    cout << ans << endl;

    return 0;
}
