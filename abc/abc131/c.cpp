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

ll gcd(ll x, ll y)
{
    if (x < y) {
        swap(x, y);
    }

    if (x % y == 0) {
        return y;
    }

    return gcd(y, x % y);
}

ll lcm(ll x, ll y)
{
    return x / gcd(x, y) * y;
}

ll f(ll x, ll C, ll D)
{
    ll res = x;
    res -= x / C;
    res -= x / D;
    res += x / lcm(C, D);
    
    return res;
}

int main()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << f(B, C, D) - f(A-1, C, D) << endl;

    return 0;
}
