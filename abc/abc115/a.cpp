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
    int D;
    cin >> D;

    if (D == 25) {
        cout << "Christmas" << endl;
    } else if (D == 24) {
        cout << "Christmas Eve" << endl;
    } else if (D == 23) {
        cout << "Christmas Eve Eve" << endl;
    } else {
        cout << "Christmas Eve Eve Eve" << endl;
    }

    return 0;
}
