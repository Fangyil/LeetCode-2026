#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;

        if (x % 10 == 0)
            x = x / 10;

        while (x != 0)
        {
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0;
            ans = ans * 10 + x % 10;
            x = x / 10;
            cout << x << " " << ans << endl;
        }

        if (x < 0)
            return -ans;
        return ans;
    }
};

// int main()
// {
//     Solution t1;
//     int input;

//     cin >> input;
//     cout << t1.reverse(input);

//     return 0;
// }
