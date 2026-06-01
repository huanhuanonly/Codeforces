/**
 * Codeforces Round 1090 (Div. 4)
 *
 * => G. The 67th Iteration of "Counting is Fun" ( @c 1800 )
 *
 * -> https://codeforces.com/contest/2218/problem/G
 *
 * Submissions ~> https://codeforces.com/contest/2218/submission/370213365 By huanhuanonly
 *
 * @b Combinatorics
 *
 * ----April 08, 2026 [09h:31m:05s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> v(n);
        std::vector<std::vector<int>> pos(m);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
            pos[v[i]].push_back(i);
        }

        constexpr uint64 mod = 676767677;

        std::vector<bool> vis(n);

        for (const auto& i : pos[0])
        {
            vis[i] = true;
        }

        int cnt = pos[0].size();

        uint64 sum = 1;

        for (int i = 1; i < m; ++i)
        {
            for (const auto& j : pos[i])
            {
                int mark = 0;
                bool limit = false;

                if (j - 1 >= 0 and vis[j - 1])
                {
                    mark = 1;

                    if (v[j - 1] < v[j] - 1)
                    {
                        limit = true;
                    }
                }

                if (j + 1 < n and vis[j + 1])
                {
                    mark |= 2;

                    if (v[j + 1] < v[j] - 1)
                    {
                        limit = true;
                    }
                }

                if (not mark)
                {
                    sum = 0;
                    break;
                }

                if (limit)
                {
                    (sum *= pos[i - 1].size()) %= mod;
                }
                else
                {
                    (sum *= cnt) %= mod;
                }
            }

            if (sum == 0)
            {
                break;
            }

            for (const auto& j : pos[i])
            {
                vis[j] = true;
            }

            cnt += pos[i].size();
        }

        std::cout << sum << '\n';
    }

    return 0;
}