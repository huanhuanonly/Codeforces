/**
 * Educational Codeforces Round 103 (Rated for Div. 2)
 * 
 * => B. Inflation ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/1476/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/1476/submission/329747024 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----July 19, 2025 [17h:20m:17s]----
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
        int64 n, k;
        std::cin >> n >> k;

        std::vector<int64> v(n);

        for (int64& i : v)
        {
            std::cin >> i;
        }

        int64 sum = v[0];

        int64 ans = 0;
        
        for (int i = 1; i < n; ++i)
        {
            auto check = [&](int64 mid) -> bool
            {
                return v[i] * 100ULL <= k * (sum + mid);
            };
            
            int64 l = -1, r = 1e11, mid;

            while (r - l > 1)
            {
                mid = l + r >> 1;

                if (check(mid))
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }

            sum += r + v[i];
            ans += r;
        }

        std::cout << ans << '\n';
    }

    return 0;
}