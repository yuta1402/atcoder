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
    string s;
    cin >> s;

    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == s[i+1]) {
            cout << "Bad" << endl;
            return 0;
        }
    }

    cout << "Good" << endl;

    return 0;
}
