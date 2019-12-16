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

/*!
@fn z_algorithm
@brief 長さNの文字列Sについて, S[0:N-1]とS[i:N-1] (0 <= i < N)の最長共通接頭辞の長さを求める
*/
vector<int> z_algorithm(const string& s)
{
    const int n = s.size();
    vector<int> z(n);
    z[0] = n;

    int i = 1;
    int j = 0;
    while (i < n) {
        while (i+j < n && s[j] == s[i+j]) {
            ++j;
        }
        z[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }

        int k = 1;
        while (i+k < n && k+z[k] < j) {
            z[i+k] = z[k];
            ++k;
        }
        i += k;
        j -= k;
    }

    return z;
}

int main()
{
    int N;
    cin >> N;

    string S;
    cin >> S;

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        auto z = z_algorithm(S.substr(i));

        for (int j = 1; j < z.size(); ++j) {
            if (z[j] <= j) {
                ans = max(ans, z[j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
