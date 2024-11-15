/**
 * 2024 China Collegiate Programming Contest (CCPC) Female Onsite (2024年中国大学生程序设计竞赛女生专场)
 * 
 * => G. Increasing Sequence
 * 
 * -> https://codeforces.com/gym/105487/problem/G
 * 
 * Submissions ~> https://codeforces.com/gym/105487/submission/291285315 By huanhuanonly
 * 
 * @b Digit-DP
 * 
 * ----November 13, 2024 [15h:58m:08s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint32 _;
    std::cin >> _;

    while (_--)
    {
        uint64 n, k;
        std::cin >> n >> k;

        std::vector<uint64> v(n);

        for (uint32 i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        enum : uint8 { Any = std::numeric_limits<uint8>::max() };

        std::array<uint8, 64> x;
        x.fill(Any);

        bool exist = true;

        for (uint64 i = 0; i + 1 < v.size() and exist; ++i)
        {
            for (uint64 j = 64; j--; )
            {
                if (uint64 l = ((v[i] >> j) & 1), r = ((v[i + 1] >> j) & 1); l != r)
                {
                    if (l == 0 and r == 1)
                    {
                        if (x[j] != Any and x[j] != 0)
                        {
                            exist = false;
                        }
                        else
                        {
                            x[j] = 0;
                        }
                    }
                    else
                    {
                        if (x[j] != Any and x[j] != 1)
                        {
                            exist = false;
                        }
                        else
                        {
                            x[j] = 1;
                        }
                    }

                    break;
                }
            }
        }

        if (exist == false)
        {
            std::cout << 0 << '\n';
            continue;
        }

        std::reverse(x.begin(), x.end());

        std::bitset<64> bs(k);

        constexpr uint64 inf = std::numeric_limits<uint64>::max();

        std::vector<uint64> dp(64, inf);

        auto dfs = [&](auto& dfs, uint32 pos, bool lead, bool limit) -> uint64
        {
            if (pos == dp.size())
            {
                return 1;
            }

            if (not lead and not limit and dp[pos] != inf)
            {
                return dp[pos];
            }

            uint64 cnt = 0;

            for (uint32 i = 0, up = (limit ? bs[bs.size() - 1 - pos] : 1); i <= up; ++i)
            {
                if (x[pos] == Any or x[pos] == i)
                {
                    cnt += dfs(dfs, pos + 1, lead and i == 0, limit and i == up);
                }
            }

            if (not lead and not limit)
            {
                dp[pos] = cnt;
            }

            return cnt;
        };

        std::cout << dfs(dfs, 0, true, true) << '\n';
    }

    return 0;
}