/**
 * Codeforces Round 1042 (Div. 3)
 * 
 * => H. Sea, You & copriMe ( @c 2600 )
 * 
 * -> https://codeforces.com/contest/2131/problem/H
 * 
 * Submissions ~> https://codeforces.com/contest/2131/submission/334521595 By huanhuanonly
 * 
 * @b Number-theory ( @a greatest-common-divisor | @a prime-factorization )
 * @b Combinatorics ( @a inclusion-exclusion-principle )
 * @b Graphs        ( @a degrees )
 * 
 * ----August 19, 2025 [19h:48m:36s]----
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
        int n, m;
        std::cin >> n >> m;

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        std::vector<int> cnt(m + 1);

        for (int x : v)
        {
            int sq = std::ceil(std::sqrt(x));

            for (int i = 1; i < sq; ++i)
            {
                if (x % i == 0)
                {
                    ++cnt[i];
                    ++cnt[x / i];
                }
            }

            if (sq * sq == x)
            {
                ++cnt[sq];
            }
        }

        std::vector<std::vector<int>> pf(m + 1);

        for (int i = 2; i <= m; ++i)
        {
            if (pf[i].empty())
            {
                for (int j = i; j <= m; j += i)
                {
                    pf[j].push_back(i);
                }
            }
        }

        std::vector<int> degree(n);

        for (int idx = 0; idx < n; ++idx)
        {
            int  x = v[idx];
            int& d = degree[idx];

            d = n;

            std::vector<int> dp(1 << pf[x].size(), 1);

            for (uint32 i = 1; i < (1U << pf[x].size()); ++i)
            {
                dp[i] = dp[i ^ (i & -i)] * pf[x][std::countr_zero(i)];
                d += cnt[dp[i]] * ((std::popcount(i) & 1) ? -1 : +1);
            }
        }

        int ppos = std::ranges::max_element(degree) - degree.begin();

        if (degree[ppos] == 0)
        {
            std::cout << 0 << '\n';
            continue;
        }

        std::pair<int, int> qpos{std::numeric_limits<int>::max(), 0};

        for (int i = 0; i < n; ++i)
        {
            if (i != ppos and std::gcd(v[i], v[ppos]) == 1)
            {
                qpos = std::min(qpos, {degree[i], i});
                --degree[i];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (i != ppos and i != qpos.second and std::gcd(v[i], v[qpos.second]) == 1)
            {
                --degree[i];
            }
        }

        degree[ppos] = degree[qpos.second] = 0;

        int rpos = std::ranges::find(degree, true, [](int i) -> bool { return static_cast<bool>(i); }) - degree.begin();
        
        if (rpos == degree.size())
        {
            std::cout << 0 << '\n';
            continue;
        }

        int spos = 0;

        for (; spos < n; ++spos)
        {
            if (spos != ppos and spos != qpos.second and spos != rpos and std::gcd(v[rpos], v[spos]) == 1)
            {
                break;
            }
        }

        std::cout << ++ppos << ' ' << ++qpos.second << ' ' << ++rpos << ' ' << ++spos << '\n';
    }

    return 0;
}