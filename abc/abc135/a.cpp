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
    int A, B;
    cin >> A >> B;

    int k = (A + B) / 2;

    if (abs(A - k) == abs(B - k)) {
        cout << k << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
