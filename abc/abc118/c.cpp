#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<ll> A(N);
    for (auto&& Ai : A) {
        cin >> Ai;
    }

    while(true) {
        if (A.size() == 1) {
            break;
        }

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                if (i != j) {
                    A[j] %= A[i];
                }
            }
            A.erase(remove(A.begin(), A.end(), 0), A.end());
        }
    }

    std::cout << A[0] << std::endl;

    return 0;
}
