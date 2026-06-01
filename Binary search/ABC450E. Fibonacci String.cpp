/**
 * AtCoder Beginner Contest 450
 * 
 * => E - Fibonacci String ( @c 450 )
 * 
 * -> https://atcoder.jp/contests/abc450/tasks/abc450_e
 * 
 * Submissions ~> https://atcoder.jp/contests/abc450/submissions/74310577 By huanhuanonly
 * 
 * @b Prefix-sum and @b Binary-search
 * 
 * ----March 21, 2026 [21h:24m:48s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    std::string x, y;
    std::cin >> x >> y;

    std::vector<std::array<uint64, 26>> prex(x.size() + 1);
    std::vector<std::array<uint64, 26>> prey(y.size() + 1);

    for (int i = 1; i <= x.size(); ++i)
    {
        prex[i] = prex[i - 1];
        ++prex[i][x[i - 1] - 'a'];
    }

    for (int i = 1; i <= y.size(); ++i)
    {
        prey[i] = prey[i - 1];
        ++prey[i][y[i - 1] - 'a'];
    }

    std::vector<uint64> s{0, x.size(), y.size()};
    std::vector<std::array<uint64, 26>> sc(3);

    for (const char& c : x)
    {
        ++sc[1][c - 'a'];
    }

    for (const char& c : y)
    {
        ++sc[2][c - 'a'];
    }

    while (s.back() <= 1e18)
    {
        s.push_back(s.back() + s[s.size() - 2]);

        sc.push_back(sc.back());

        for (int i = 0; i < 26; ++i)
        {
            sc.back()[i] += sc[sc.size() - 3][i];
        }
    }

    auto calc = [&](uint64 n, char c) -> uint64
    {
        uint64 cnt = 0;
        int pos = s.size() - 1;

        while (n)
        {
            if (s[pos] == n)
            {
                cnt += sc[pos][c - 'a'];
                break;
            }
            else if (pos == 1)
            {
                cnt += prex[n][c - 'a'];
                break;
            }
            else if (pos == 2)
            {
                cnt += prey[n][c - 'a'];
                break;
            }

            if (n >= s[pos - 1])
            {
                cnt += sc[pos - 1][c - 'a'];
                n -= s[pos - 1];
                pos -= 2;
            }
            else
            {
                --pos;
            }
        }

        return cnt;
    };

    int q;
    std::cin >> q;

    while (q--)
    {
        uint64 l, r;
        char c;

        std::cin >> l >> r >> c;

        std::cout << calc(r, c) - calc(l - 1, c) << '\n';
    }

    return 0;
}