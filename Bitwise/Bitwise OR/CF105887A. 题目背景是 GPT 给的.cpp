/**
 * 第十三届重庆市大学生程序设计竞赛
 * 
 * => A. 题目背景是 GPT 给的
 * 
 * -> https://codeforces.com/gym/105887/problem/A
 * 
 * Submissions ~> https://codeforces.com/gym/105887/submission/319739109 By huanhuanonly
 * 
 * @b Bitwise-OR
 * 
 * ----May 16, 2025 [14h:55m:09s]----
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

    std::vector<uint64> mp{0};

    for (uint64 i = 1; mp.back() <= 1e5; ++i)
    {
        mp.push_back(mp.back() + i);
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<uint64> v(n * 2);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
            v[i + n] = v[i];
        }

        std::array<int, 31> last;
        last.fill(-1);

        int mx = 0;

        for (int i = 0; i < v.size(); ++i)
        {
            std::bitset<31> bs(v[i]);

            for (int j = bs._Find_first(); j != bs.size(); j = bs._Find_next(j))
            {
                if (last[j] == -1)
                {
                    last[j] = i;
                }
                else
                {
                    mx = std::max(mx, i - last[j] - 1);
                    last[j] = i;
                }
            }
        }

        std::cout << std::ranges::lower_bound(mp, mx) - mp.begin() << '\n';
    }

    return 0;
}