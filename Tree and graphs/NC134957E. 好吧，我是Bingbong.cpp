/**
 * 牛客周赛 Round 144
 *
 * => E-好吧，我是Bingbong ( @c 1600 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134957/E
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83649476 By huanhuanonly
 *
 * @b Dfs on @a Trees
 *
 * ----May 20, 2026 [11h:42m:22s]----
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

    int n;
    std::cin >> n;

    std::vector<uint64> h(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> h[i];
    }

    std::vector<uint64> f(n + 1), w(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        std::cin >> f[i];
    }

    for (int i = 2; i <= n; ++i)
    {
        std::cin >> w[i];
    }

    std::vector<std::vector<std::pair<uint64, int>>> e(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        e[f[i]].emplace_back(w[i], i);
    }

    std::ranges::for_each(e, std::ranges::sort);

    std::vector<uint64> ans(n + 1);

    auto dfs = [&, sum = uint64{}](auto& self, int u) mutable -> void
    {
        uint64 add = 0;

        for (const auto& [w, v] : e[u])
        {
            sum += w - add;
            add = w;

            self(self, v);
        }

        sum += h[u] - add;
        ans[u] = sum;
    };

    dfs(dfs, 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cout << ans[i] << ' ';
    }

    return 0;
}