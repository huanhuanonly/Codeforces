/**
 * Codeforces Round 1031 (Div. 2)
 * 
 * => C. Smilo and Minecraft ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2113/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2113/submission/324514841 By huanhuanonly
 * 
 * @b 2D-Prefix-sum
 * 
 * ----June 15, 2025 [21h:25m:06s]----
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
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::string> map(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> map[i];
        }

        std::vector<std::vector<int>> pre(n + 1, std::vector<int>(m + 1));

        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] == 'g')
                {
                    pre[i + 1][j + 1] = 1;
                    ++sum;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }

        auto get = [&](int i, int j, int x, int y)
        {
            i = std::clamp(i, 1, n);
            x = std::clamp(x, 1, n);
            j = std::clamp(j, 1, m);
            y = std::clamp(y, 1, m);

            return pre[i][j] - pre[i][y - 1] - pre[x - 1][j] + pre[x - 1][y - 1];
        };

        int min = sum;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] == '.')
                {
                    min = std::min(min, get(i + k, j + k, i - k + 2, j - k + 2));
                }
            }
        }

        std::cout << sum - min << '\n';
    }

    return 0;
}