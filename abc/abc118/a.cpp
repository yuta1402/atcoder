#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    if (B % A == 0) {
        std::cout << A + B << std::endl;
    } else {
        std::cout << B - A << std::endl;
    }

    return 0;
}
