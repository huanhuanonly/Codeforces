/**
 * AtCoder Beginner Contest 458
 *
 * => D - Chalkboard Median ( @c 400 )
 *
 * -> https://atcoder.jp/contests/abc458/tasks/abc458_d
 *
 * Submissions ~> https://atcoder.jp/contests/abc458/submissions/76009004 By huanhuanonly
 *
 * @b Two-heaps
 *
 * ----May 22, 2026 [21h:56m:21s]----
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

    std::priority_queue<int> lq;
    std::priority_queue<int, std::vector<int>, std::ranges::greater> rq;

    int x;
    std::cin >> x;

    lq.push(x);

    int q;
    std::cin >> q;

    while (q--)
    {
        int a, b;
        std::cin >> a >> b;

        if (a <= lq.top())
        {
            lq.push(a);
        }
        else
        {
            rq.push(a);
        }

        if (b <= lq.top())
        {
            lq.push(b);
        }
        else
        {
            rq.push(b);
        }

        for (; rq.size() > lq.size(); lq.push(rq.top()), rq.pop());
        for (; lq.size() - 1 > rq.size(); rq.push(lq.top()), lq.pop());

        std::cout << lq.top() << '\n';
    }

    return 0;
}