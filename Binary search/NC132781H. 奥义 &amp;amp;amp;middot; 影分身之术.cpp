/**
 * 哈尔滨华德学院第十七届程序设计竞赛（同步赛）
 *
 * => H-奥义 &amp;amp;amp;middot; 影分身之术
 *
 * -> https://ac.nowcoder.com/acm/contest/132781/H
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83575409 By huanhuanonly
 *
 * @b Binary-search on @a Trees
 *
 * ----May 12, 2026 [19h:26m:44s]----
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

    uint64 k, n, m;
    std::cin >> k >> n >> m;

    n = std::min(n, uint64(64));

    auto dfs = [&](const auto& self, uint64 num) -> uint64
    {
        if (n == 0)
        {
            return num;
        }

        --n;

        const uint64 ls = 1ULL << n;

        if (m <= ls)
        {
            return self(self, num);
        }
        else
        {
            m -= ls;
            return self(self, (num + 1) % (k + 1));
        }
    };

    --n;
    std::cout << dfs(dfs, 0) << '\n';

    return 0;
}