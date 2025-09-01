/**
 * Codeforces Round 1037 (Div. 3)
 * 
 * => G1. Big Wins! (easy version) ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2126/problem/G1
 * 
 * Submissions ~> https://codeforces.com/contest/2126/submission/330655875 By huanhuanonly
 * 
 * @b Enumeration and @b Prefix-sum
 * 
 * ----July 25, 2025 [01h:32m:02s]----
*/

/// @brief This is an @c interesting problem!

/**
 * On the technique of median-based criteria:
 * 
 *    Let the median be x.
 * 
 *    Assign each number a value of @c -1 if it is less than x,
 *    and @c +1 if it is greater than or equal to x.
 * 
 *    If there exists a subarray whose sum is non-negative, then the median is at least x.
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
        int n;
        std::cin >> n;
    
        std::vector<int> v(n + 1);
    
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }
    
        int ans = 0;
    
        for (int med = 1; med <= 100; ++med)
        {
            auto $ = [&](int i) -> int
            {
                return i >= med ? 1 : -1;
            };
    
            std::vector<int> presum(n + 1);

            int premin = 0;
            std::vector<int> sufmax(n + 1);

            for (int i = 1; i <= n; ++i)
            {
                presum[i] = presum[i - 1] + $(v[i]);
            }

            sufmax[n] = presum[n];
            for (int i = n - 1; i >= 1; --i)
            {
                sufmax[i] = std::max(presum[i], sufmax[i + 1]);
            }

            for (int i = 1; i <= n; ++i)
            {
                if (sufmax[i] - premin >= 0)
                {
                    ans = std::max(ans, med - v[i]);
                }

                premin = std::min(premin, presum[i]);
            }
        }
    
        std::cout << ans << '\n';
    }

    return 0;
}