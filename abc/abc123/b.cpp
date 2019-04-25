#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;
using ll = long long;

int calc(const vector<int>& v)
{
    int time = 0;

    for (int i = 0; i < v.size()-1; ++i) {
        time += v[i];
        if (time % 10 != 0) {
            time += 10 - (time % 10);
        }
    }

    time += v[v.size()-1];

    return time;
}

int main()
{
    vector<int> v(5);
    for (auto&& vi : v) {
        cin >> vi;
    }

    int ans = 1000;

    do {
        ans = min(ans, calc(v));
    } while (next_permutation(begin(v), end(v)));

    cout << ans << endl;

    return 0;
}
