/**
 * Educational Codeforces Round 95 (Rated for Div. 2)
 * 
 * => C. Mortal Kombat Tower ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/1418/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1418/submission/327268864 By huanhuanonly
 * 
 * @b Dijkstra
 * 
 * ----July 04, 2025 [00h:32m:21s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        auto bfs = [&]() -> int
        {
            std::vector<int> dis(n + 1, std::numeric_limits<int>::max());

            struct item
            {
                int index, count;

                bool operator<(const item& other) const noexcept
                {
                    return count > other.count;
                }
            };

            std::priority_queue<item> que;
            que.push({0, v[0]});
            dis[0] = v[0];

            if (1 < n)
            {
                que.push({1, v[0] + v[1]});
                dis[1] = v[0] + v[1];
            }

            while (not que.empty())
            {
                item cur = que.top();
                que.pop();

                if (cur.count > dis[cur.index])
                {
                    continue;
                }

                for (int i = cur.index + 1; i <= cur.index + 2 and i < n; ++i)
                {
                    int cnt = 0;

                    for (int j = i + 1; j <= i + 2 and j <= n; ++j)
                    {
                        cnt += j < n and v[j];

                        if (cur.count + cnt < dis[j])
                        {
                            que.push({j, cur.count + cnt});
                            dis[j] = cur.count + cnt;
                        }
                    }
                }
            }

            return std::min(dis[n - 1], dis[n]);
        };

        std::cout << bfs() << '\n';
    }

    return 0;
}