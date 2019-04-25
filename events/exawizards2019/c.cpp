#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>
#include <unordered_map>

using namespace std;
using ll = long long;

enum State
{
    LEFT,
    RIGHT,
    SURVIVE,
};

State go(int x, const string& s, const vector<char>& t, const vector<char>& d)
{
    int N = s.size();
    int Q = t.size();

    for (int i = 0; i < Q; ++i) {
        if (s[x] == t[i]) {
            if (d[i] == 'L') {
                --x;
            } else {
                ++x;
            }

            if (x < 0) {
                return LEFT;
            }

            if (x >= N) {
                return RIGHT;
            }
        }
    }

    return SURVIVE;
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    string s;
    cin >> s;

    vector<char> t(Q);
    vector<char> d(Q);

    for (int i = 0; i < Q; ++i) {
        cin >> t[i] >> d[i];
    }

    int left = -1;
    int right = N;
    while (right - left > 1) {
        int middle = (left + right) / 2;

        if (go(middle, s, t, d) == LEFT) {
            left = middle;
        } else {
            right = middle;
        }
    }

    int survive_left_pos = right;

    left = -1;
    right = N;
    while (right - left > 1) {
        int middle = (left + right) / 2;

        if (go(middle, s, t, d) == RIGHT) { 
            right = middle;
        } else {
            left = middle;
        }
    }

    int survive_right_pos = left;

    cout << survive_right_pos - survive_left_pos + 1 << endl;

    return 0;
}
