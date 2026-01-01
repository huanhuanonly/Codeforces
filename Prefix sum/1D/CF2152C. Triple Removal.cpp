/**
 * Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2)
 * 
 * => C. Triple Removal ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2152/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2152/submission/341693504 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----October 04, 2025 [09h:47m:33s]----
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
        int n, q;
        std::cin >> n >> q;

        std::vector<int> v(n + 1, -1);
        std::vector<int> pre(n + 1);

        std::vector<int> log;
        log.reserve(n);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            pre[i] = pre[i - 1] + v[i];

            if (v[i] == v[i - 1])
            {
                log.push_back(i - 1);
            }
        }

        while (q--)
        {
            int l, r;
            std::cin >> l >> r;

            if ((pre[r] - pre[l - 1]) % 3 or ((r - l + 1) - (pre[r] - pre[l - 1])) % 3)
            {
                std::cout << -1 << '\n';
            }
            else
            {
                auto it = std::ranges::lower_bound(log, l);

                std::cout << (r - l + 1) / 3 + (it == log.end() or *it >= r) << '\n';
            }
        }
    }

    return 0;
}