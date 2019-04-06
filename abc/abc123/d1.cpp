#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;

int main()
{
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);

    for (auto&& Ai : A) {
        cin >> Ai;
    }

    for (auto&& Bi : B) {
        cin >> Bi;
    }

    for (auto&& Ci : C) {
        cin >> Ci;
    }

    sort(begin(A), end(A), greater<ll>());
    sort(begin(B), end(B), greater<ll>());
    sort(begin(C), end(C), greater<ll>());

    vector<ll> ABC;
    for (int a = 0; a < X; ++a) {
        for (int b = 0; b < Y; ++b) {
            if ((a+1)*(b+1) > K) {
                break;
            }

            for (int c = 0; c < Z; ++c) {
                if ((a+1)*(b+1)*(c+1) > K) {
                    break;
                }

                ABC.emplace_back(A[a] + B[b] + C[c]);
            }
        }
    }

    sort(begin(ABC), end(ABC), greater<ll>());

    for (int i = 0; i < K; ++i) {
        cout << ABC[i] << endl;
    }

    return 0;
}
