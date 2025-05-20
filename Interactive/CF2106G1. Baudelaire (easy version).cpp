/**
 * Codeforces Round 1020 (Div. 3)
 * 
 * => G1. Baudelaire (easy version) ( @c Rating )
 * 
 * -> https://codeforces.com/contest/2106/problem/G1
 * 
 * Submissions ~> https://codeforces.com/contest/2106/submission/317185604 By huanhuanonly
 * 
 * @b Interactive
 * 
 * ----April 25, 2025 [22h:09m:47s]----
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

int query(const std::vector<int>& u)
{
    std::cout << "? 1 " << u.size() << ' ';

    for (int i : u)
    {
        std::cout << i << ' ';
    }

    std::cout << std::endl;

    int res;
    std::cin >> res;

    return res;
}

void invert(int u)
{
    std::cout << "? 2 " << u << std::endl;
}

void answer(const std::vector<int>& v)
{
    std::cout << "! ";

    for (int i : v | std::views::drop(1))
    {
        std::cout << i << ' ';
    }

    std::cout << std::endl;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;
        }

        std::vector<int> v(n + 1);

        int is_root = false;

        while (true)
        {
            switch (v[1] = query({1}))
            {
            case 0:
                invert(1);
                continue;

            // node 1 is the root
            case 1: case -1:
                is_root = true;
                goto got;

            case 2:
                v[1] = 1;
                goto got;

            case -2:
                v[1] = -1;
                goto got;

            default: throw;
            }
        }

    got:

        invert(1);
        v[1] = -v[1];

        for (int i = 2; i <= n; ++i)
        {
            v[i] = query({i});

            if (is_root)
            {
                v[i] -= v[1];
            }
        }

        answer(v);
    }

    return 0;
}