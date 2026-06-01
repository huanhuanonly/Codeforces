/**
 * 2025 National Invitational of CCPC (Fujian), The 12th Fujian Collegiate Programming Contest
 * 
 * => G. 炒股高手
 * 
 * -> https://codeforces.com/gym/105977/problem/G
 * 
 * Submissions ~> https://codeforces.com/gym/105977/submission/372705164 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----April 28, 2026 [20h:39m:45s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<int64> v(n + 2);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    v.back() = -1;

    std::vector<int> next(n + 2), prev(n + 2);

    for (int i = 1; i <= n; ++i)
    {
        int r = i;
        for (; r <= n and v[r] <= v[r + 1]; ++r);

        for (int j = i; j <= r; ++j)
        {
            next[j] = r;
            prev[j] = i;
        }

        i = r;
    }

    std::vector<int64> pre(n + 1);

    for (int i = 1; i <= n; i = next[i] + 1)
    {
        pre[i] = pre[i - 1] + (v[next[i]] - v[i]);

        for (int j = i + 1; j <= next[i]; ++j)
        {
            pre[j] = pre[j - 1];
        }
    }

    int64 k;
    std::cin >> k;

    while (m--)
    {
        int l, r;
        std::cin >> l >> r;

        int64 sum = k;

        sum += v[std::min(next[l], r)] - v[l];
        l = next[l] + 1;

        if (l <= r)
        {
            sum += v[r] - v[std::max(prev[r], l)];
            r = prev[r] - 1;
        }

        if (l <= r)
        {
            sum += pre[r] - pre[l - 1];
        }

        std::cout << sum << '\n';
    }

    return 0;
}