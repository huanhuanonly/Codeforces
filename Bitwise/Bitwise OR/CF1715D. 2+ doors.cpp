/**
 * Codeforces Round 816 (Div. 2)
 * 
 * => D. 2+ doors ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1715/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1715/submission/349001259 By huanhuanonly
 * 
 * @b Bitwise-OR and @b Graph-modeling
 * 
 * ----November 15, 2025 [01h:58m:05s]----
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

    uint32 n, q;
    std::cin >> n >> q;

    constexpr auto bitcount = 30U;

    std::vector<std::tuple<uint32, uint32, uint32>> statements(q);

    std::vector<uint32> ans(n);

    for (uint32 i = 0; i < q; ++i)
    {
        uint32 u, v, x;
        std::cin >> u >> v >> x;

        --u, --v;

        statements[i] = std::make_tuple(u, v, x);

        if (u == v)
        {
            ans[u] = x;
        }
    }
    
    std::vector<bool> fixed(n);
    std::vector<std::vector<uint32>> e(n);

    for (uint32 layer = 0; layer < bitcount; ++layer)
    {
        for (uint32 i = 0; i < q; ++i)
        {
            const auto& [u, v, x] = statements[i];

            if (u == v)
            {
                fixed[u] = true;
            }
            else
            {
                if (x & (1U << layer))
                {
                    e[u].push_back(v);
                    e[v].push_back(u);
                }
                else
                {
                    fixed[u] = fixed[v] = true;
                }
            }
        }

        for (uint32 i = 0; i < n; ++i)
        {
            if (fixed[i])
            {
                continue;
            }

            for (const auto j : e[i])
            {
                if ((j < i or fixed[j]) and not (ans[j] & (1U << layer)))
                {
                    ans[i] |= 1U << layer;
                    break;
                }
            }
        }

        fixed.assign(fixed.size(), false);
        std::ranges::for_each(e, [](auto& c) -> void { c.clear(); });
    }

    for (uint32 i = 0; i < n; ++i)
    {
        std::cout << ans[i] << ' ';
    }

    return 0;
}