/**
 * Codeforces Round 149 (Div. 2)
 * 
 * => C. King's Path ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/242/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/242/submission/351933220 By huanhuanonly
 * 
 * @b Breadth-first-search
 * 
 * ----December 05, 2025 [08h:42m:42s]----
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

    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    int n;
    std::cin >> n;

    std::map<int, std::set<std::pair<int, int>>> mp;

    for (int i = 0; i < n; ++i)
    {
        int r, a, b;
        std::cin >> r >> a >> b;

        auto& t = mp[r];

        auto it = t.lower_bound({a, b});

        if (it != t.end() and it->first <= b + 1)
        {
            auto nd = t.extract(it);
            
            nd.value().first = std::min(nd.value().first, a);
            nd.value().second = std::max(nd.value().second, b);

            t.insert(std::move(nd));
        }
        else
        {
            t.insert(it, {a, b});
        }
    }

    constexpr auto inf = std::numeric_limits<int>::max() / 2;

    auto check = [&](int x, int y) -> bool
    {
        if (auto it = mp[x].upper_bound({y, inf}); not mp[x].empty())
        {
            --it;

            if (it->first <= y and y <= it->second)
            {
                return true;
            }
        }

        return false;
    };

    std::map<std::pair<int, int>, int> dis;
    dis[{sx, sy}] = 0;

    int ans = inf;

    using item = std::pair<int, std::pair<int, int>>;

    std::priority_queue<item, std::vector<item>, std::ranges::greater> que;
    que.push({0, {sx, sy}});

    std::set<std::pair<int, int>> vis;

    while (not que.empty())
    {
        auto cur = que.top().second;
        que.pop();

        auto [l, r] = *std::prev(mp[cur.first].upper_bound({cur.second, inf}));

        if (cur.first == tx and l <= ty and ty <= r)
        {
            ans = std::min(ans, dis[cur] + std::abs(cur.second - ty));
            continue;
        }

        if (vis.contains(cur))
        {
            continue;
        }

        vis.insert(cur);

        constexpr std::pair<int, int> d[]{
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
            {1, -1}, {-1, 1}, {1, 1}, {-1, -1}
        };
        
        for (const auto& [dx, dy] : d)
        {
            const int nx = cur.first + dx, ny = cur.second + dy;

            if (not check(nx, ny))
            {
                continue;
            }

            auto fit = dis.find({nx, ny});
    
            if (fit == dis.end())
            {
                fit = dis.insert({{nx, ny}, inf}).first;
            }

            if (const int ndis = dis[cur] + 1; ndis < fit->second)
            {
                fit->second = ndis;
                que.push({ndis, {nx, ny}});
            }
        }
    }

    if (ans == inf)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ans;
    }

    return 0;
}