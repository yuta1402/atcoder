#include <iostream>

using namespace std;

int func(int x)
{
    int sum = 0;

    while(x != 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int sum = 0;

    for(int i = 1; i <= N; ++i) {
        int x = func(i);
        if(A <= x && x <= B) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}
