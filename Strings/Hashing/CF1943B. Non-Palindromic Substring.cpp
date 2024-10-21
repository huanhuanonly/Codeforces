/**
 * Codeforces Round 934 (Div. 1)
 * 
 * => B. Non-Palindromic Substring
 * 
 * -> https://codeforces.com/problemset/problem/1943/B (2000)
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
        int n, q;
        std::cin >> n >> q;

        std::string s;
        std::cin >> s;

        std::vector<std::array<int, 26>> pre(n + 1);
        pre.front().fill(0);

        std::vector<int> mxlen(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            pre[i] = pre[i - 1];
            ++pre[i][s[i - 1] - 'a'];

            if (i - 3 >= 0 and s[i - 1] == s[i - 3])
            {
                mxlen[i] = mxlen[i - 2] + 2;
            }
            else
            {
                mxlen[i] = 1;
            }
        }

        constexpr const int P = 449, MOD = 436522843;

        std::vector<ullong> p(n + 1, 1), h(n + 1), rh(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            p[i] = (p[i - 1] * P) % MOD;
            h[i] = (h[i - 1] * P + s[i - 1]) % MOD;
            rh[i] = (rh[i - 1] * P + s[n - i]) % MOD;
        }

        auto is_palindrome = [&](int l, int r) -> bool
        {
            return (h[r] + MOD - (h[l - 1] * p[r - l + 1]) % MOD) % MOD ==
                (rh[n - l + 1] + MOD - (rh[n - r] * p[r - l + 1]) % MOD) % MOD;
        };

        ullong l, r;
        
        while (q--)
        {
            std::cin >> l >> r;

            std::array<int, 26> ct = pre[r];

            for (int i = 0; i < 26; ++i)
                ct[i] -= pre[l - 1][i];

            if (l == r or std::find(ct.begin(), ct.end(), r - l + 1) != ct.end())
            {
                std::cout << 0 << '\n';
            }
            else if (mxlen[r] + 2 > r - l + 1 and mxlen[r - 1] + 2 > r - l)
            {
                ullong len = (r - l + 1) & ~1;
                std::cout << len * (len + 2) / 4 - ((r - l + 1) % 2 == 0 and is_palindrome(l, r) ? (r - l + 1) : 0) << '\n';
            }
            else
            {
                ullong len = r - l + 1;
                std::cout << len * (len + 1) / 2 - (is_palindrome(l, r) ? len : 0) - 1 << '\n';
            }
        }
    }

    return 0;
}