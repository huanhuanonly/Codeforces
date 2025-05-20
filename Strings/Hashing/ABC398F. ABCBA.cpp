/**
 * UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
 * 
 * => F - ABCBA ( @c 500 )
 * 
 * -> https://atcoder.jp/contests/abc398/tasks/abc398_f
 * 
 * Submissions ~> https://atcoder.jp/contests/abc398/submissions/64400214 By huanhuanonly
 * 
 * @b Hashing
 * 
 * ----March 31, 2025 [21h:45m:51s]----
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

    std::string s;
    std::cin >> s;

    static constexpr uint64 base = 449;
    static constexpr uint64 mod  = 436522843;

    std::vector<uint64> pre(s.size() + 1), suf(s.size() + 1);
    std::vector<uint64> pow(s.size() + 1, 1);
    
    for (int i = 1; i <= s.size(); ++i)
    {
        pre[i] = (pre[i - 1] * base % mod + s[i - 1]) % mod;
        suf[i] = (suf[i - 1] * base % mod + s[s.size() - i]) % mod;
        pow[i] = pow[i - 1] * base % mod;
    }

    auto get = [&](const auto& v, int l, int r) -> uint64
    {
        return (v[r] + mod - v[l - 1] * pow[r - l + 1] % mod) % mod;
    };
    
    if (pre.back() == suf.back())
    {
        std::cout << s;
        return 0;
    }

    int pos = 1 + s.size() / 2;

    bool is_old = false;

    for (; pos <= s.size(); ++pos)
    {
        // old
        if (get(pre, pos - (s.size() - pos), pos) == get(suf, 1, s.size() - pos + 1))
        {
            is_old = true;
            break;
        } else
        // even
        if (get(pre, pos - (s.size() - pos) + 1, pos) == get(suf, 1, s.size() - pos))
        {
            break;
        }
    }

    int n = s.size();

    s.resize(pos * 2 - is_old);

    for (int i = 0; i < s.size() / 2; ++i)
    {
        s[s.size() - i - 1] = s[i];
    }

    if (s.size() % 2 == 0 and n <= s.size() / 2 and s[s.size() / 2 - 1] == s[s.size() / 2])
    {
        s.erase(s.begin() + s.size() / 2);
    }
    
    std::cout << s;

    return 0;
}