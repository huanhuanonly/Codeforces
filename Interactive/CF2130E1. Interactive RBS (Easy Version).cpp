/**
 * Codeforces Round 1040 (Div. 2)
 * 
 * => E1. Interactive RBS (Easy Version) ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2130/problem/E1
 * 
 * Submissions ~> https://codeforces.com/contest/2130/submission/338091941 By huanhuanonly
 * 
 * @b Interactive
 * @b Binary-search
 * @b Constructive
 * @b Classification-discussion
 * 
 * ----September 11, 2025 [22h:09m:41s]----
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

        std::vector<int> ids(6);
        ids[1] = rci;
        ids[2] = ids[4] = lci;

        std::string ans;

        for (int i = 2; i <= n; i += 2)
        {
            ids[0] = i - 1;
            ids[3] = ids[5] = i;

            const int res = query(ids);

            if (res == 0)
            {
                ans += ")(";
            }
            else if (res == 1)
            {
                ans += "((";
            }
            else if (res == 3)
            {
                ans += "))";
            }
            else
            {
                ans += "()";
            }
        }

        if (n & 1)
        {
            const int res = query(std::array{lci, n});

            if (res == 0)
            {
                ans += '(';
            }
            else
            {
                ans += ')';
            }
        }

        answer(ans);
    }

    return 0;
}