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

    vector<pair<int, int>> tasks;
    
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;

        tasks.emplace_back(b, a);
    }

    sort(begin(tasks), end(tasks));

    int t = 0;
    for (int i = 0; i < N; ++i) {
        t += tasks[i].second;
        if (t > tasks[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
