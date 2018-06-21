#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int n = b - a;

    int height = n * (n+1) / 2;

    cout << height - b << endl;

    return 0;
}
