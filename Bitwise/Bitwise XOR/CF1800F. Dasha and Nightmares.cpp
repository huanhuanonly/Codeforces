/**
 * Codeforces Round 855 (Div. 3)
 * 
 * => F. Dasha and Nightmares ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1800/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/1800/submission/319423516 By huanhuanonly
 * 
 * @b Bitwise-XOR
 * 
 * ----May 13, 2025 [01h:38m:34s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::pair<uint32, uint32>> odd, even;

    std::string s;
    while (n--)
    {
        std::cin >> s;

        std::pair<uint32, uint32> pair;

        for (const char c : s)
        {
            pair.first  |= (1U << c - 'a');
            pair.second ^= (1U << c - 'a');
        }

        if (s.size() & 1)
            odd.push_back(pair);
        else
            even.push_back(pair);
    }

    uint64 ans = 0;

    for (uint32 k : std::views::iota(0U, 26U))
    {
        auto filter = std::views::filter([&](const auto& i) -> bool { return (i.first & (1 << k)) == 0; });

        uint32 x = ((1 << 26) - 1) ^ (1 << k);

        std::map<uint32, uint32> mp;

        for (const auto& [i, j] : odd | filter)
        {
            ++mp[j ^ x];
        }

        for (const auto& [i, j] : even | filter)
        {
            ans += mp[j];
        }
    }

    std::cout << ans;

    return 0;
}