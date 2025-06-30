#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double sum = 0, k, x, z, d = 1, y, e;
    cout << "k=";
    cin >> k;
    e = pow (10,-k);
    cout << "x=";
    cin >> x;
    if (x == 1) {
        cout << "0" << endl;
        cout << "The Result by function is:" << log(x) << endl;
        return 0;
    }
    z = (x + 1) / (x - 1);
    double step = ((x - 1) * (x - 1)) / ((x + 1) * (x + 1));
    while (abs(z)>=e)
    {
        z *= step;
        y = (1 / d) * z;
        sum = sum + y;
        d = d + 2;
    }

    cout << "The Result by taylor is:" << 2 * sum << endl;
    cout << "The Result by function is:" << log(x) << endl;
    return 0;
}
