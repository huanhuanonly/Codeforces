/**
 * Codeforces Round 1012 (Div. 1)
 * 
 * => B1. Canteen (Easy Version) ( @c 1900 )
 * 
 * -> https://codeforces.com/problemset/problem/2089/B1
 * 
 * Submissions ~> https://codeforces.com/contest/2089/submission/318629089 By huanhuanonly
 * 
 * @b Two-pointers
 * 
 * ----May 06, 2025 [21h:29m:56s]----
*/

#include <bits/stdc++.h>

using int8 = signed char;
using int16 = short;
using int32 = int;
using int64 = long long;

using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;

#ifdef __GNUC__
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;
using real128 = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, k;
        std::cin >> n >> k;

        std::vector<int64> a(n << 1), b(n << 1);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            a[i + n] = a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> b[i];
            b[i + n] = b[i];
        }

        int ans = 1;

        int64 sum_a = 0, sum_b = 0;

        for (int i = -1, j = -1; i < n * 2; )
        {
            if (sum_a > sum_b)
            {
                ans = std::max(ans, i - j + 1);

                ++i;

                sum_a += a[i];
                sum_b += b[i];
            }
            else if (sum_a < sum_b)
            {
                ++j;

                sum_a -= a[j];
                sum_b -= b[j];
            }
            else
            {
                j = i;
                
                ++i;

                sum_a = a[i];
                sum_b = b[i];
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}