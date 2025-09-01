/**
 * Educational Codeforces Round 180 (Rated for Div. 2)
 * 
 * => D. Reachability and Tree ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2112/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2112/submission/325818204 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----June 24, 2025 [00h:52m:58s]----
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

        std::vector<int> d(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);

            ++d[u], ++d[v];
        }

        std::vector<std::pair<int, int>> ans;
        ans.reserve(n - 1);

        int start;
        bool found = false;

        for (int i = 1; i <= n; ++i)
        {
            if (d[i] == 2)
            {
                found = true;
                start = i;
            }
        }

        if (not found)
        {
            std::cout << "NO\n";
            continue;
        }

        bool r = false;

        auto dfs = [&](const auto& self, int u, int fa, int lay) -> void
        {
            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
            {
                if (lay & 1)
                {
                    ans.push_back({u, i});
                }
                else
                {
                    ans.push_back({i, u});
                }

                if (not r and u == start)
                {
                    r = true;
                    ans.back() = {ans.back().second, ans.back().first};
                    self(self, i, u, lay);
                }
                else
                {
                    self(self, i, u, lay + 1);
                }
            }
        };

        dfs(dfs, start, 0, 0);

        std::cout << "YES\n";

        for (const auto& [u, v] : ans)
        {
            std::cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}