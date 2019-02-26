#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string S;
    cin >> S;

    if (S <= "2019/04/30") {
        std::cout << "Heisei" << std::endl;
    } else {
        std::cout << "TBD" << std::endl;
    }

    return 0;
}
