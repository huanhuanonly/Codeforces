/**
 * Codeforces Round 1043 (Div. 3)
 * 
 * => E. Arithmetics Competition ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2132/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2132/submission/336482025 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----September 01, 2025 [18h:08m:39s]----
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
        int n, m, q;
        std::cin >> n >> m >> q;

        std::vector<uint64> a(n + 1), b(m + 1);

        std::vector<std::pair<uint64, bool>> v(n + m + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            v[i].first = a[i];
        }

        for (int i = 1; i <= m; ++i)
        {
            std::cin >> b[i];
            v[n + i] = {b[i], true};
        }

        std::ranges::sort(a | std::views::drop(1), std::ranges::greater());
        std::ranges::sort(b | std::views::drop(1), std::ranges::greater());
        std::ranges::sort(v | std::views::drop(1), std::ranges::greater());

        std::partial_sum(a.begin(), a.end(), a.begin());
        std::partial_sum(b.begin(), b.end(), b.begin());

        std::vector<std::array<int, 2>> cnt(v.size());

        for (int i = 1; i < v.size(); ++i)
        {
            cnt[i][0] = cnt[i - 1][0] + not v[i].second;
            cnt[i][1] = cnt[i - 1][1] + v[i].second;

            v[i].first += v[i - 1].first;
        }

        while (q--)
        {
            int x, y, z;
            std::cin >> x >> y >> z;

            uint64 sum = v[z].first;

            if (cnt[z][0] > x)
            {
                const uint64 diff = cnt[z][0] - x;

                sum = sum - a[cnt[z][0]] + a[x];
                sum = sum - b[cnt[z][1]] + b[cnt[z][1] + diff];
            }
            else if (cnt[z][1] > y)
            {
                const uint64 diff = cnt[z][1] - y;

                sum = sum - b[cnt[z][1]] + b[y];
                sum = sum - a[cnt[z][0]] + a[cnt[z][0] + diff];
            }

            std::cout << sum << '\n';
        }
    }

    return 0;
}