#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

int main()
{
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> l(Q);
    vector<int> r(Q);

    for (int i = 0; i < Q; ++i) {
        int li, ri;
        cin >> li >> ri;
        --li;
        --ri;

        l[i] = li;
        r[i] = ri;
    }

    vector<int> part_counts(N);

    part_counts[0] = 0;

    int count = 0;
    for (int i = 1; i < part_counts.size(); ++i) {
        if (S[i-1] == 'A' && S[i] == 'C') {
            ++count;
        }

        part_counts[i] = count;
    }

    for (int i = 0; i < Q; ++i) {
        int ans = part_counts[r[i]] - part_counts[l[i]];
        cout << ans << endl;
    }

    return 0;
}
