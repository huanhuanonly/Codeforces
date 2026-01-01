/**
 * Codeforces Round 1061 (Div. 2)
 * 
 * => C. Maximum GCD on Whiteboard ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2156/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2156/submission/345589880 By huanhuanonly
 * 
 * @b Number-theory ( @a greatest-common-divisor )
 * @b Difference-array and @b Prefix-sum
 * 
 * ----October 25, 2025 [00h:37m:59s]----
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
        int n, k;
        std::cin >> n >> k;

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }
        
        std::vector<int> cnt(n + 2);

        for (int t : v)
        {
            const int limit = t / 4;

            ++cnt[1];
            --cnt[limit + 1];

            for (int i = 1; i <= std::sqrt(t); ++i)
            {
                if (t % i == 0)
                {
                    if (i > limit)
                    {
                        ++cnt[i];
                        --cnt[i + 1];
                    }

                    if (t / i != i and t / i > limit)
                    {
                        ++cnt[t / i];
                        --cnt[t / i + 1];
                    }
                }
            }
        }

        std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());

        int ans = 1;

        for (int i = 1; i <= n; ++i)
        {
            if (cnt[i] + k >= n)
            {
                ans = i;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}