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
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int num_negative = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < 0) {
            ++num_negative;
        }
    }

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += abs(A[i]);
    }

    if (num_negative % 2 == 0) {
        cout << sum << endl;
    } else {
        auto it = min_element(begin(A), end(A), [](ll a, ll b){
            return abs(a) < abs(b);
        });

        cout << sum - 2 * abs(*it) << endl;
    }

    return 0;
}
