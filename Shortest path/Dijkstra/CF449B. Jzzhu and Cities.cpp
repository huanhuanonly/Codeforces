/**
 * Codeforces Round 257 (Div. 1)
 * 
 * => B. Jzzhu and Cities
 * 
 * -> https://codeforces.com/problemset/problem/449/B (2000)
 * 
 * @b Dijkstra
*/

#include <bits/stdc++.h>

using uint = unsigned int;
using llong = long long int;
using ullong = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int n, m, k;
    std::cin >> n >> m >> k;

    struct node
    {
        llong to, w;

        bool operator<(const node& rv) const
        {
            return this->w > rv.w;
        }
    };

    std::vector<node> e[n + 1];
    for (llong i = 0, u, v, w; i < m; ++i)
    {
        std::cin >> u >> v >> w;
        
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    std::vector<llong> dis(n + 1, LLONG_MAX / 2 - 1);

    auto bfs = [&](node start) -> void
    {
        std::priority_queue<node> que;
        que.push(start);

        std::vector<bool> vis(n + 1);
        dis[start.to] = start.w;

        while (not que.empty())
        {
            auto ct = que.top();
            que.pop();

            if (vis[ct.to])
                continue;
            else
                vis[ct.to] = true;

            for (const auto& [to, w] : e[ct.to])
            {
                if (dis[ct.to] + w < dis[to])
                {
                    dis[to] = dis[ct.to] + w;
                    que.push({to, dis[to]});
                }
            }
        }

        return;
    };

    bfs({1, 0});

    std::vector<std::pair<llong, llong>> st;
    st.reserve(k);

    for (int i = 0; i < k; ++i)
    {
        llong s, w;
        std::cin >> s >> w;

        if (w < dis[s])
            st.push_back(std::make_pair(s, w));
    }

    std::sort(st.begin(), st.end(), [&dis](const std::pair<llong, llong>& lv, const std::pair<llong, llong>& rv) -> bool
    {
        return lv.second < rv.second;
    });

    int cnt = k - static_cast<int>(st.size());
    for (const auto& [s, w] : st)
    {
        if (w < dis[s])
            bfs({s, w});
        else
            ++cnt;
    }

    std::cout << cnt << '\n';
    
    return 0;
}