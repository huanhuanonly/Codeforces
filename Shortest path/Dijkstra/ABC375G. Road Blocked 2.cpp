/**
 * Panasonic Programming Contest 2024（AtCoder Beginner Contest 375）
 * 
 * => G - Road Blocked 2 ( @c 575 )
 * 
 * -> https://atcoder.jp/contests/abc375/tasks/abc375_g
 * 
 * Submissions ~> https://atcoder.jp/contests/abc375/submissions/59324087 By huanhuanonly
 * 
 * @b Dijkstra ( @a Find-meeting-point )
 * 
 * ----November 01, 2024 [20h:22m:18s]----
*/

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    uint32 n, m;
    std::cin >> n >> m;

    std::vector<std::tuple<uint32, uint32, uint64>> es(m + 1);

    std::vector<std::vector<std::pair<uint32, uint64>>> e(n + 1);

    for (auto& [u, v, w] : es | std::views::drop(1))
    {
        std::cin >> u >> v >> w;

        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    constexpr uint64 inf = std::numeric_limits<decltype(inf)>::max() / 2;

    std::vector<uint64> dis(n + 1, inf);
    std::vector<uint32> vis(n + 1);
    std::vector<std::vector<uint32>> from(n + 1);

    auto bfs = [&]() -> void
    {
        struct Item
        {
            uint32 point;
            uint64 w;

            bool operator<(const Item& __it) const
            {
                return this->w > __it.w;
            }
        };

        std::priority_queue<Item> que;

        que.push({1, 0});
        dis[1] = 0;

        while (not que.empty())
        {
            auto cur = que.top();
            que.pop();

            if (vis[cur.point])
                continue;
            else
                vis[cur.point] = true;

            for (const auto& [to, w] : e[cur.point])
            {
                if (dis[cur.point] + w < dis[to])
                {
                    from[to].clear();
                    from[to].push_back(cur.point);

                    dis[to] = dis[cur.point] + w;
                    que.push({to, dis[to]});
                }
                else if (dis[cur.point] + w == dis[to])
                {
                    from[to].push_back(cur.point);
                }
            }
        }
    };

    bfs();

    vis.assign(n + 1, false);
    vis[1] = true;
    
    std::vector<uint32> mp(n + 1);

    auto dfs = [&](auto& self, uint32 point) -> uint32
    {
        uint32 res = mp[point];

        for (const auto& i : from[point])
        {
            if (vis[i])
            {
                res = std::max(res, mp[i]);
                continue;
            }
            
            vis[i] = true;
            res = std::max(res, self(self, i));
        }

        return res;
    };

    std::vector<uint32> str;
    str.reserve(n);

    for (uint32 cur = n; cur != 1; cur = from[cur].front())
    {
        mp[cur] = str.size();
        str.push_back(cur);
        vis[cur] = true;
    }

    mp[1] = str.size();

    std::unordered_set<std::pair<uint32, uint32>, decltype(
        [](const std::pair<uint32, uint32>& value) -> uint64 {
            return (static_cast<uint64>(value.first) << 32) | value.second;
        })> st;

    for (uint32 i = 0; i < str.size(); )
    {
        if (from[str[i]].size() > 1)
        {
            i = dfs(dfs, str[i]);
        }
        else
        {
            st.insert(std::minmax(str[i], from[str[i]].front()));
            ++i;
        }
    }
    
    for (const auto& [u, v, w] : es | std::views::drop(1))
    {
        if (st.contains(std::minmax(u, v)))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    return 0;
}