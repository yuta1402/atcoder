#include <iostream>
#include <algorithm>

using namespace std;

int func(int x)
{
    int c = 0;

    while(x % 2 == 0) {
        c++;
        x /= 2;
    }

    return c;
}

int main()
{
    int N;
    cin >> N;

    int ans = 210;

    for(int i = 0; i < N; ++i) {
        int A;
        cin >> A;

        ans = min(ans, func(A));
    }

    cout << ans << endl;

    return 0;
}
