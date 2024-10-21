/**
 * Codeforces Round 964 (Div. 4)
 * 
 * => G2. Ruler (hard version)
 * 
 * -> https://codeforces.com/problemset/problem/1999/G2
 * 
 * @b TernarySearch
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        auto query = [](int x, int y) -> int
        {
            std::cout << "? " << x << ' ' << y << std::endl;

            int res;
            std::cin >> res;

            return res;
        };

        int l = 1, r = 999, mid1, mid2;

        while (r - l > 1)
        {
            mid1 = l + (r - l) / 3, mid2 = l + (r - l) * 2 / 3;

            int res = query(mid1, mid2);

            if (res == mid1 * (mid2 + 1))
                l = mid1, r = mid2;
            else if (res == mid1 * mid2)
                l = mid2;
            else if (res == (mid1 + 1) * (mid2 + 1))
                r = mid1;
        }

        std::cout << "! " << r << std::endl;
    }

    return 0;
}