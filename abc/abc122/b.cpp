#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

bool is_atcg_string(char c)
{
    if (c == 'A') {
        return true;
    }

    if (c == 'C') {
        return true;
    }

    if (c == 'G') {
        return true;
    }

    if (c == 'T') {
        return true;
    }

    return false;
}

int main()
{
    string S;
    cin >> S;

    int max_count = 0;
    for (int i = 0; i < S.size(); ++i) {
        int count = 0;

        for (int j = i; j < S.size(); ++j) {
            if (!is_atcg_string(S[j])) {
                break;
            }
            ++count;
        }

        max_count = max(count, max_count);
    }

    cout << max_count << endl;

    return 0;
}
