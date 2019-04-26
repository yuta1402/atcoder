#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> S(H);

    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '#') {
                cout << '#';
                continue;
            }

            int count = 0;

            for (int k = -1; k <= +1; ++k) {
                for (int l = -1; l <= +1; ++l) {
                    int y = i + k;
                    int x = j + l;

                    if (y < 0 || H <= y) {
                        continue;
                    }

                    if (x < 0 || W <= x) {
                        continue;
                    }

                    if (S[y][x] == '#') {
                        ++count;
                    }
                }
            }

            cout << count;
        }

        cout << endl;
    }

    return 0;
}
