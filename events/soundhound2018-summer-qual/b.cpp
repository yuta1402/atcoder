#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    int w;

    cin >> S >> w;

    for(int i = 0; i < S.size(); i += w) {
        cout << S[i];
    }

    cout << '\n';

    return 0;
}

