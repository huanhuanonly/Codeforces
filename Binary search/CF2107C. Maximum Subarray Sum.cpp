/**
 * Codeforces Round 1023 (Div. 2)
 * 
 * => C. Maximum Subarray Sum ( @c Rating )
 * 
 * -> https://codeforces.com/contest/2107/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2107/submission/318713428 By huanhuanonly
 * 
 * @b BinarySearch
 * 
 * ----May 07, 2025 [18h:33m:34s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int64 n, k;
        std::cin >> n >> k;

        std::string s;
        std::cin >> s;

        std::vector<int64> v(n);

        for (int64& i : v)
        {
            std::cin >> i;
        }

        auto fpos = std::ranges::find(s, '0') - s.begin();

        for (auto i = fpos + 1; i < v.size(); ++i)
        {
            if (s[i] == '0')
            {
                v[i] = -static_cast<int64>(1e18);
            }
        }

        int64 maxsum = 0;

        for (int64 i = 0, sum = 0; i < n; ++i)
        {
            if ((sum += v[i]) <= 0)
            {
                sum = 0;
            }
            else
            {
                maxsum = std::max(maxsum, sum);
            }
        }

        if (maxsum == k)
        {
            std::cout << "YES\n";

            for (const int64& i : v)
            {
                std::cout << i << ' ';
            }

            std::cout.put('\n');
        }
        else if (fpos == s.size())
        {
            std::cout << "NO\n";
        }
        else
        {
            auto eval = [&]() -> int64
            {
                maxsum = 0;

                for (int64 i = 0, sum = 0; i < n; ++i)
                {
                    if ((sum += v[i]) <= 0)
                    {
                        sum = 0;
                    }
                    else
                    {
                        maxsum = std::max(maxsum, sum);
                    }
                }

                return maxsum;
            };

            auto check = [&](int64 mid) -> bool
            {
                v[fpos] = mid;
                return eval() >= k;
            };

            int64 l = -static_cast<int64>(1e12) - 1, r = static_cast<int64>(1e12), mid;

            while (r - l > 1)
            {
                mid = l + r >> 1;

                if (check(mid))
                    r = mid;
                else
                    l = mid;
            }

            v[fpos] = r;

            if (eval() == k)
            {
                std::cout << "YES\n";
                
                for (const int64& i : v)
                {
                    std::cout << i << ' ';
                }
    
                std::cout.put('\n');
            }
            else
            {
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}