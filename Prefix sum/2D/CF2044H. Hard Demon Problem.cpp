/**
 * Codeforces Round 993 (Div. 4)
 * 
 * => H. Hard Demon Problem ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2044/problem/H
 * 
 * Submissions ~> https://codeforces.com/contest/2044/submission/315801137 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----April 16, 2025 [16h:07m:38s]----
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
        uint64 n, q;
        std::cin >> n >> q;

        /**
         * x1 x1 x1
         * x1 x1 x1
         * x1 x1 x1
         */
        std::vector<std::vector<uint64>> sum_prefix(n + 1, std::vector<uint64>(n + 1));

        /**
         * x1 x2 x3
         * x1 x2 x3
         * x1 x2 x3
         */
        std::vector<std::vector<uint64>> row_prefix(n + 1, std::vector<uint64>(n + 1));

        /**
         * x0 x0 x0
         * x1 x1 x1
         * x2 x2 x2
         */
        std::vector<std::vector<uint64>> col_prefix(n + 1, std::vector<uint64>(n + 1));

        for (uint64 i = 1; i <= n; ++i)
        {
            for (uint64 j = 1; j <= n; ++j)
            {
                std::cin >> sum_prefix[i][j];

                col_prefix[i][j] = col_prefix[i - 1][j] + col_prefix[i][j - 1] - col_prefix[i - 1][j - 1] + sum_prefix[i][j] * (i - 1);
                row_prefix[i][j] = row_prefix[i - 1][j] + row_prefix[i][j - 1] - row_prefix[i - 1][j - 1] + sum_prefix[i][j] * j;
                
                sum_prefix[i][j] += sum_prefix[i - 1][j] + sum_prefix[i][j - 1] - sum_prefix[i - 1][j - 1];
            }
        }

        while (q--)
        {
            uint64 x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;

            /**
             * x1 x2 x3     x0 x0 x0           x1 x2 x3
             * x1 x2 x3  +  x1 x1 x1  *  3  =  x4 x5 x6
             * x1 x2 x3     x2 x2 x2           x7 x8 x9
             */

            uint64 sum = 0;

            uint64 sum_sum = sum_prefix[x2][y2] - sum_prefix[x1 - 1][y2] - sum_prefix[x2][y1 - 1] + sum_prefix[x1 - 1][y1 - 1];
            uint64 sum_row = row_prefix[x2][y2] - row_prefix[x1 - 1][y2] - row_prefix[x2][y1 - 1] + row_prefix[x1 - 1][y1 - 1];
            uint64 sum_col = col_prefix[x2][y2] - col_prefix[x1 - 1][y2] - col_prefix[x2][y1 - 1] + col_prefix[x1 - 1][y1 - 1];

            sum += sum_row - sum_sum * (y1 - 1);

            sum += (sum_col - sum_sum * (x1 - 1)) * (y2 - y1 + 1);

            std::cout << sum << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}