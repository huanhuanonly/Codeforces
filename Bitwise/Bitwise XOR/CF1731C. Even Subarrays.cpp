/**
 * Codeforces Round 841 (Div. 2) and Divide by Zero 2022
 * 
 * => C. Even Subarrays ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1731/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1731/submission/343831874 By huanhuanonly
 * 
 * @b Bitwise-XOR
 * @b Prefix-sum
 * @b Number-theory ( @a divisor )
 * 
 * ----October 15, 2025 [16h:52m:16s]----
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

    constexpr auto maxn = std::bit_floor(static_cast<uint32>(2e5) << 1);

    std::vector<uint32> dcnt(maxn + 1);

    for (uint32 i = 1; i <= maxn; ++i)
    {
        for (uint32 j = 1; i * j <= maxn; ++j)
        {
            ++dcnt[i * j];
        }
    }

    std::vector st{0U};
    st.reserve(512 + 1);

    for (uint32 i = 1; i <= maxn; ++i)
    {
        if (dcnt[i] & 1)
        {
            st.push_back(i);
        }
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        uint64 n;
        std::cin >> n;

        std::vector<uint32> v(n + 1);

        for (uint64 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            v[i] ^= v[i - 1];
        }

        uint64 ans = n * (n + 1) / 2;

        std::vector<uint32> cnt(std::bit_floor(n << 1));
        cnt[v[0]] = 1;

        for (uint64 i = 1; i <= n; ++i)
        {
            for (auto j : st | std::views::filter([&](auto j) -> bool { return (v[i] ^ j) < cnt.size(); }))
            {
                ans -= cnt[v[i] ^ j];
            }

            ++cnt[v[i]];
        }

        std::cout << ans << '\n';
    }

    return 0;
}