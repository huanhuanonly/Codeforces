/**
 * Codeforces Round 1059 (Div. 3)
 * 
 * => D. Beautiful Permutation ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2162/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2162/submission/344291342 By huanhuanonly
 * 
 * @b Interactive and @b Binary-search
 * 
 * ----October 19, 2025 [00h:03m:11s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        static auto query = [](int l, int r) -> int
        {
            std::cout << 1 << ' ' << l << ' ' << r << std::endl;
            
            int a;
            std::cin >> a;

            std::cout << 2 << ' ' << l << ' ' << r << std::endl;

            int b;
            std::cin >> b;

            return b - a;
        };

        static auto answer = [](int l, int r) -> void
        {
            std::cout << "! " << l << ' ' << r << std::endl;
        };

        const int len = query(1, n);

        auto dfs = [&](const auto& self, int l, int r) -> void
        {
            if (l == r)
            {
                answer(l, r);
                return;
            }

            const int mid = l + r >> 1;

            const int ls = query(l, mid);
            const int rs = len - ls;

            if (ls and rs)
            {
                answer(mid - ls + 1, mid + rs);
                return;
            }
            else if (ls)
            {
                self(self, l, mid);
            }
            else
            {
                self(self, mid + 1, r);
            }
        };

        dfs(dfs, 1, n);
    }

    return 0;
}