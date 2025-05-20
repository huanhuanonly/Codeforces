/**
 * Codeforces Round 1023 (Div. 2)
 * 
 * => D. Apple Tree Traversing ( @c Rating )
 * 
 * -> https://codeforces.com/contest/2107/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2107/submission/318735398 By huanhuanonly
 * 
 * @b Bfs to find @a Tree-diameter
 * 
 * ----May 07, 2025 [21h:53m:04s]----
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

        std::vector<std::tuple<int, int, int>> ans;
        ans.reserve(n);

        std::vector<int> prev(n + 1);
        std::vector<bool> vis(n + 1);

        auto bfs = [&](int start) -> std::pair<int, int>
        {
            // size, id
            std::pair<int, int> result;

            std::queue<std::pair<int, int>> que;
            que.emplace(1, start);
            prev[start] = 0;

            std::vector<bool> st(n + 1);
            st[start] = true;

            while (not que.empty())
            {
                auto [size, id] = que.front();
                result = std::max(result, que.front());
                que.pop();

                for (const auto& i : e[id] | std::views::filter([&](int i) -> bool { return not vis[i] and not st[i]; }))
                {
                    st[i] = true;
                    que.emplace(size + 1, i);
                    prev[i] = id;
                }
            }

            return result;
        };

        auto find_diameter = [&](int start) -> std::tuple<int, int, int>
        {
            std::tuple<int, int, int> result;

            std::tie(std::ignore, std::get<1>(result)) = bfs(start);
            std::tie(std::get<0>(result), std::get<2>(result)) = bfs(std::get<1>(result));

            if (std::get<1>(result) < std::get<2>(result))
            {
                std::swap(std::get<1>(result), std::get<2>(result));
            }

            return result;
        };

        auto erase_path = [&](int u, int v) -> void
        {
            // From v to u
            if (prev[v])
            {
                std::swap(u, v);
            }

            for (; u != v; u = prev[u])
            {
                vis[u] = true;
            }

            vis[v] = true;
        };

        for (int i = 1; i <= n; ++i)
        {
            while (not vis[i])
            {
                auto [size, u, v] = find_diameter(i);
                erase_path(u, v);
    
                ans.emplace_back(size, u, v);
            }
        }

        std::sort(ans.begin(), ans.end(), std::greater());

        for (const auto& [a, b, c] : ans)
        {
            std::cout << a << ' ' << b << ' ' << c << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}