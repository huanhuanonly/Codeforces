/**
 * Codeforces Round 457 (Div. 2)
 * 
 * => C. Jamie and Interesting Graph ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/916/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/916/submission/341132668 By huanhuanonly
 * 
 * @b Constructive and @b Graphs
 * 
 * ----September 30, 2025 [11h:10m:14s]----
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

    int n, m;
    std::cin >> n >> m;

    struct edge
    {
        int from, to, w;

        bool operator<(const edge& other) const noexcept
        {
            return std::minmax(from, to) < std::minmax(other.from, other.to);
        }
    };

    std::set<edge> e;
    
    constexpr int p1 = 1000003, p2 = 10000019;

    e.insert({1, n, p1});

    if (n > 2)
    {
        e.insert({2, n, p2 - (p1 + (n - 3))});
    }

    for (int i = 3; i <= n - 1; ++i)
    {
        e.insert({i, n, 1});
    }

    for (int i = 1; i <= n and e.size() != m; ++i)
    {
        for (int j = i + 1; j <= n and e.size() != m; ++j)
        {
            e.insert({i, j, int(1e9)}); 
        }
    }

    if (n == 2)
    {
        std::cout << p1 << ' ' << p1 << '\n';
    }
    else
    {
        std::cout << p1 << ' ' << p2 << '\n';
    }

    assert(e.size() == m);

    for (const auto& [from, to, w] : e)
    {
        std::cout << from << ' ' << to << ' ' << w << '\n';
    }

    return 0;
}