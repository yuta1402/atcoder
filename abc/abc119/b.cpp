#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<double> x(N);
    vector<string> u(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> u[i];
    }

    double ans = 0.0;

    for (int i = 0 ; i < N; i++) {
        if (u[i] == "BTC") {
            ans += x[i] * 380000.0;
        } else {
            ans += x[i];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
