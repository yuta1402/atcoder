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
#include <bitset>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    string S;
    cin >> S;

    if (S == "Sunny") {
        cout << "Cloudy" << endl;
    } else if (S == "Cloudy") {
        cout << "Rainy" << endl;
    } else if (S == "Rainy") {
        cout << "Sunny" << endl;
    } 

    return 0;
}
