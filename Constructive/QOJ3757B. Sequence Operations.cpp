/**
 * The 2026 ICPC China Wuhan National Invitational and Hubei Provincial Programming Contest
 *
 * => B. Sequence Operations
 *
 * -> https://qoj.ac/contest/3757/problem/22149
 *
 * Submissions ~> https://qoj.ac/submission/2406662 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 20, 2026 [09h:31m:46s]----
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

int mex(int lhs, int rhs)
{
    if (rhs < lhs)
    {
        std::swap(lhs, rhs);
    }

    if (lhs == 0)
    {
        return 1 + (rhs == 1);
    }
    else
    {
        return 0;
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m;
        std::cin >> n >> m;

        std::set<int> set;

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            set.insert(v);
        }

        std::vector<std::pair<int, int>> ops(m);

        for (int i = 0; i < m; ++i)
        {
            std::cin >> ops[i].first >> ops[i].second;
        }

        auto check = [&](std::set<int> set) mutable -> bool
        {
            int gcd = 0;

            for (int i = 0; i < m; ++i)
            {
                if (ops[i].first == 1)
                {
                    set = set | std::views::transform([&](int x) -> int { return mex(x, ops[i].second); }) | std::ranges::to<std::set>();
                }
                else if (i + 1 < m and ops[i + 1].first == 2)
                {
                    gcd = std::gcd(gcd, ops[i].second);
                }
                else
                {
                    gcd = std::gcd(gcd, ops[i].second);
                    set = set | std::views::transform([&](int x) -> int { return std::gcd(x, gcd); }) | std::ranges::to<std::set>();
                    gcd = 0;
                }
            }

            return set.size() == 1;
        };

        int last = -1;

        for (int i = m - 1; i >= 0; --i)
        {
            if (ops[i].first == 0)
            {
                if (~last)
                {
                    ops[i].first = 2;
                }
                else
                {
                    last = i;
                }
            }
        }

        if (~last)
        {
            ops[last].first = 1;
            bool yes = check(set);
            ops[last].first = 2;
            yes = yes or check(set);

            if (yes)
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
        }
        else
        {
            if (check(set))
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
        }
    }

    return 0;
}