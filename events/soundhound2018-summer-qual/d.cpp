#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;
using ull = unsigned long long;
using P = pair<ull, int>;

static const ull Money = 1e15;

struct Edge
{
    int to;
    int cost[2];

    Edge(int to_, int cost_y_, int cost_s_) :
        to{ to_ }
    {
        cost[0] = cost_y_;
        cost[1] = cost_s_;
    }

};

using Edges = vector<vector<Edge>>;


void dijkstra(int s, int flag, vector<ull>& d, Edges& edges)
{
    priority_queue<P, vector<P>, greater<P>> que;

    d[s] = 0;
    que.emplace(0, s);

    while(!que.empty()) {
        P p = que.top();
        que.pop();

        int v = p.second;

        if(d[v] < p.first) {
            continue;
        }

        for(int i = 0; i < edges[v].size(); ++i) {
            Edge e = edges[v][i];
            if(d[e.to] > d[v] + e.cost[flag]) {
                d[e.to] = d[v] + e.cost[flag];
                que.emplace(d[e.to], e.to);
            }
        }
    }
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    s--;
    t--;

    Edges edges(n);

    for(int i = 0; i < m; ++i) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;

        u--;
        v--;

        edges[u].emplace_back(v, a, b);
        edges[v].emplace_back(u, a, b);
    }

    vector<ull> ds(n, numeric_limits<ull>::max());
    vector<ull> dt(n, numeric_limits<ull>::max());

    dijkstra(s, 0, ds, edges);
    dijkstra(t, 1, dt, edges);

    vector<ull> costs(n);

    ull c = numeric_limits<ull>::max();
    for(int i = 0; i < n; ++i) {
        c = min(c, ds[n-i-1] + dt[n-i-1]);
        costs[i] = c;
    }

    reverse(begin(costs), end(costs));

    for(int i = 0; i < n; ++i) {
        cout << Money - costs[i] << endl;
    }

    return 0;
}
