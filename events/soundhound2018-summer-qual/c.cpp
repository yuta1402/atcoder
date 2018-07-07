#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
    ll n, m, d;

    cin >> n >> m >> d;

    double ans;

    if(d == 0) {
        ans = static_cast<double>(m-1) / n;
    } else {
        ans = static_cast<double>(m-1) * (n-d) * 2.0 / (n*n);
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
