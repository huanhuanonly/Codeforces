/**
 * Codeforces Round 1050 (Div. 4)
 * 
 * => G. Farmer John's Last Wish ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2148/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2148/submission/338623384 By huanhuanonly
 * 
 * @b Number-theory ( @a greatest-common-divisor | @a prime-factorization )
 * 
 * ----September 14, 2025 [23h:26m:06s]----
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

template<typename _Tp>
std::vector<_Tp> prime_factorization(_Tp __n)
{
    std::vector<_Tp> res;

    for (int i = 2; i <= __n / i; ++i)
    {
        for (int t = i; __n % i == 0; t *= i)
        {
            res.push_back(t);
            __n /= i;
        }
    }

    if (__n != 1)
        res.push_back(__n);

    return res;
}

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

        std::vector<int> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::map<int, int> cnt;
        std::multiset<int, std::ranges::greater> set;

        for (int i = 1; i <= n; ++i)
        {
            auto&& ps = prime_factorization(v[i]);

            for (int p : ps)
            {
                if (auto fit = cnt.find(p); fit != cnt.end())
                {
                    auto nd = set.extract(fit->second++);
                    ++nd.value();
                    set.insert(std::move(nd));
                }
                else
                {
                    set.insert(++cnt[p]);
                }
            }

            auto fit = set.upper_bound(i);
            std::cout << (fit != set.end() ? *fit : 0) << " \n"[i == n];
        }
    }

    return 0;
}