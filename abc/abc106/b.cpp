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

int num_fac(int x)
{
    int count = 0;

    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            ++count;
        }
    }

    return count;
}

int main()
{
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1 && num_fac(i) == 8) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
