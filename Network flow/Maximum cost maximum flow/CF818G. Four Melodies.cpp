/**
 * Educational Codeforces Round 24
 * 
 * => G. Four Melodies ( @c 2600 )
 * 
 * -> https://codeforces.com/contest/818/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/818/submission/346999971 By huanhuanonly
 * 
 * @b SPFA-Dinic for @a Maximum-cost-maximum-flow
 * 
 * ----November 02, 2025 [01h:20m:33s]----
*/

/// @brief This is an @c interesting problem!

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
        int to;
        int cap;
        int cost;
        int rid;
    };

    std::vector<std::vector<edge>> e;

    const int source, sink;

    static constexpr int inf = std::numeric_limits<int>::max() / 3;

    explicit Dinic(int n)
        : e(n + 2), source(n), sink(n + 1), level(n + 2), current(n + 2), vis(n + 2)
    { }

    void add_edge(int u, int v, int cap, int cost)
    {
        e[u].emplace_back(v, cap, cost, e[v].size());
        e[v].emplace_back(u, 0, -cost, e[u].size() - 1);
    }

    bool build_level_graph()
    {
        std::ranges::fill(level, -inf);
        std::ranges::fill(current, 0);

        vis.assign(vis.size(), false);
        
        struct item
        {
            int point, level;
        };

        std::queue<item> que;

        que.emplace(source, 0);
        level[source] = 0;

        while (not que.empty())
        {
            const auto cur = que.front();
            que.pop();

            vis[cur.point] = false;
            
            for (const auto& i : e[cur.point])
            {
                if (i.cap == 0)
                {
                    continue;
                }

                if (level[cur.point] + i.cost > level[i.to])
                {
                    level[i.to] = level[cur.point] + i.cost;

                    if (not vis[i.to])
                    {
                        vis[i.to] = true;
                        que.emplace(i.to, level[i.to]);
                    }
                }
            }
        }

        return level[sink] != -inf;
    }

    int augment_flow(int u, int limit, int& cost)
    {
        if (u == sink)
        {
            return limit;
        }

        while (current[u] < e[u].size())
        {
            auto& i = e[u][current[u]++];
            
            if (i.cap == 0 or vis[i.to] or level[u] + i.cost != level[i.to])
            {
                continue;
            }

            vis[u] = true;

            if (const int flow = augment_flow(i.to, std::min(limit, i.cap), cost))
            {
                i.cap -= flow;
                e[i.to][i.rid].cap += flow;

                cost += i.cost * flow;

                return flow;
            }
        }

        return 0;
    }

    int max_flow(int* cost = nullptr)
    {
        int sum = 0, c = 0;

        while (build_level_graph())
        {
            int flow;
            
            while (flow = augment_flow(source, inf, c))
            {
                vis.assign(vis.size(), false);
                sum += flow;
            }
        }

        if (cost)
        {
            *cost = c;
        }

        return sum;
    }

private:

    std::vector<int> level;
    std::vector<int> current;
    std::vector<bool> vis;
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<int> v(n);

    std::array<std::vector<int>, 7> pos;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        pos[v[i] % 7].push_back(i);
    }

    const int N = n * 4 + 1;

    Dinic dinic(N);

    const int sub_source = N - 1;

    dinic.add_edge(dinic.source, sub_source, 4, 0);

    auto in        = [&](int u) -> int { return n * 0 + u; };
    auto out       = [&](int u) -> int { return n * 1 + u; };

    // v[i] % 7 == v[j] % 7
    auto transfer1 = [&](int u) -> int { return n * 2 + u; };

    // v[i] == v[j]
    auto transfer2 = [&](int u) -> int { return n * 3 + u; };

    for (int i = 0; i < n; ++i)
    {
        dinic.add_edge(transfer1(i), in(i), dinic.inf, 0);
        dinic.add_edge(transfer2(i), in(i), dinic.inf, 0);

        dinic.add_edge(in(i), out(i), 1, 1);
    }

    for (int i = 0; i < n; ++i)
    {
        dinic.add_edge(sub_source, in(i), dinic.inf, 0);
        dinic.add_edge(out(i), dinic.sink, dinic.inf, 0);
    }

    for (const auto& set : pos)
    {
        for (int i = 0; i < int(set.size()) - 1; ++i)
        {
            dinic.add_edge(out(set[i]), transfer1(set[i + 1]), dinic.inf, 0);
            dinic.add_edge(transfer1(set[i]), transfer1(set[i + 1]), dinic.inf, 0);
        }
    }

    std::map<int, int> mp;

    for (int i = n - 1; i >= 0; --i)
    {
        if (auto it = mp.find(v[i] - 1); it != mp.end())
        {
            dinic.add_edge(out(i), transfer2(it->second), dinic.inf, 0);
        }
        
        if (auto it = mp.find(v[i] + 1); it != mp.end())
        {
            dinic.add_edge(out(i), transfer2(it->second), dinic.inf, 0);
        }

        if (auto it = mp.find(v[i]); it != mp.end())
        {
            dinic.add_edge(transfer2(i), transfer2(it->second), dinic.inf, 0);
        }

        mp[v[i]] = i;
    }

    int cost;
    const int flow = dinic.max_flow(&cost);

    assert(flow == 4);

    std::cout << cost << '\n';
    
    return 0;
}