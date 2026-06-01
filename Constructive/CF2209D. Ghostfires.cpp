/**
 * Codeforces Round 1087 (Div. 2)
 *
 * => D. Ghostfires ( @c 1800 )
 *
 * -> https://codeforces.com/contest/2209/problem/D
 *
 * Submissions ~> https://codeforces.com/contest/2209/submission/368220059 By huanhuanonly
 *
 * @b Constructive
 *
 * ----March 26, 2026 [13h:58m:53s]----
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

std::string operator*(const std::string& s, std::size_t n)
{
    std::string res;

    while (n--)
    {
        res += s;
    }

    return res;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        std::array<std::pair<int, char>, 3> v{{{0, 'R'}, {0, 'G'}, {0, 'B'}}};

        std::cin >> v[0].first >> v[1].first >> v[2].first;

        std::ranges::sort(v, std::ranges::greater{});

        std::string s;
        s.reserve(v[0].first + v[1].first + v[2].first);

        const int three = std::max(v[2].first - (v[0].first - v[1].first), 0);

        const std::array<std::string, 3> tl{
            std::string{v[0].second, v[1].second, v[2].second},
            std::string{v[1].second, v[2].second, v[0].second},
            std::string{v[2].second, v[0].second, v[1].second}};

        for (int i = 0, pos = 0; i < three; ++i, ++pos %= 3)
        {
            s.append(tl[pos]);
        }

        v[0].first -= three;
        v[1].first -= three;
        v[2].first -= three;

        auto try_insert = [&](int fid, int sid) -> void
        {
            for (int i = 0; i <= s.size(); ++i)
            {
                if (i < s.size() and s[i] == v[sid].second)
                {
                    continue;
                }

                if (i + 1 < s.size() and s[i + 1] == v[fid].second)
                {
                    continue;
                }

                if (i + 2 < s.size() and s[i + 2] == v[sid].second)
                {
                    continue;
                }

                if (i - 1 >= 0 and s[i - 1] == v[fid].second)
                {
                    continue;
                }

                if (i - 2 >= 0 and s[i - 2] == v[sid].second)
                {
                    continue;
                }

                if (i - 3 >= 0 and s[i - 3] == v[fid].second)
                {
                    continue;
                }

                const int cnt = std::min(v[fid].first, v[sid].first);
                s.insert(i, (std::string(1, v[fid].second) + v[sid].second) * cnt);

                v[fid].first -= cnt;
                v[sid].first -= cnt;

                return;
            }
        };

        try_insert(0, 1);
        try_insert(1, 0);
        try_insert(0, 2);
        try_insert(2, 0);
        try_insert(1, 2);
        try_insert(2, 1);

        std::ranges::sort(v, std::ranges::greater{});

        if (v[0].first)
        {
            if (not (s.size() >= 1 and v[0].second == s[s.size() - 1]) and
                not (s.size() >= 3 and v[0].second == s[s.size() - 3]))
            {
                s.push_back(v[0].second);
                --v[0].first;
            }
        }

        if (v[0].first)
        {
            if (not (s.size() >= 1 and v[0].second == s[0]) and
                not (s.size() >= 3 and v[0].second == s[2]))
            {
                s.insert(s.begin(), v[0].second);
                --v[0].first;
            }
        }

        std::cout << s << '\n';
    }

    return 0;
}