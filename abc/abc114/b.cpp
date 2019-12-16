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
    string S;
    cin >> S;

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < S.size()-2; ++i) {
        string tmp = S;
        tmp = tmp.substr(i, 3);

        int num = stoi(tmp);
        ans = min(ans, abs(num - 753));
    }

    cout << ans << endl;

    return 0;
}
