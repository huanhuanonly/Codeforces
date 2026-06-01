/**
 * Polaris.AI Programming Contest 2026（AtCoder Beginner Contest 457）
 *
 * => G - Catch All Apples ( @c 625 )
 *
 * -> https://atcoder.jp/contests/abc457/tasks/abc457_g
 *
 * Submissions ~> https://atcoder.jp/contests/abc457/submissions/75715845 By huanhuanonly
 *
 * @b Partially-ordered-set
 * @b Dilworth-theorem
 * @b Binary-search
 *
 * ----May 11, 2026 [10h:58m:10s]----
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

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> v(n);

    for (int i = 0, t, x; i < n; ++i)
    {
        std::cin >> t >> x;
        v[i] = {t + x, t - x};
    }

    std::ranges::sort(v);

    std::vector<int> s;

    for (const auto& i : v | std::views::values | std::views::transform(std::negate{}))
    {
        if (auto it = std::ranges::lower_bound(s, i); it != s.end())
        {
            *it = i;
        }
        else
        {
            s.push_back(i);
        }
    }

    std::cout << s.size() << '\n';

    return 0;
}