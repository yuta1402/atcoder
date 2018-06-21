#include <iostream>
#include <algorithm>

using namespace std;

int func(int n, int a) {
    int res = 0;

    while(n > 0) {
        res += n % a;
        n /= a;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    // inf扱いでnを使用
    int ans = n;

    for(int i = 0; i <= n; ++i) {
        ans = min(ans, func(i, 6) + func(n-i, 9));
    }

    cout << ans << endl;

    return 0;
}
