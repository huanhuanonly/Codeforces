/**
 * Codeforces Round 1046 (Div. 2)
 * 
 * => F1. From the Unknown (Easy Version) ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2136/problem/F1
 * 
 * Submissions ~> https://codeforces.com/contest/2136/submission/338695039 By huanhuanonly
 * 
 * @b Interactive and @b Constructive
 * 
 * ----September 15, 2025 [16h:53m:17s]----
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
        constexpr int n = 1e5;

        static auto query = [](const auto& vs) -> int
        {
            std::cout << "? " << vs.size() << ' ';

            for (int i : vs)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;

            int res;
            std::cin >> res;

            return res;
        };

        static auto answer = [](int w) -> void
        {
            std::cout << "! " << w << std::endl;
        };

        const int cnt = query(std::views::iota(0, n) | std::views::transform([](int){ return 1; }));
        
        if (cnt == 1)
        {
            answer(n);
            continue;
        }

        const int l = n / cnt;
        const int r = std::ceil(double(n) / (cnt - 1)) - 1;

        assert(l * 2 > r);

        if (l >= r)
        {
            answer(l);
        }
        else
        {
            std::vector<int> q;
    
            for (int i = 1; i <= r - l; ++i)
            {
                q.push_back(l);
                q.push_back(i);
            }

            answer(r - (query(q) - (q.size() / 2)));
        }
    }

    return 0;
}