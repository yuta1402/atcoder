#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX_N = 100010;

int memo[MAX_N];

int f(int n)
{

    if(n == 0) {
        return 0;
    }

    if(memo[n] != -1) {
        return memo[n];
    }

    int res = f(n-1) + 1;

    for(int i = 6; i <= n; i *= 6) {
        res = min(res, f(n-i) + 1);
    }

    for(int i = 9; i <= n; i *= 9) {
        res = min(res, f(n-i) + 1);
    }

    memo[n] = res;

    return res;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < MAX_N; ++i) {
        memo[i] = -1;
    }

    int ans = f(n);
    cout << ans << endl;

    return 0;
}
