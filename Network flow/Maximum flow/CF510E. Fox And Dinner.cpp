/**
 * Codeforces Round 290 (Div. 2)
 * 
 * => E. Fox And Dinner ( @c 2300 )
 * 
 * -> https://codeforces.com/contest/510/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/510/submission/262142485 By huanhuanonly
 * 
 * @b Dinic for @a Max-flow ( @a bipartite-graph-with-modeling )
 * 
 * ----May 22, 2024 [20h:12m:11s]----
*/

/// @brief This is an @c interesting problem!

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

template<typename T>
bool is_prime(T n)
{
    if (n <= 3) return n > 1;

    if (n % 6 != 1 && n % 6 != 5) return false;

    for (int i = 5; i <= std::sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

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

    std::vector<int> v(n);

    std::vector<int> odd, even;

    struct edge
    {
        int to, w, rid;
        bool is_reverse;
    };

    std::vector<std::vector<edge>> e(n + 2 + 1);

    int s = e.size() - 1, t = e.size() - 2;

    auto add_edge = [&](int u, int v, int w) -> void
    {
        e[u].push_back({v, w, int(e[v].size()), false});
        e[v].push_back({u, 0, int(e[u].size() - 1), true});
    };

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];

        if (v[i] & 1)
            odd.push_back(i);
        else
            even.push_back(i);
    }

    for (int i = 0; i < odd.size(); ++i)
        add_edge(s, i + 1, 2);
    
    for (int i = 0; i < even.size(); ++i)
        add_edge(odd.size() + i + 1, t, 2);

    for (int i = 0; i < odd.size(); ++i)
        for (int j = 0; j < even.size(); ++j)
            if (is_prime(v[odd[i]] + v[even[j]]))
                add_edge(i + 1, odd.size() + j + 1, 1);

    std::vector<int> layer(e.size()), cur(e.size());

    auto bfs = [&]() -> bool
    {
        std::fill(layer.begin(), layer.end(), 0);
        std::fill(cur.begin(), cur.end(), 0);

        std::queue<int> que;
        que.push(s);
        layer[s] = 1;

        while (not que.empty())
        {
            int u = que.front();
            que.pop();

            for (const auto& i : e[u])
            {
                if (i.w == 0 or layer[i.to])
                    continue;

                layer[i.to] = layer[u] + 1;
                que.push(i.to);
            }
        }
        
        return layer[t];
    };

    std::function<int(int, int)> dfs = [&](int u, int limit) -> int
    {
        if (u == t)
            return limit;

        for (int c = cur[u]; c < e[u].size(); ++c)
        {
            cur[u] = c;

            auto& i = e[u][c];
            
            if (i.w == 0 or layer[i.to] != layer[u] + 1)
                continue;

            if (int flow = dfs(i.to, std::min(i.w, limit)); flow)
            {
                i.w -= flow;
                e[i.to][i.rid].w += flow;

                return flow;
            }
            else
            {
                layer[i.to] = 0;
            }
        }
        
        return 0;
    };

    int maxflow = 0, flow;

    while (bfs())
    {
        while (flow = dfs(s, INT_MAX))
        {
            maxflow += flow;
        }
    }

    if (maxflow != n)
    {
        std::cout << "Impossible";
        return 0;
    }

    std::vector<std::vector<int>> ans;

    std::vector<bool> vis(n + 1);

    std::function<void(int)> go_left, go_right = [&](int u) -> void
        {
            ans.back().push_back(odd[u - 1]);
            vis[u] = true;

            for (const auto& i : e[u])
            {
                if (i.w or i.is_reverse or vis[i.to])
                    continue;

                go_left(i.to);

                break;
            }
        };

    go_left = [&](int u) -> void
        {
            ans.back().push_back(even[u - odd.size() - 1]);
            vis[u] = true;

            for (const auto& i : e[u])
            {
                if (i.w == 0 or i.is_reverse == false or vis[i.to])
                    continue;

                go_right(i.to);
                break;
            }
        };

    for (int i = 0; i < odd.size(); ++i)
    {
        if (vis[i + 1] == false)
        {
            ans.emplace_back();
            go_right(i + 1);
        }
    }

    std::cout << ans.size() << '\n';

    for (const auto& c : ans)
    {
        std::cout << c.size() << ' ';

        for (const auto& i : c)
            std::cout << i + 1 << ' ';

        std::cout << '\n';
    }

    return 0;
}