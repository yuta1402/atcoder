#include <iostream>
#include <cmath>

using namespace std;

int t[100010];
int x[100010];
int y[100010];

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> t[i] >> x[i] >> y[i];
    }

    int ct, cx, cy;
    ct = cx = cy = 0;

    for(int i = 0; i < N; ++i) {
        int time = t[i] - ct;

        int d = abs(cx - x[i]) + abs(cy - y[i]);

        if(d > time) {
            cout << "No" << endl;

            return 0;
        }

        if((time - d) % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }

        ct = t[i];
        cx = x[i];
        cy = y[i];
    }

    cout << "Yes" << endl;

    return 0;
}
