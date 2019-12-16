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
    int s;
    cin >> s;

    vector<int> seq;

    int a = s;
    seq.emplace_back(a);
    for (int i = 2; i <= 1000000; ++i) {
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = 3*a + 1;
        }

        auto it = find(begin(seq), end(seq), a);
        if (it != end(seq)) {
            cout << i << endl;
            break;
        }

        seq.emplace_back(a);
    }

    return 0;
}
