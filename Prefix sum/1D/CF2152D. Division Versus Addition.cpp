/**
 * Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2)
 * 
 * => D. Division Versus Addition ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2152/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2152/submission/341719232 By huanhuanonly
 * 
 * @b Prefix-sum and @b Game-theory
 * 
 * ----October 04, 2025 [09h:48m:50s]----
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

constexpr int64 lowbit(int64 x)
{
    return x & -x;
}

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
        int64 n, q;
        std::cin >> n >> q;

        std::vector<int64> v(n + 1);

        struct item
        {
            int64 s;
            int64 c;
        };

        auto get = [](int64 x) -> int64
        {
            int64 cnt = 0;

            while (true)
            {
                x /= 2;
                ++cnt;

                if (x >= 2)
                {
                    ++x;
                }
                else
                {
                    break;
                }
            }

            return cnt;
        };

        std::vector<item> cnt(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];

            cnt[i].c = get(v[i]);
            cnt[i].s = (get(v[i] + 1) > get(v[i]));

            cnt[i].s += cnt[i - 1].s;
            cnt[i].c += cnt[i - 1].c;
        }

        while (q--)
        {
            int64 l, r;
            std::cin >> l >> r;

            int64 s = cnt[r].s - cnt[l - 1].s;
            int64 c = cnt[r].c - cnt[l - 1].c;

            std::cout << c + s / 2 << '\n';
        }
    }

    return 0;
}