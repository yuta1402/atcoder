#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;

    ll ans0 = 0;
    // 0101010101...
    for (int i = 0; i < S.size(); ++i) {
        int num = (S[i] == '0') ? 0 : 1;
        if (num != (i % 2)) {
            ++ans0;
        }
    }

    ll ans1 = 0;
    // 1010101010...
    for (int i = 0; i < S.size(); ++i) {
        int num = (S[i] == '0') ? 0 : 1;
        if (num != (i+1)%2) {
            ++ans1;
        }
    }

    ll ans = min(ans0, ans1);
    cout << ans << endl;

    return 0;
}
