/**
 * Educational Codeforces Round 171 (Rated for Div. 2)
 * 
 * => D. Sums of Segments ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2026/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2026/submission/291417647 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----November 14, 2024 [19h:09m:48s]----
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

    uint32 n;
    std::cin >> n;

    std::vector<int64> v(n + 1), s(n + 1);
    std::vector<int64> valuePresum(n + 1);

    int64 sum = 0;

    for (int32 i = 1; i <= n; ++i)
    {
        std::cin >> v[i];

        sum += v[i] * (n - i + 1);

        s[i] = s[i - 1] + v[i];
        valuePresum[i] = s[i];
    }

    for (uint32 i = 1; i <= n; ++i)
    {
        valuePresum[i] += valuePresum[i - 1];
    }

    std::vector<int64> blockPresum(n + 1);
    std::vector<int64> pos(n + 1);

    for (int64 i = 1, cursum = 0; i <= n; cursum += v[i] * (n - i + 1), ++i)
    {
        blockPresum[i] = blockPresum[i - 1] + (sum - cursum);
        pos[i] = pos[i - 1] + (n - i + 1);
    }

    uint32 q;
    std::cin >> q;

    while (q--)
    {
        int64 l, r;
        std::cin >> l >> r;

        int64 lgroup = std::lower_bound(pos.begin() + 1, pos.end(), l) - pos.begin();
        int64 rgroup = std::lower_bound(pos.begin() + 1, pos.end(), r) - pos.begin();

        int64 lpos = l - pos[lgroup - 1] + (lgroup - 1);
        int64 rpos = r - pos[rgroup - 1] + (rgroup - 1);

        int64 ans = 0;

        if (lgroup == rgroup)
        {
            ans = valuePresum[rpos] - valuePresum[lpos - 1] - s[lgroup - 1] * (rpos - lpos + 1);
        }
        else
        {
            ans = (valuePresum[n] - valuePresum[lpos - 1] - s[lgroup - 1] * (n - lpos + 1)) + (valuePresum[rpos] - valuePresum[rgroup - 1] - s[rgroup - 1] * (rpos - rgroup + 1)) + (blockPresum[rgroup - 1] - blockPresum[lgroup]);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
