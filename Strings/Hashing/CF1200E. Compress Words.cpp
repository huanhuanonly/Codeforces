/**
 * Codeforces Round 578 (Div. 2)
 * 
 * => E. Compress Words
 * 
 * -> https://codeforces.com/problemset/problem/1200/E
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

    int n;
    std::cin >> n;

    constexpr const int P = 449, MOD = 436522843;

    std::vector<ullong> p(1e6 + 1, 1);

    for (int i = 1; i < p.size(); ++i)
    {
        p[i] = p[i - 1] * P % MOD;
    }

    std::vector<ullong> h(1);
    h.reserve(1e6 + 1);

    auto get = [&](int l, int r) -> ullong
    {
        return (h[r] + MOD - h[l - 1] * p[r - l + 1] % MOD) % MOD;
    };

    std::string s;

    std::string ans;
    std::cin >> ans;

    for (int i = 0; i < ans.size(); ++i)
    {
        h.push_back((h.back() * P + ans[i]) % MOD);
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> s;

        int mx = 0;

        ullong hs = 0;
        for (int j = 0; j < s.size() and j < ans.size(); ++j)
        {
            hs = (hs * P + s[j]) % MOD;

            if (get(ans.size() - j, ans.size()) == hs)
            {
                mx = j + 1;
            }
        }

        for (; mx < s.size(); ++mx)
        {
            h.push_back((h.back() * P + s[mx]) % MOD);
            ans.push_back(s[mx]);
        }
    }

    std::cout << ans;

    return 0;
}