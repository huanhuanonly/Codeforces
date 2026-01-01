/**
 * Codeforces Global Round 31 (Div. 1 + Div. 2)
 * 
 * => D. Insolvable Disks ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2180/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2180/submission/354585967 By huanhuanonly
 * 
 * @b Greedy
 * 
 * ----December 23, 2025 [00h:01m:55s]----
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
        int64 n;
        std::cin >> n;

        std::vector<int64> v(n);
        
        for (auto& i : v)
        {
            std::cin >> i;
            i *= 10;
        }

        auto calc = [n](const auto& v) -> int64
        {
            int64 ans = 0;
    
            int64 lo = 0, hi = (1e9 + 1) * 10;
    
            for (int64 i = 0; i < n - 1; ++i)
            {
                const int64 len = v[i + 1] - v[i];
    
                if (lo > len)
                {
                    hi = std::min(std::exchange(lo, int64(0)) / 10 * 10, len);
                }
                else if (hi < len)
                {
                    lo = len - std::exchange(hi, len - lo / 10 * 10) + 5;
                    ++ans;
                }
                else
                {
                    hi = len - std::exchange(lo, int64(0)) / 10 * 10;
                    ++ans;
                }
            }

            return ans;
        };

        std::cout << calc(v) << '\n';
    }

    return 0;
}