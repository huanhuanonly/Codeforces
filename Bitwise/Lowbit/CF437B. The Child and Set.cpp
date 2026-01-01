/**
 * Codeforces Round 250 (Div. 2)
 * 
 * => B. The Child and Set ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/437/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/437/submission/338937195 By huanhuanonly
 * 
 * @b Lowbit and @b Dfs
 * 
 * ----September 16, 2025 [22h:34m:53s]----
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

    uint32 sum, limit;
    std::cin >> sum >> limit;

    static auto lowbit = [](uint32 x) -> uint32
    {
        return x & -x;
    };

    std::map<uint32, std::vector<uint32>> sets;

    for (uint32 i = 1; i <= limit; ++i)
    {
        sets[lowbit(i)].push_back(i);
    }

    std::set<uint32> st;
    
    auto fetch = [&](const auto& self, uint32 i) -> bool
    {
        if (not sets[i].empty())
        {
            st.insert(sets[i].back());
            sets[i].pop_back();
            return true;
        }
        else if (i == 1U)
        {
            return false;
        }
        else
        {
            return self(self, i >> 1) and self(self, i >> 1);
        }
    };
    
    bool can = true;

    for (; sum; sum -= lowbit(sum))
    {
        can = can and fetch(fetch, lowbit(sum));
    }

    if (can)
    {
        std::cout << st.size() << '\n';

        for (uint32 i : st)
        {
            std::cout << i << ' ';
        }
    }
    else
    {
        std::cout << -1;
    }

    return 0;
}