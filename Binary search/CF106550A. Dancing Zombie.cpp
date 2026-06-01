/**
 * The 2026 Jiangsu Collegiate Programming Contest, The 2026 Guangdong Provincial Collegiate Programming Contest
 *
 * => A. Dancing Zombie
 *
 * -> https://codeforces.com/gym/106550/problem/A
 *
 * Submissions ~> https://codeforces.com/gym/106550/submission/376413659 By huanhuanonly
 *
 * @b Binary-search
 *
 * ----May 28, 2026 [21h:42m:42s]----
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

constexpr void chmin(auto& lhs, const auto& rhs)
{
    if (rhs < lhs)
    {
        lhs = rhs;
    }
}

constexpr void chmax(auto& lhs, const auto& rhs)
{
    if (lhs < rhs)
    {
        lhs = rhs;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int64 n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int64, int64>> v(n);

    for (auto& [pos, time] : v)
    {
        std::cin >> time >> pos;
    }

    std::ranges::sort(v);

    auto check = [&](int64 mid) -> bool
    {
        std::stack<std::pair<int64, int64>> st;

        for (const auto& [pos, time] : v)
        {
            if (time <= mid)
            {
                std::pair<int64, int64> cur{pos - (mid - time), pos + (mid - time)};
                for (; not st.empty() and cur.first - 1 <= st.top().second; chmin(cur.first, st.top().first), chmax(cur.second, st.top().second), st.pop());
                st.push(cur);
            }
        }

        return st.size() == 1 and st.top().first <= 0 and st.top().second >= k;
    };

    int64 l = -1, r = 1e18, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    std::cout << r << '\n';

    return 0;
}