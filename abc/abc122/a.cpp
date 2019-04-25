#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

int main()
{
    char b;
    cin >> b;

    if (b == 'A') {
        cout << 'T' << endl;
    } else if (b == 'T'){
        cout << 'A' << endl;
    } else if (b == 'C'){
        cout << 'G' << endl;
    } else if (b == 'G'){
        cout << 'C' << endl;
    }

    return 0;
}
