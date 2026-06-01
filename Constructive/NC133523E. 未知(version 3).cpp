/**
 * 牛客周赛 Round 141
 *
 * => E-未知(version 3) ( @c 1700 )
 *
 * -> https://ac.nowcoder.com/acm/contest/133523/E
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83424596 By huanhuanonly
 *
 * @b Constructive and @b Trees
 *
 * ----April 26, 2026 [20h:32m:11s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    do
    {
        uint64 n, m;
        std::cin >> n >> m;

        if (not (m * 2 <= n and n <= m * (m + 1) / 2 + 1))
        {
            std::cout << "NO\n";
            break;
        }

        std::cout << "YES\n";

        uint64 diff = m * (m + 1) / 2 + 1 - n;

        std::vector<uint64> cnt(m + 1);
        std::ranges::iota(cnt | std::views::reverse, 1);
        cnt[0] = 1;

        for (int i = 1; i <= m; ++i)
        {
            const uint64 t = std::min(diff, cnt[i] - 2);
            diff -= t;
            cnt[i] -= t;
        }

        std::vector<std::vector<int>> ps(m + 1);

        for (int i = 0, idx = 0; i <= m; ++i)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                ps[i].push_back(++idx);
            }
        }

        std::vector<std::pair<int, int>> ans;
        ans.reserve(n - 1);

        for (uint64 i = 1; i <= m; ++i)
        {
            for (uint64 j = 0; j < cnt[i]; ++j)
            {
                ans.emplace_back(ps[i - 1][std::min(j + 1, cnt[i - 1] - 1)], ps[i][j]);
            }
        }

        for (const auto& [u, v] : ans)
        {
            std::cout << u << ' ' << v << '\n';
        }
    } while (false);

    return 0;
}