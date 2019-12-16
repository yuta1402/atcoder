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

    int m = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int pi;
        cin >> pi;
        ans += pi;
        m = max(m, pi);
    }

    ans -= m;
    ans += m / 2;
    cout << ans << endl;

    return 0;
}
