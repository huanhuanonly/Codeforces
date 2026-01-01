/**
 * Codeforces Round 670 (Div. 2)
 * 
 * => C. Link Cut Centroids ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1406/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1406/submission/344065359 By huanhuanonly
 * 
 * @b Dfs to find @a Tree-centroid
 * 
 * ----October 17, 2025 [00h:56m:09s]----
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

        std::vector<int> sizes(n + 1, 1);
        std::vector<int> fa(n + 1);

        auto dfs = [&](const auto& self, int u) -> void
        {
            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa[u]; }))
            {
                fa[i] = u;
                self(self, i);
                sizes[u] += sizes[i];
            }
        };

        dfs(dfs, 1);

        std::pair<int, std::vector<int>> centroids{std::numeric_limits<int>::max(), {}};

        for (int u = 1; u <= n; ++u)
        {
            int max = sizes[1] - sizes[u];

            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa[u]; }))
            {
                max = std::max(max, sizes[i]);
            }

            if (max < centroids.first)
            {
                centroids.first = max;
                centroids.second = {u};
            }
            else if (max == centroids.first)
            {
                centroids.second.push_back(u);
            }
        }

        if (centroids.second.size() == 1)
        {
            std::cout << 1 << ' ' << e[1].front() << '\n';
            std::cout << 1 << ' ' << e[1].front() << '\n';
        }
        else
        {
            int child = e[centroids.second.front()][0];
            
            if (child == centroids.second.back())
            {
                child = e[centroids.second.front()][1];
            }

            std::cout << centroids.second.front() << ' ' << child << '\n';
            std::cout << centroids.second.back()  << ' ' << child << '\n';
        }
    }

    return 0;
}