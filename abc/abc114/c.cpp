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

bool ok(int num)
{
    bool ok7 = false;
    bool ok5 = false;
    bool ok3 = false;

    while (num) {
        int x = num % 10;

        if (x == 7) {
            ok7 = true;
        } else if (x == 5) {
            ok5 = true;
        } else if (x == 3) {
            ok3 = true;
        }

        num /= 10;
    }

    return ok7 && ok5 && ok3;
}

ll f(int i, int num, int N, int digits)
{
    if (i >= digits) {
        if (ok(num) && num <= N) {
            return 1;
        }

        return 0;
    }

    ll res = 0;
    res += f(i+1, num*10 + 7, N, digits);
    res += f(i+1, num*10 + 5, N, digits);
    res += f(i+1, num*10 + 3, N, digits);

    return res;
}

int main()
{
    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 2; i <= 9; ++i) {
        ans += f(0, 0, N, i);
    }

    cout << ans << endl;

    return 0;
}
