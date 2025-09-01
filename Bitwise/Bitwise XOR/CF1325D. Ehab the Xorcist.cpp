/**
 * Codeforces Round 628 (Div. 2)
 * 
 * => D. Ehab the Xorcist ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1325/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1325/submission/326313696 By huanhuanonly
 * 
 * @b Bitwise-XOR
 * 
 * ----June 28, 2025 [00h:35m:35s]----
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

    uint64 u, v;
    std::cin >> u >> v;

    if (v < u)
    {
        std::cout << -1;
    }
    else if (v == u)
    {
        if (u)
        {
            std::cout << 1 << '\n' << u;
        }
        else
        {
            std::cout << 0;
        }
    }
    else
    {
        std::vector<uint64> ans{u};
        v -= u;

        bool remain = v & 1;

        if ((u & (v >> 1)) == 0)
        {
            ans.back() |= v >> 1;
        }
        else
        {
            ans.push_back(v >> 1);
        }

        ans.push_back(v >> 1);

        remain ? ans.push_back(1) : void();

        if (std::reduce(ans.begin(), ans.end(), 0ULL, std::bit_xor()) == u)
        {
            std::cout << ans.size() << '\n';
            std::ranges::for_each(ans, [](uint64 i) -> void { std::cout << i << ' '; });
        }
        else
        {
            std::cout << -1;
        }
    }

    return 0;
}