#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template<class T>
bool is_prime(T x)
{
    if (x == 2) {
        return true;
    }

    if (x % 2 == 0) {
        return false;
    }

    for (T i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int N;
    cin >> N;

    unordered_map<int, int> primes;
    for (int i = 2; i <= 100; ++i) {
        if (is_prime(i)) {
            primes[i] = 0;
        }
    }

    for (int i = 1; i <= N; ++i) {
        int n = i;
        for (auto&& p : primes) {
            while (n % p.first == 0) {
                p.second++;
                n /= p.first;
            }
        }
    }

    int ans = 0;

    auto num = [&primes](int m){
        return count_if(begin(primes), end(primes), [m](const auto& p){ return p.second >= m-1; });
    };

    ans += num(75);
    ans += num(25) * (num(3) - 1);
    ans += num(15) * (num(5) - 1);
    ans += num( 5) * (num(5) - 1) * (num(3) - 2) / 2;

    cout << ans << endl;

    return 0;
}
