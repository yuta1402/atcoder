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
    int A, B;
    cin >> A >> B;

    if (A == B) {
        cout << A + B << endl;
    } else {
        int m = max(A, B);
        cout << m + m-1 << endl;
    }

    return 0;
}
