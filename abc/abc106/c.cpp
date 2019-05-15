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

    ll K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        if (S[i] != '1') {
            cout << S[i] << endl;
            return 0;
        }
    }

    cout << '1' << endl;

    return 0;
}
