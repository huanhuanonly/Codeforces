/**
 * Codeforces Round 1059 (Div. 3)
 * 
 * => C. Beautiful XOR ( @c 1100 )
 * 
 * -> https://codeforces.com/contest/2162/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2162/submission/344252804 By huanhuanonly
 * 
 * @b Bitwise-XOR
 * 
 * ----October 19, 2025 [00h:05m:01s]----
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
        uint64 a, b;
        std::cin >> a >> b;

        std::bitset<64> sa(a), sb(b);

        std::vector<uint64> ans;

        for (uint64 i = 0; i < sa.size(); ++i)
        {
            if ((1ULL << i) > a)
            {
                break;
            }
            
            if (sa[i] != sb[i])
            {
                sa.flip(i);
                ans.push_back(1ULL << i);
            }
        }

        if (sa == sb)
        {
            std::cout << ans.size() << '\n';

            for (uint64 i : ans)
            {
                std::cout << i << ' ';
            }

            std::cout.put('\n');
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}