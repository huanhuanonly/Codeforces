/**
 * Codeforces Round 1064 (Div. 2)
 * 
 * => E. Binary Wine ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2166/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2166/submission/349386588 By huanhuanonly
 * 
 * @b Bitwise-XOR and @b Greedy
 * 
 * ----November 17, 2025 [15h:02m:03s]----
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
        uint64 n, q;
        std::cin >> n >> q;

        std::vector<uint64> v(n);

        for (uint64 i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        std::ranges::sort(v, std::ranges::greater());

        constexpr auto bitcount = 30ULL;

        if (n > bitcount)
        {
            v.resize(bitcount);
            n = bitcount;
        }
        
        while (q--)
        {
            uint64 c;
            std::cin >> c;

            std::priority_queue que(v.begin(), v.end());
            
            uint64 sum = 0;

            for (uint64 b = bitcount; b--; )
            {
                if (not (c & (1ULL << b)))
                {
                    continue;
                }

                if (auto top = que.top(); que.pop(), top >= 1ULL << b)
                {
                    if (top & (1ULL << b))
                    {
                        top ^= 1ULL << b;
                    }
                    else
                    {
                        break;
                    }

                    que.push(top);
                }
                else
                {
                    sum += (1ULL << b) - top;
                    que.push(0);
                }
            }

            std::cout << sum << '\n';
        }
    }

    return 0;
}