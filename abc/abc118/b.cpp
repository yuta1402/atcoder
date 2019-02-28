#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> v(M, 0);

    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;

        for (int j = 0; j < K; ++j) {
            int a;
            cin >> a;
            ++v[a-1];
        }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        if (v[i] == N) {
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
