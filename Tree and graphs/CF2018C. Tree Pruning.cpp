/**
 * Codeforces Round 975 (Div. 1)
 * 
 * => C. Tree Pruning ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2018/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2018/submission/333496062 By huanhuanonly
 * 
 * @b Dfs on @a Trees
 * 
 * ----August 11, 2025 [13h:39m:13s]----
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
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<std::pair<int, int>> cnt(n + 1);

        auto dfs = [&](const auto& self, int u, int fa, int deep) -> int
        {
            ++cnt[deep].first;
            
            int max = deep;

            for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
            {
                max = std::max(max, self(self, i, u, deep + 1));
            }

            ++cnt[max].second;
            return max;
        };

        dfs(dfs, 1, 0, 1);

        std::partial_sum(cnt.begin(), cnt.end(), cnt.begin(), [](const auto& lv, const auto& rv) {
            return std::make_pair(lv.first + rv.first, lv.second + rv.second);
        });

        int ans = std::numeric_limits<int>::max();

        for (int i = 1; i <= n; ++i)
        {
            ans = std::min(ans, cnt[i - 1].second + cnt[n].first - cnt[i].first);
        }

        std::cout << ans << '\n';
    }

    return 0;
}