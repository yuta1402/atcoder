#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    set<int> d;

    for(int i = 0; i < N; ++i) {
        int di;
        cin >> di;
        d.emplace(di);
    }

    cout << d.size() << endl;

    return 0;
}
