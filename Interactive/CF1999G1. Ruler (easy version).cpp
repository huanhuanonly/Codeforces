/**
 * Codeforces Round 964 (Div. 4)
 * 
 * => G1. Ruler (easy version) ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/1999/problem/G1
 * 
 * Submissions ~> https://codeforces.com/contest/1999/submission/274892469 By huanhuanonly
 * 
 * @b Interactive and @b Binary-search
 * 
 * ----August 06, 2024 [00h:13m:40s]----
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
        int l = 1, r = 999, mid;

        auto check = [](int mid) -> bool
        {
            std::cout << "? " << mid << ' ' << mid << std::endl;

            int v;
            std::cin >> v;
            
            return v > mid * mid;
        };

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
                r = mid;
            else
                l = mid;
        }

        std::cout << "! " << r << std::endl;
    }

    return 0;
}