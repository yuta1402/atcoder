#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string candidates[4] = { "dream", "dreamer", "erase", "eraser" };

int main()
{
    string S;
    cin >> S;

    reverse(begin(S), end(S));

    for(auto& c : candidates) {
        reverse(begin(c), end(c));
    }

    string::size_type cpos = 0;

    while(cpos < S.size()) {
        bool can = false;

        for(const auto& c : candidates) {
            auto pos = S.find(c, cpos);

            if(pos == cpos) {
                can = true;
                cpos += c.size();
                break;
            }
        }

        if(!can) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
