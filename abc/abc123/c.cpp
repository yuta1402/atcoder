#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;

    vector<ll> v(5);
    for (auto&& vi : v) {
        cin >> vi;
    }

    auto it = min_element(begin(v), end(v));
    ll min_val = *it;

    ll ans = 4 + ceil(static_cast<double>(N) / min_val);

    cout << ans << endl;

    return 0;
}
