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
    int N;
    cin >> N;

    string s;
    cin >> s;

    int red_count = 0;
    for (char c : s) {
        if (c == 'R') {
            ++red_count;
        }
    }

    int blue_count = N - red_count;
    if (red_count > blue_count) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
