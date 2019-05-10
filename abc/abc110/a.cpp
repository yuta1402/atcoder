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
    int A, B, C;
    cin >> A >> B >> C;

    if (A >= B && A >= C) {
        cout << 10 * A + B + C << endl;
    } else if (B >= A && B >= C) {
        cout << 10 * B + A + C << endl;
    } else {
        cout << 10 * C + A + B << endl;
    }

    return 0;
}
