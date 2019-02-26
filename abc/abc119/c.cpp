#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int calc(const vector<int>& v, const vector<int>& L, const vector<int>& ABC)
{
    int mp = 0;
    int min_sum_length = std::numeric_limits<int>::max();

    for (int i = 0; i < 3; ++i) {
        int count = 0;
        int sum_length = 0;

        for (int j = 0; j < v.size(); ++j) {
            if (v[j] == i) {
                ++count;
                sum_length += L[j];
            }
        }

        min_sum_length = min(sum_length, min_sum_length);

        if (count > 1) {
            mp += (count-1) * 10;
        }

        mp += abs(sum_length - ABC[i]);
    }

    if (min_sum_length > 0) {
        return mp;
    }

    return std::numeric_limits<int>::max();
}

int dfs(int depth, vector<int> v, const vector<int>& L, const vector<int>& ABC)
{
    if (depth == L.size()) {
        return calc(v, L, ABC);
    }

    int min = std::numeric_limits<int>::max();

    for (int i = 0; i < 4; ++i) {
        v[depth] = i;
        int mp = dfs(depth+1, v, L, ABC);
        min = std::min(mp, min);
    }

    return min;
}

int main()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<int> ABC{ A, B, C };

    vector<int> L(N);
    for (auto&& Li : L) {
        cin >> Li;
    }

    vector<int> v(N, 0);

    int ans = dfs(0, v, L, ABC);
    std::cout << ans << std::endl;

    return 0;
}
