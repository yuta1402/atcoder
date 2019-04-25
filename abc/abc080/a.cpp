#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    cout << min(N * A, B) << endl;

    return 0;
}
