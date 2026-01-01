/**
 * Codeforces Round 1065 (Div. 3)
 * 
 * => E. Anisphia Wynn Palettia and Good Permutations ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2171/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2171/submission/350014752 By huanhuanonly
 * 
 * @b Constructive and @b Number-theory ( @a greatest-common-divisor )
 * 
 * ----November 21, 2025 [11h:54m:43s]----
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

        std::vector<bool> vis(n + 1);

        std::vector<int> buffer;
        buffer.reserve(n);

        for (int i = 2; i <= 3; ++i)
        {
            for (int x = i; x <= n; x += i)
            {
                if (not vis[x])
                {
                    buffer.push_back(x);
                    vis[x] = true;
                }
            }
        }

        std::vector<int> log;
        log.reserve(n);

        for (int i = 1; i <= n; ++i)
        {
            if (not vis[i])
            {
                log.push_back(i);
            }
        }

        std::vector<int> ans;
        ans.reserve(n);

        while (buffer.size() >= 2)
        {
            if (not log.empty())
            {
                ans.push_back(log.back());
                log.pop_back();
            }

            ans.push_back(buffer.back());
            buffer.pop_back();

            ans.push_back(buffer.back());
            buffer.pop_back();
        }

        if (not buffer.empty())
        {
            ans.push_back(buffer.back());
        }

        if (not log.empty())
        {
            ans.insert(ans.end(), log.begin(), log.end());
        }

        assert(ans.size() == n);

        for (const int i : ans)
        {
            std::cout << i << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}