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

int main()
{
    string S;
    cin >> S;

    bool ok = true;

    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 1) {
            ok = ok && !(S[i] == 'R');
        } else {
            ok = ok && !(S[i] == 'L');
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
