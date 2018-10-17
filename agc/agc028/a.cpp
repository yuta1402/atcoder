#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

ull gcd(ull a, ull b)
{
    if (a > b) {
        swap(a, b);
    }

    ull r = b % a;
    while (r != 0) {
        b = a;
        a = r;
        r = b % a;
    }

    return a;
}

int main()
{
    ull N, M;
    cin >> N >> M;

    string S, T;
    cin >> S;
    cin >> T;

    ull g = gcd(N, M);
    ull L = N * M / g;

    for (ull i = 0; i < N; ++i) {
        if (i*M % N == 0) {
            ull j = i*M / N;

            if (S[i] != T[j]) {
                std::cout << -1 << std::endl;
                return 0;
            }
        }
    }

    std::cout << L << std::endl;

    return 0;
}
