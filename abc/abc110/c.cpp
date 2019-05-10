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
    string S, T;
    cin >> S;
    cin >> T;

    int N = S.size();

    unordered_map<char, char> m;
    unordered_map<char, char> mm;

    for (int i = 0; i < N; ++i) {
        auto it = m.find(S[i]);
        auto it2 = mm.find(T[i]);

        if (it == end(m)) {
            m.emplace(S[i], T[i]);
        } else if (it->second != T[i]) {
            cout << "No" << endl;
            return 0;
        }

        if (it2 == end(mm)) {
            mm.emplace(T[i], S[i]);
        } else if (it2->second != S[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
