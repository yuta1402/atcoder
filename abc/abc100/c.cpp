#include <iostream>

using namespace std;

int func(int x)
{
    int count = 0;

    while(x % 2 == 0) {
        count++;
        x /= 2;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ans += func(a);
    }

    cout << ans << endl;

    return 0;
}
