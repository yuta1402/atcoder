#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
int distances[30][30];
int colors[500][500];

int distance_table[3][30];

int distance(int r, int c)
{
    int d = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((i + j) % 3 == r) {
                d += distances[colors[i][j]][c];
            }
        }
    }

    return d;
}

int func(int c0, int c1, int c2)
{
    int d = 0;

    d += distance_table[0][c0];
    d += distance_table[1][c1];
    d += distance_table[2][c2];

    return d;
}

int main()
{
    cin >> n >> c;

    for(int i = 0; i < c; ++i) {
        for(int j = 0; j < c; ++j) {
            int d;
            cin >> d;
            distances[i][j] = d;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int c;
            cin >> c;
            colors[i][j] = c - 1;
        }
    }

    for(int r = 0; r < 3; ++r) {
        for(int ci = 0; ci < c; ++ci) {
            distance_table[r][ci] = distance(r, ci);
        }
    }

    // inf
    int ans = 500 * 500 * 1000;

    for(int c0 = 0; c0 < c; ++c0) {
        for(int c1 = 0; c1 < c; ++c1) {
            for(int c2 = 0; c2 < c; ++c2) {
                if(c0 == c1 || c1 == c2 || c2 == c0) {
                    continue;
                }

                ans = min(ans, func(c0, c1, c2));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
