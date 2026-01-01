/**
 * Forethought Future Cup - Elimination Round
 * 
 * => G. Zoning Restrictions ( @c 2700 )
 * 
 * -> https://codeforces.com/contest/1146/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/1146/submission/346158691 By huanhuanonly
 * 
 * @b Dinic for @a Min-cut ( @a maximum-weight-closure-of-a-graph )
 * 
 * ----October 28, 2025 [20h:10m:13s]----
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

class Dinic
{
public:

    struct edge
    {
        int to, cap, rid;
    };

    std::vector<std::vector<edge>> e;

    const int source, sink;

    explicit Dinic(int n) : e(n + 2), source(n), sink(n + 1), level(n + 2), current(n + 2) { }

    void add_edge(int u, int v, int cap)
    {
        e[u].push_back({v, cap, int(e[v].size())});
        e[v].push_back({u, 0, int(e[u].size()) - 1});
    }

    bool build_level_graph()
    {
        std::ranges::fill(level, 0);
        std::ranges::fill(current, 0);

        std::queue<int> que;

        que.push(source);
        level[source] = 1;

        while (not que.empty())
        {
            const int u = que.front();
            que.pop();

            for (const auto& i : e[u])
            {
                if (i.cap == 0 or level[i.to])
                {
                    continue;
                }

                level[i.to] = level[u] + 1;
                que.push(i.to);
            }
        }

        return level[sink];
    }

    int augment_flow(int u, int flow)
    {
        if (u == sink)
        {
            return flow;
        }

        for (; current[u] < e[u].size(); ++current[u])
        {
            auto& i = e[u][current[u]];

            if (i.cap == 0 or level[i.to] != level[u] + 1)
            {
                continue;
            }

            if (const int f = augment_flow(i.to, std::min(flow, i.cap)))
            {
                i.cap -= f;
                e[i.to][i.rid].cap += f;

                return f;
            }
            else
            {
                level[i.to] = 0;
            }
        }

        return 0;
    }

    int max_flow()
    {
        int sum = 0;

        while (build_level_graph())
        {
            int flow;

            while (flow = augment_flow(source, std::numeric_limits<int>::max()))
            {
                sum += flow;
            }
        }

        return sum;
    }

    int min_cut()
    {
        return max_flow();
    }

private:

    std::vector<int> level;
    std::vector<int> current;
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, h, m;
    std::cin >> n >> h >> m;

    Dinic dinic(n * h + m);

    constexpr auto inf = std::numeric_limits<int>::max();

    auto $ = [&](int i, int j) -> int
    {
        return h * (i - 1) + (j - 1);
    };

    int sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= h; ++j)
        {
            dinic.add_edge(dinic.source, $(i, j), j * j - (j - 1) * (j - 1));
            sum += j * j - (j - 1) * (j - 1);

            if (j > 1) [[likely]]
            {
                dinic.add_edge($(i, j), $(i, j - 1), inf);
            }
        }
    }
    
    for (int i = 1; i <= m; ++i)
    {
        int l, r, x, c;
        std::cin >> l >> r >> x >> c;

        dinic.add_edge($(n, h) + i, dinic.sink, c);

        if (x + 1 <= h)
        {
            for (int pos = l; pos <= r; ++pos)
            {
                dinic.add_edge($(pos, x + 1), $(n, h) + i, inf);
            }
        }
    }

    std::cout << sum - dinic.min_cut();

    return 0;
}