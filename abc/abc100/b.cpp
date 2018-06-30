#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int d, n;
    cin >> d >> n;

    if(n == 100) {
        n = 101;
    }

    int ans = 1;

    for(int i = 0; i < d; ++i) {
        ans *= 100;
    }

    ans *= n;
    cout << ans << endl;

    return 0;
}
