#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll sum_digits(ll x)
{
    ll sum = 0;

    while(x > 0) {
        sum += (x % 10);
        x /= 10;
    }

    return sum;
}

int main()
{
    ll N;
    cin >> N;

    ll sum = sum_digits(N);

    if (N % sum == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
