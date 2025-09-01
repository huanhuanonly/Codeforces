/**
 * Codeforces Round 1044 (Div. 2)
 * 
 * => C. The Nether ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2133/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2133/submission/335362759 By huanhuanonly
 * 
 * @b Interactive and @b Graphs
 * 
 * ----August 25, 2025 [01h:52m:58s]----
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

        auto query = [](int start, const std::vector<int>& s) -> int
        {
            std::cout << "? " << start << ' ' << s.size() << ' ';

            for (int i : s)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;

            int res;
            std::cin >> res;

            return res;
        };

        auto answer = [](const std::vector<int>& s) -> void
        {
            std::cout << "! " << s.size() << ' ';

            for (int i : s)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;
        };

        std::vector<int> ap(n);
        std::iota(ap.begin(), ap.end(), 1);

        std::vector<std::vector<int>> sets(n + 1);

        int max = 0;

        for (int i = 1; i <= n; ++i)
        {
            int res = query(i, ap);
            sets[res].push_back(i);

            max = std::max(max, res);
        }

        std::vector<int> s;
        s.reserve(max);

        for (int i = max; i >= 1; --i)
        {
            s.push_back({});

            for (int j : sets[i])
            {
                s.back() = j;
                if (query(s.front(), s) == s.size())
                {
                    break;
                }
            }
        }

        answer(s);
    }

    return 0;
}