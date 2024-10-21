/**
 * Educational Codeforces Round 21
 * 
 * => F. Card Game
 * 
 * -> https://codeforces.com/problemset/problem/808/F (2400)
 * 
 * @b Dinic for @a Min-Cut on @a binary_search
*/

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

    int n, k;
    std::cin >> n >> k;

    struct Data
    {
        int p, c, l;
    };

    std::vector<Data> data(n + 1);

    for (int i = 1; i <= n; ++i)
        std::cin >> data[i].p >> data[i].c >> data[i].l;

    struct edge
    {
        int to, cap, rid;
    };

    std::vector<std::vector<edge>> e(n + n + 2 + 1);

    int s = e.size() - 1, t = s - 1;

    constexpr int inf = INT_MAX / 2;

    auto add_edge = [&](int u, int v, int cap) -> void
    {
        e[u].push_back({v, cap, int(e[v].size())});
        e[v].push_back({u, 0, int(e[u].size() - 1)});
    };

    auto check = [&](int mid) -> bool
    {
        for (auto& i : e)
            i.clear();

        int sum = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (data[i].l > mid)
                continue;

            add_edge(s, i, data[i].p);
            add_edge(n + i, t, data[i].p);

            sum += data[i].p;

            for (int j = 1; j <= n; ++j)
            {
                if (i != j and data[j].l <= mid and is_prime(data[i].c + data[j].c))
                {
                    add_edge(i, n + j, inf);
                }
            }
        }

        std::vector<int> dis(e.size()), cur(e.size());
        
        auto bfs = [&]() -> bool
        {
            std::fill(dis.begin(), dis.end(), 0);
            std::fill(cur.begin(), cur.end(), 0);

            std::queue<int> que;
            que.push(s);
            dis[s] = 1;

            while (not que.empty())
            {
                int u = que.front();
                que.pop();

                for (const auto& i : e[u])
                {
                    if (i.cap == 0 or dis[i.to])
                        continue;

                    dis[i.to] = dis[u] + 1;
                    que.push(i.to);
                }
            }

            return dis[t];
        };

        std::function<int(int, int)> dfs = [&](int u, int limit) -> int
        {
            if (u == t)
                return limit;

            for (int c = cur[u]; c < e[u].size(); ++c)
            {
                cur[u] = c;
                auto& i = e[u][c];

                if (i.cap == 0 or dis[i.to] != dis[u] + 1)
                    continue;

                if (int flow = dfs(i.to, std::min(i.cap, limit)); flow)
                {
                    i.cap -= flow;
                    e[i.to][i.rid].cap += flow;
                    return flow;
                }
                else
                {
                    dis[i.to] = 0;
                }
            }

            return 0;
        };

        int maxflow = 0, flow;

        while (bfs())
        {
            while (flow = dfs(s, inf))
            {
                maxflow += flow;
            }
        }

        return sum - maxflow / 2 >= k;
    };

    int l = 0, r = n + 1, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    std::cout << (r != n + 1 ? r : -1);

    return 0;
}