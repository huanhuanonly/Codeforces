/**
 * CROC 2016 - Elimination Round
 * 
 * => D. Robot Rapping Results Report ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/645/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/645/submission/341943033 By huanhuanonly
 * 
 * @b Dfs on @a Graphs and @b Binary-search
 * 
 * ----October 05, 2025 [13h:11m:05s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> v(m + 1);
    std::vector<int> indegree(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
        ++indegree[v[i].second];
    }
    
    const int start = std::ranges::find(indegree | std::views::drop(1), 0) - indegree.begin();
    
    std::vector<std::vector<int>> e(n + 1);
    int lastmid = 0;

    std::vector<bool> vis(n + 1);
    std::vector<int>  cnt(n + 1, 1);
    
    auto check = [&](int mid) -> bool
    {
        for (int& i = lastmid; i < mid; ++i)
        {
            e[v[i + 1].first].push_back(v[i + 1].second);
        }

        for (int& i = lastmid; i > mid; --i)
        {
            e[v[i].first].pop_back();
        }
        
        auto dfs = [&](const auto& self, int u, int d) -> bool
        {
            if (vis[u])
            {
                return false;
            }

            if (d + cnt[u] == n)
            {
                return true;
            }
            else if (cnt[u] > 1)
            {
                return false;
            }

            vis[u] = true;

            for (int i : e[u])
            {
                if (self(self, i, d + 1))
                {
                    vis[u] = false;
                    return true;
                }

                cnt[u] = std::max(cnt[u], cnt[i] + 1);
            }

            vis[u] = false;
            return false;
        };

        std::ranges::fill(cnt, 1);
        
        return dfs(dfs, start, 0);
    };

    int l = n - 2, r = m + 1, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    if (r <= m)
    {
        std::cout << r;
    }
    else
    {
        std::cout << -1;
    }

    return 0;
}