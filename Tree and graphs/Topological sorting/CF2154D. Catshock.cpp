/**
 * Codeforces Round 1060 (Div. 2)
 * 
 * => D. Catshock ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2154/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2154/submission/344736570 By huanhuanonly
 * 
 * @b Topological-sorting on @a Trees
 * 
 * ----October 19, 2025 [00h:23m:26s]----
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

        struct node
        {
            int parent;
            int depth;
            int count;
        };

        std::vector<node> tree(n + 1);

        std::queue<int> que;

        auto dfs = [&](const auto& self, int u) -> void
        {
            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != tree[u].parent; }))
            {
                ++tree[u].count;

                tree[i].parent = u;
                tree[i].depth = tree[u].depth + 1;

                self(self, i);
            }

            if (tree[u].count == 0)
            {
                que.push(u);
            }
        };

        dfs(dfs, 1);

        std::vector<int> mpath;
        mpath.reserve(n);

        std::vector<bool> inpath(n + 1);
        inpath[n] = true;

        for (int i = tree[n].parent; i != 0; i = tree[i].parent)
        {
            mpath.push_back(i);
            inpath[i] = true;
        }

        std::vector<std::pair<int, int>> ans;
        ans.reserve(n * 3);

        int cnt = 0;

        while (not que.empty())
        {
            int u = que.front();
            que.pop();

            if (inpath[u])
            {
                continue;
            }

            if (not ((cnt & 1) != (tree[u].depth & 1) or cnt < tree[u].depth))
            {
                ans.push_back({1, u});
                ++cnt;
            }

            ans.push_back({2, u});
            ans.push_back({1, u});
            ++cnt;

            if (--tree[tree[u].parent].count == 0)
            {
                que.push(tree[u].parent);
            }
        }

        for (int u : mpath | std::views::reverse)
        {
            if (not ((cnt & 1) != (tree[u].depth & 1) or cnt < tree[u].depth))
            {
                ans.push_back({1, u});
                ++cnt;
            }

            ans.push_back({2, u});
            ans.push_back({1, u});
            ++cnt;
        }

        if (not ans.empty() and ans.back().first == 1)
        {
            ans.pop_back();
        }

        std::cout << ans.size() << '\n';

        for (int i = 0; i < ans.size(); ++i)
        {
            if (ans[i].first == 1)
            {
                std::cout << 1 << '\n';
            }
            else
            {
                std::cout << 2 << ' ' << ans[i].second << '\n';
            }
        }
    }

    return 0;
}