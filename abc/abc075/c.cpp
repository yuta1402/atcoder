#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

bool is_connected(const vector<vector<int>>& g)
{
    vector<int> visited(g.size(), 0);

    queue<int> que;
    que.push(0);

    visited[0] = 1;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (const auto& u : g[v]) {
            if (!visited[u]) {
                visited[u] = 1;
                que.push(u);
            }
        }
    }

    for (int i = 0; i < visited.size(); ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> a(M);
    vector<int> b(M);
    vector<vector<int>> g(N);

    for (int i = 0; i < M; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;

        a[i] = ai;
        b[i] = bi;

        g[ai].emplace_back(bi);
        g[bi].emplace_back(ai);
    }

    int ans = 0;

    for (int i = 0; i < M; ++i) {
        auto gg = g;

        // remove edge (a[i], b[i])
        gg[a[i]].erase(remove(begin(gg[a[i]]), end(gg[a[i]]), b[i]), end(gg[a[i]]));
        gg[b[i]].erase(remove(begin(gg[b[i]]), end(gg[b[i]]), a[i]), end(gg[b[i]]));

        if (!is_connected(gg)) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
