/**
 * Educational Codeforces Round 136 (Rated for Div. 2)
 * 
 * => D. Reset K Edges ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1739/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1739/submission/340907806 By huanhuanonly
 * 
 * @b Binary-search and @b Trees
 * 
 * ----September 28, 2025 [22h:10m:20s]----
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
        int n, k;
        std::cin >> n >> k;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 2; i <= n; ++i)
        {
            int u;
            std::cin >> u;

            e[u].push_back(i);
        }

        auto check = [&](int mid) -> bool
        {
            int cnt = 0;

            auto dfs = [&](const auto& self, int u, int fa) -> int
            {
                int max = 1;

                for (int i : e[u])
                {
                    max = std::max(max, self(self, i, u) + 1);
                }

                if (max >= mid)
                {
                    cnt += fa != 1;
                    return 0;
                }
                else
                {
                    return max;
                }
            };

            for (int i : e[1])
            {
                dfs(dfs, i, 1);
            }

            return cnt <= k;
        };

        int l = 0, r = n - 1, mid;

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

        std::cout << r << '\n';
    }

    return 0;
}