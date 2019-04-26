#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    if (A == B) {
        cout << C << endl;
    } else if(B == C) {
        cout << A << endl;
    } else if(C == A) {
        cout << B << endl;
    }

    return 0;
}
