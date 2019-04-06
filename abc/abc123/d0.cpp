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

    vector<ll> AB;
    for (const auto& Ai: A) {
        for (const auto& Bi: B) {
            AB.emplace_back(Ai + Bi);
        }
    }

    sort(begin(AB), end(AB), greater<ll>());
    sort(begin(C), end(C), greater<ll>());

    vector<ll> ABC;

    for (int i = 0; i < min(K, (int)AB.size()); ++i) {
        for (int j = 0; j < Z; ++j) {
            ABC.emplace_back(AB[i] + C[j]);
        }
    }

    sort(begin(ABC), end(ABC), greater<ll>());

    for (int i = 0; i < K; ++i) {
        cout << ABC[i] << endl;
    }

    return 0;
}
