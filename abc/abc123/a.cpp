#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;

    if (e - a <= k) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}
