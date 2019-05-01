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

    vector<int> V(N);
    vector<int> C(N);

    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (V[i] > C[i]) {
            ans += V[i] - C[i];
        }
    }

    cout << ans << endl;

    return 0;
}
