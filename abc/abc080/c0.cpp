#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;

ll calc_value(const vector<int>& v, const vector<vector<int>>& F, const vector<vector<int>>& P)
{
    vector<int> counts(F.size(), 0);

    for (int j = 0; j < v.size(); ++j) {
        if (v[j] == 0) {
            continue;
        }

        for (int i = 0; i < F.size(); ++i) {
            if (F[i][j] == 1) {
                ++counts[i];
            }
        }
    }

    ll value = 0;
    for (int i = 0; i < counts.size(); ++i) {
        value += P[i][counts[i]];
    }

    return value;
}

bool all_zero(const vector<int>& v)
{
    for (const auto& vi : v) {
        if (vi == 1) {
            return false;
        }
    }

    return true;
}

ll func(vector<int> v, int i, const vector<vector<int>>& F, const vector<vector<int>>& P)
{
    if (i >= 10) {
        if (all_zero(v)) {
            return -INT_MAX;
        }

        return calc_value(v, F, P);
    }

    ll max_value = -INT_MAX;

    v[i] = 0;
    max_value = max(max_value, func(v, i+1, F, P));
    v[i] = 1;
    max_value = max(max_value, func(v, i+1, F, P));

    return max_value;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> F(
        N, vector<int>(10, 0)
    );

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> F[i][j];
        }
    }

    vector<vector<int>> P(
        N, vector<int>(11, 0)
    );

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> P[i][j];
        }
    }

    vector<int> v(10, 0);
    cout << func(v, 0, F, P) << endl;

    return 0;
}
