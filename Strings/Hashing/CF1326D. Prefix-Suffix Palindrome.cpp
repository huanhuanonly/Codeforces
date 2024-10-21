/**
 * Codeforces Global Round 7
 * 
 * => D1. Prefix-Suffix Palindrome (Easy version)
 * 
 * -> https://codeforces.com/problemset/problem/1326/D1 (1500)
 * 
 * 
 * => D2. Prefix-Suffix Palindrome (Hard version)
 * 
 * -> https://codeforces.com/problemset/problem/1326/D2 (1800)
 * 
 * @b Hashing
*/

#include <bits/stdc++.h>

using uint = unsigned int;
using llong = long long int;
using ullong = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        std::string str;
        std::cin >> str;
        
        std::string_view s(str);

        int w = 0;
        while (w < s.size() and s[w] == s[s.size() - w - 1])
            ++w;

        if (w == s.size())
        {
            std::cout << s << '\n';
            continue;
        }

        s.remove_prefix(w);
        s.remove_suffix(w);

        constexpr const int P = 449, MOD = 436522843;

        std::vector<ullong> p(s.size() + 1, 1);

        std::vector<ullong> h(s.size() + 1), rh(s.size() + 1);

        for (int i = 1; i <= s.size(); ++i)
        {
            p[i] = (p[i - 1] * P) % MOD;
            
            h[i] = (h[i - 1] * P + s[i - 1]) % MOD;
            rh[i] = (rh[i - 1] * P + s[s.size() - i]) % MOD;
        }

        auto is_hash_equal = [&](int l, int r) -> bool
        {
            auto h1 = (h[r] - h[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;

            std::swap(l, r);

            l = s.size() - l + 1, r = s.size() - r + 1;
            auto h2 = (rh[r] - rh[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;

            return h1 == h2;
        };
        
        int l = 0, r = 0;
        
        for (int i = 1; i < s.size(); ++i)
        {
            if (is_hash_equal(1, i))
                l = i;
        }

        for (int i = 1; i < s.size(); ++i)
        {
            if (is_hash_equal(i, s.size()))
            {
                r = s.size() - i + 1;
                break;
            }
        }

        for (int i = 0; i < w; ++i)
            std::cout.put(str[i]);
        
        if (l >= r)
            std::cout << s.substr(0, l);
        else
            std::cout << s.substr(s.size() - r);
        
        for (int i = w - 1; i >= 0; --i)
            std::cout.put(str[i]);

        std::cout.put('\n');
    }

    return 0;
}