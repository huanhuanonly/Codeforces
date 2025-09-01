/**
 * Codeforces Round 236 (Div. 2)
 * 
 * => C. Searching for Graph ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/402/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/402/submission/325052676 By huanhuanonly
 * 
 * @b Constructive-algorithms
 * 
 * ----June 19, 2025 [00h:16m:54s]----
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
        int n, p;
        std::cin >> n >> p;

        std::vector<std::vector<int>> e(n);

        for (int i = 0; i < n; ++i)
        {
            e[i].push_back((i + 1) % n);
            e[i].push_back((i + 2) % n);
        }

        for (int i = 0; p; ++i)
        {
            if (int nt = (i % n + e[i % n].size() + 1) % n; not std::ranges::binary_search(e[nt], i))
            {
                e[i % n].push_back(nt);
                --p;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < e[i].size(); ++j)
            {
                std::cout << i + 1 << ' ' << e[i][j] + 1 << '\n';
            }
        }
    }

    return 0;
}