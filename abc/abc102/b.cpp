#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[110];

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i == j) {
                continue;
            }

            ans = max(ans, std::abs(a[i]-a[j]));
        }
    }

    cout << ans << endl;

    return 0;
}
