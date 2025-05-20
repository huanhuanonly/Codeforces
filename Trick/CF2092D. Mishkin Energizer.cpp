/**
 * Codeforces Round 1014 (Div. 2)
 * 
 * => D. Mishkin Energizer ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2092/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2092/submission/317430302 By huanhuanonly
 * 
 * @b Brute-force
 * 
 * ----April 27, 2025 [16h:47m:56s]----
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

        std::string s;
        std::cin >> s;

        if (std::count(s.begin(), s.end(), s.front()) == s.size())
        {
            std::cout << -1 << '\n';
            continue;
        }

        std::map<char, int> cnt;

        for (int i = 0; i < s.size(); ++i)
        {
            ++cnt[s[i]];
        }

        int mx = std::max({cnt['L'], cnt['I'], cnt['T']});

        auto another = [](char a, char b) -> char
        {
            for (char c : "LIT")
            {
                if (a != c and b != c)
                {
                    return c;
                }
            }

            return '\0';
        };

        std::vector<int> ans;
        int last = -1;

        while (not(cnt['L'] == cnt['I'] and cnt['I'] == cnt['T'] and ans.size() <= n * 2))
        {
            if (last != ans.size())
                last = ans.size();
            else
                if ((++mx) > n * 2)
                    break;

            for (int i = 0; i < s.size() - 1; ++i)
            {
                while (ans.size() <= n * 2)
                {
                    if (char c = another(s[i], s[i + 1]); s[i] != s[i + 1] and cnt[c] != mx)
                    {
                        s.insert(s.begin() + i + 1, c);
                        ans.push_back(i + 1);
                        ++cnt[c];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        if (cnt['L'] == cnt['I'] and cnt['I'] == cnt['T'] and ans.size() <= n * 2)
        {
            std::cout << ans.size() << '\n';

            for (int i : ans)
            {
                std::cout << i << '\n';
            }
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}