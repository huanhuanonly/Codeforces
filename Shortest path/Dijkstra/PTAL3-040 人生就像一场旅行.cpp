/**
 * 2025 CCCC GPLT 团体程序设计天梯赛
 * 
 * => L3-040 人生就像一场旅行 ( @c 30 )
 * 
 * -> https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1913922872972247052&page=2
 * 
 * Submissions ~> https://pintia.cn/problem-sets/994805046380707840/exam/submissions/1914975755245998080 By huanhuanonly
 * 
 * @b Dijkstra
 * 
 * ----April 23, 2025 [17h:53m:15s]----
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

    int b, n, m, q;
    std::cin >> b >> n >> m >> q;

    struct edge
    {
        int to, w, pow;

        bool operator<(const edge& other) const
        {
            if (w != other.w)
                return w > other.w;
            else
                return pow < other.pow;
        }
    };

    std::vector<std::vector<edge>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w, pow;
        std::cin >> u >> v >> w >> pow;

        e[u].push_back({v, w, pow});
        e[v].push_back({u, w, pow});
    }

    constexpr int inf = std::numeric_limits<int>::max() / 2;

    std::vector<int>  dis(n + 1, inf);
    std::vector<int>  pow(n + 1);
    std::vector<bool> vis(n + 1);

    auto bfs = [&](int start) -> void
    {
        std::fill(dis.begin(), dis.end(), inf);
        std::fill(pow.begin(), pow.end(), 0);
        std::fill(vis.begin(), vis.end(), false);

        std::priority_queue<edge> que;
        que.push({start, 0, 0});
        dis[start] = 0;
        
        while (not que.empty())
        {
            auto cur = que.top();
            que.pop();

            if (vis[cur.to])
                continue;
            else
                vis[cur.to] = true;

            for (const auto& i : e[cur.to])
            {
                if (int ndis = dis[cur.to] + i.w; ndis < dis[i.to])
                {
                    dis[i.to] = ndis;
                    pow[i.to] = pow[cur.to] + i.pow;

                    que.push({i.to, ndis, pow[i.to]});
                }
                else if (ndis == dis[i.to])
                {
                    pow[i.to] = std::max(pow[i.to], pow[cur.to] + i.pow);
                }
            }
        }
    };

    while (q--)
    {
        int start;
        std::cin >> start;

        bfs(start);

        std::vector<int> ans;

        for (int i = 1; i <= n; ++i)
        {
            if (i != start and dis[i] <= b)
            {
                ans.push_back(i);
            }
        }

        if (ans.empty())
        {
            std::cout << "T_T\n";
            continue;
        }

        for (int i = 0; i < ans.size(); ++i)
        {
            std::cout << ans[i] << " \n"[i + 1 == ans.size()];
        }

        int max = pow[*std::max_element(ans.begin(), ans.end(), [&](int lv, int rv) -> bool {
            return pow[lv] < pow[rv];
        })];

        auto range = ans | std::views::filter([&](int value) -> bool { return pow[value] == max; });

        for (auto it = range.begin(); it != range.end(); )
        {
            std::cout << *it << " \n"[++it == range.end()];
        }
    }

    return 0;
}