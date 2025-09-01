/**
 * Codeforces Round 1028 (Div. 1)
 * 
 * => A. Gellyfish and Flaming Peony ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2115/problem/A
 * 
 * Submissions ~> https://codeforces.com/contest/2115/submission/330546128 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----July 24, 2025 [00h:37m:58s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        std::ranges::sort(v);

        int gcd = std::reduce(v.begin() + 1, v.end(), v.front(), &std::gcd<int, int>);

        if (int cnt_gcd = std::ranges::count(v, gcd); cnt_gcd)
        {
            std::cout << n - cnt_gcd << '\n';
        }
        else
        {
            std::vector dp(*std::ranges::max_element(v) + 1, std::numeric_limits<int>::max() / 2);
            
            for (int i : v)
            {
                dp[i] = 0;
            }

            for (int i = dp.size() - 1; i >= gcd; --i)
            {
                for (int j : v)
                {
                    int g = std::gcd(i, j);
                    dp[g] = std::min(dp[g], dp[i] + 1);
                }
            }
    
            std::cout << n - 1 + dp[gcd] << '\n';
        }
    }

    return 0;
}