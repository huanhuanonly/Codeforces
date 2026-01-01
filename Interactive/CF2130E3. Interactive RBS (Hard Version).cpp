/**
 * Codeforces Round 1040 (Div. 2)
 * 
 * => E3. Interactive RBS (Hard Version) ( @c 2300 )
 * 
 * -> https://codeforces.com/contest/2130/problem/E3
 * 
 * Submissions ~> https://codeforces.com/contest/2130/submission/338146811 By huanhuanonly
 * 
 * @b Interactive
 * @b Binary-search
 * @b Constructive
 * @b Classification-discussion
 * 
 * ----September 12, 2025 [09h:14m:24s]----
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

    static auto $ = [](int i) -> int
    {
        return i * (i + 1) / 2;
    };

    std::vector<int> vcnt{1};

    for (int i = 1, sum = $(vcnt.front()), cnt = vcnt.front() * 2 + 1; cnt <= 1000; ++i)
    {
        if ($(i) > sum)
        {
            if ((cnt += i * 2 + 1) <= 1000)
            {
                sum += $(i);
                vcnt.push_back(i);
            }
        }
    }


    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;
        
        static auto query = [](const auto& v) -> int
        {
            std::cout << "? " << v.size() << ' ';

            for (int i : v)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;

            int res;
            std::cin >> res;

            return res;
        };

        static auto answer = [](const std::string& s) -> void
        {
            std::cout << "! " << s << std::endl;
        };

        int lci = n, rci = 1;

        if (query(std::views::iota(1, n + 1)))
        {
            int l = 0, r = n, mid;
    
            while (r - l > 1)
            {
                mid = l + r >> 1;
    
                if (query(std::views::iota(1, mid + 1)))
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }

            lci = r - 1, rci = r;
        }

        std::vector<int> ids;
        ids.reserve(1000);

        std::string ans;

        const int segsize = vcnt.size();

        for (int i = 1; i <= n; )
        {
            int cnt = 0;

            for (; cnt < segsize and i <= n; ++cnt, ++i)
            {
                for (int k = 0; k < vcnt[cnt]; ++k)
                {
                    ids.push_back(i);
                    ids.push_back(rci);
                }

                ids.push_back(rci);
            }

            int res = query(ids);
            ids.clear();

            std::string t;
            for (int j = cnt - 1; j >= 0; --j)
            {
                if (int cur = $(vcnt[j]); res >= cur)
                {
                    t += '(';
                    res -= cur;
                }
                else
                {
                    t += ')';
                }
            }

            std::ranges::reverse(t);
            ans += t;
        }

        answer(ans);
    }

    return 0;
}