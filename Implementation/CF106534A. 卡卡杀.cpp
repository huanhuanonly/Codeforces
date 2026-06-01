/**
 * CCPC2026黑龙江省大学生程序设计竞赛
 *
 * => A. 卡卡杀
 *
 * -> https://codeforces.com/gym/106534/problem/A
 *
 * Submissions ~> https://codeforces.com/gym/106534/submission/375410735 By huanhuanonly
 *
 * @b Implementation
 * @b Dfs on @a Trees
 * @b LCA ( @a binary-lifting )
 *
 * ----May 21, 2026 [11h:50m:06s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    constexpr int laycnt = 13;

    struct node
    {
        int depth;
        std::array<int, laycnt> up;
    };

    std::vector<node> tree(n + 1);

    auto build = [&](const auto& self, int u) -> void
    {
        for (const auto& v : e[u])
        {
            if (v != tree[u].up[0])
            {
                tree[v].depth = tree[u].depth + 1;
                tree[v].up[0] = u;

                self(self, v);
            }
        }
    };

    build(build, 1);

    for (int i = 1; i < laycnt; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            tree[u].up[i] = tree[tree[u].up[i - 1]].up[i - 1];
        }
    }

    auto lca = [&](int u, int v) -> int
    {
        if (tree[u].depth < tree[v].depth)
        {
            std::swap(u, v);
        }

        for (int i = laycnt - 1, diff = tree[u].depth - tree[v].depth; i >= 0; --i)
        {
            if (diff & (1 << i))
            {
                u = tree[u].up[i];
            }
        }

        if (u == v)
        {
            return u;
        }

        for (int i = laycnt - 1; i >= 0; --i)
        {
            if (tree[u].up[i] != tree[v].up[i])
            {
                u = tree[u].up[i];
                v = tree[v].up[i];
            }
        }

        return tree[u].up[0];
    };

    std::array<std::list<std::pair<std::vector<int>, std::pair<int, int>>>, 4> data;
    std::vector<int> ans;

    for (int i = 0; i < m; ++i)
    {
        int op, tim, s, t;
        std::cin >> op >> tim >> s >> t;

        if (s == t)
        {
            ans.push_back(i);
            continue;
        }

        std::vector<int> path;

        const int mid = lca(s, t);
        for (; s != mid; path.push_back(s), s = tree[s].up[0]);

        const int cnt = path.size();
        for (; t != mid; path.push_back(t), t = tree[t].up[0]);
        path.push_back(mid);

        std::ranges::reverse(path | std::views::drop(cnt));

        data[op - 1].emplace_back(std::move(path), std::pair(tim, i));
    }

    std::array<
        std::map<
            int,
            std::vector<std::remove_reference_t<decltype(data.front())>::iterator>>, 4> maps;

    auto kill = [&](int op, int u) -> void
    {
        for (const auto& it : maps[op][u])
        {
            data[op].erase(it);
        }

        maps[op][u].clear();
    };

    auto kill_except = [&](int op, int u, auto eit) -> void
    {
        bool found = false;

        for (const auto& it : maps[op][u])
        {
            if (it != eit)
            {
                data[op].erase(it);
            }
            else
            {
                found = true;
            }
        }

        maps[op][u].clear();

        if (found)
        {
            maps[op][u].emplace_back(eit);
        }
    };

    int ctime = 1;

    for (; data[0].size() or data[1].size() or data[2].size() or data[3].size(); ++ctime)
    {
        if (data[0].size())
        {
            if (data[0].begin()->first.size() - 1 == ctime)
            {
                ans.push_back(data[0].begin()->second.second);
                data[0].clear();
            }
            else
            {
                maps[0][data[0].begin()->first[ctime]].emplace_back(data[0].begin());
            }
        }

        for (auto it = data[1].begin(); it != data[1].end(); )
        {
            if (it->first.size() - 1 == ctime)
            {
                ans.push_back(it->second.second);
                it = data[1].erase(it);
            }
            else
            {
                if (ctime % it->second.first == 0)
                {
                    kill(0, it->first[ctime]);
                }

                maps[1][it->first[ctime]].emplace_back(it);
                ++it;
            }
        }

        for (auto it = data[2].begin(); it != data[2].end(); )
        {
            if (it->first.size() - 1 == ctime)
            {
                ans.push_back(it->second.second);
                it = data[2].erase(it);
            }
            else
            {
                if (ctime % it->second.first == 0)
                {
                    kill(1, it->first[ctime]);
                }

                maps[2][it->first[ctime]].emplace_back(it);
                ++it;
            }
        }

        std::vector<std::pair<int, std::remove_reference_t<decltype(data.front())>::iterator>> que;

        for (auto it = data[3].begin(); it != data[3].end(); )
        {
            if (it->first.size() - 1 == ctime)
            {
                ans.push_back(it->second.second);
                it = data[3].erase(it);
            }
            else
            {
                if (ctime % it->second.first == 0)
                {
                    kill(1, it->first[ctime]);
                    kill(2, it->first[ctime]);
                    que.emplace_back(it->first[ctime], it);
                }

                maps[3][it->first[ctime]].emplace_back(it);
                ++it;
            }
        }

        for (const auto& [key, it] : que)
        {
            kill_except(3, key, it);
        }

        if (data[0].size() and ctime % data[0].begin()->second.first == 0)
        {
            kill(1, data[0].begin()->first[ctime]);
            kill(2, data[0].begin()->first[ctime]);
            kill(3, data[0].begin()->first[ctime]);
        }

        maps[0].clear();
        maps[1].clear();
        maps[2].clear();
        maps[3].clear();
    }

    std::ranges::sort(ans);

    std::cout << ans.size() << '\n';

    for (int i : ans)
    {
        std::cout << 1 + i << '\n';
    }

    return 0;
}