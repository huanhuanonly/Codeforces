/**
 * Codeforces Round 993 (Div. 4)
 * 
 * => G2. Medium Demon Problem (hard version) ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2044/problem/G2
 * 
 * Submissions ~> https://codeforces.com/contest/2044/submission/315710603 By huanhuanonly
 * 
 * @b Topological-sorting with @b DP
 * 
 * ----April 15, 2025 [21h:31m:50s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n + 1);

        std::vector<int> in_degree(n + 1);

        for (int i = 1; i<= n; ++i)
        {
            std::cin >> v[i];

            ++in_degree[v[i]];
        }

        std::vector<int> cnt(n + 1, 1);

        std::queue<int> que;

        for (const auto& i : std::views::iota(1, n + 1)
                           | std::views::filter([&in_degree](int i) -> bool { return not in_degree[i]; }))
        {
            que.push(i);
        }
        
        auto in_degree_temp = in_degree;
        
        std::vector<bool> vis(n + 1, true);
        
        while (not que.empty())
        {
            int u = que.front();
            que.pop();

            vis[u] = false;

            if (--in_degree_temp[v[u]] == 0)
            {
                que.push(v[u]);
            }
        }
        
        for (const auto& i : std::views::iota(1, n + 1)
                           | std::views::filter([&in_degree](int i) -> bool { return not in_degree[i]; }))
        {
            que.push(i);
        }

        while (not que.empty())
        {
            int u = que.front();
            que.pop();

            if (vis[v[u]])
                cnt[v[u]] = std::max(cnt[v[u]], cnt[u] + 1);
            else
                cnt[v[u]] += cnt[u];

            if (--in_degree[v[u]] == 0)
            {
                que.push(v[u]);
            }
        }

        std::cout << *std::ranges::max_element(cnt | std::views::drop(1)) + 1 << '\n';
    }

    return 0;
}