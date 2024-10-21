/**
 * Testing Round 19 (Div. 3)
 * 
 * => C2. Message Transmission Error (hard version)
 * 
 * -> https://codeforces.com/contest/2010/problem/C2
 * 
 * @b Hashing
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

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

    std::size_t P = 449;
    std::size_t MOD = 436522843;

    std::vector<ullong> h(s.size() + 1), p(s.size() + 1, 1);

    for (int i = 1; i <= s.size(); ++i)
    {
        h[i] = (h[i - 1] * P % MOD + s[i - 1]) % MOD;
        p[i] = (p[i - 1] * P) % MOD;
    }

    auto get = [&](int l, int r) -> ullong
    {
        return (h[r] + MOD - (h[l - 1] * p[r - l + 1]) % MOD) % MOD;
    };

    for (int i = s.size() / 2 + 1; i < s.size(); ++i)
    {
        if (get(1, i) == get(s.size() - i + 1, s.size()))
        {
            std::cout << "YES\n";
            std::cout << s.substr(0, i) << '\n';
            return 0;
        }
    }

    std::cout << "NO\n";

    return 0;
}