/**
 * 2025年码蹄杯 职业院校赛道 & 青少年挑战赛道入门组国赛
 * 
 * => MC0443 蝴蝶种类 ( @c 星耀 )
 * 
 * -> https://www.matiji.net/exam/brushquestion/43/4693/305EE97B0D5E361DE6A28CD18C929AF0
 * 
 * Submissions ~> https://www.matiji.net/exam/oj/submit-detail/15237290/43/4693/305EE97B0D5E361DE6A28CD18C929AF0 By huanhuanonly
 * 
 * @b 2D-Prefix-sum
 * 
 * ----August 29, 2025 [16h:51m:31s]----
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

    std::map<int, int> mp;

    std::vector<std::vector<int>> pre(n + 1, std::vector<int>(m + 1));

    int v;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> v;
            
            auto it = mp.find(v);
            
            if (it == mp.end())
            {
                ++pre[i][j];
                mp[v] = j;
            }
            else
            {
                if (j < it->second)
                {
                    ++pre[i][j];
                    --pre[i][it->second];
                    it->second = j;
                }
            }

            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            std::cout << pre[i][j] << " \n"[j == m];
        }
    }

    return 0;
}