#include <iostream>

using namespace std;

int main()
{
    int a,b;
    while (cin>>a>>b)
    {
        if ((b - a + 360) % 360 <= (a - b + 360) % 360) {
            cout << (b - a + 360) % 360 << '\n';
        } else {
            cout << "-" << (a - b + 360) % 360 << '\n';
        }
    }
}