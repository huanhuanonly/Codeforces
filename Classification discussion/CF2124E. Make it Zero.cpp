/**
 * EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2)
 * 
 * => E. Make it Zero ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2124/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2124/submission/328065732 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----July 08, 2025 [17h:47m:32s]----
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

        std::vector<int64> v(n);

        int64 sum = 0, max = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
            
            sum += v[i];
            max = std::max(max, v[i]);
        }

        if ((sum & 1) or max > sum / 2)
        {
            std::cout << -1 << '\n';
            continue;
        }

        static auto output = [](int64 i) -> void
        {
            std::cout << i << ' ';
        };

        static auto reserve = [](auto first, auto last, int64 sum) -> void
        {
            for (; first != last; ++first)
            {
                if (sum >= *first)
                {
                    sum -= *first;
                }
                else if (sum)
                {
                    *first = std::exchange(sum, 0);
                }
                else
                {
                    *first = 0;
                }
            }
        };

        int64 cur = 0;

        for (int i = 0; i < n; ++i)
        {
            if ((cur += v[i]) > sum / 2)
            {
                int64 pre = cur - v[i], suf = sum - cur;
                cur = v[i];

                std::cout << 2 << '\n';

                if (cur == pre + suf)
                {
                    std::ranges::for_each(v.begin(), v.begin() + i, output);
                    std::cout << pre << ' ';
                    std::ranges::for_each(std::string(n - i - 1, 0), output);
                    std::cout.put('\n');

                    std::ranges::for_each(std::string(i, 0), output);
                    std::cout << suf << ' ';
                    std::ranges::for_each(v.begin() + i + 1, v.end(), output);
                    std::cout.put('\n');
                }
                else if (cur < pre + suf)
                {
                    auto t = v;
                    reserve(t.begin(), t.begin() + i, (suf - std::abs(pre - cur)) / 2 + std::max(pre - cur, 0LL));
                    reserve(t.begin() + i, t.begin() + i + 1, (suf - std::abs(pre - cur)) / 2 - std::min(pre - cur, 0LL));

                    std::ranges::for_each(t, output);
                    std::cout.put('\n');

                    std::ranges::for_each(t | std::views::transform([&v, i = 0](int64 val) mutable -> int64 { return v[i++] - val; }), output);
                    std::cout.put('\n');
                }
                else [[unlikely]]
                {
                    assert(false);
                }

                break;
            }
            else if (cur == sum / 2)
            {
                std::cout << 1 << '\n';
                
                std::ranges::for_each(v, output);
                std::cout.put('\n');

                break;
            }
        }
    }

    return 0;
}