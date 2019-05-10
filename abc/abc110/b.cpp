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

bool valid(int X, int Y, int Z, int x, int y)
{
    if (X <= Z && Z <= Y && x < Z && y >= Z) {
        return true;
    }

    return false;
}

int main()
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<int> x(N);
    vector<int> y(M);

    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> y[i];
    }

    for (int z = 0; z <= 100; ++z) {
        if (X >= z || z > Y) {
            continue;
        }

        bool x_ok = all_of(begin(x), end(x), [z](int xi) {
            return xi < z;
        });

        if (!x_ok) {
            continue;
        }

        bool y_ok = all_of(begin(y), end(y), [z](int yi) {
            return yi >= z;
        });

        if (!y_ok) {
            continue;
        }

        cout << "No War" << endl;
        return 0;
    }

    cout << "War" << endl;
    return 0;
}
