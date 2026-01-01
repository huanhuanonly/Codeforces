/**
 * Codeforces Round 1043 (Div. 3)
 * 
 * => G. Famous Choreographer ( @c 2600 )
 * 
 * -> https://codeforces.com/contest/2132/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2132/submission/336837212 By huanhuanonly
 * 
 * @b 2D-Hashing
 * 
 * ----September 04, 2025 [15h:09m:41s]----
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
constexpr _Tp binary_exponentiation(_Tp __fv, _Tp __sv, _Tp __mod)
{
    __fv %= __mod;

    _Tp ans = 1;
    for (; __sv; __fv = (__fv * __fv) % __mod, __sv >>= 1)
        if (__sv & 1)
            ans = (ans * __fv) % __mod;
    return ans;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    constexpr uint64 mod = 1e9 + 7;

    constexpr uint64 base[2]{13, 59};
    constexpr uint64 binv[2]{binary_exponentiation(base[0], mod - 2, mod), binary_exponentiation(base[1], mod - 2, mod)};

    constexpr uint64 maxn = 1e6 + 1;

    std::vector<uint64> p(maxn, 1), q(maxn, 1);
    std::vector<uint64> pinv(maxn, 1), qinv(maxn, 1);

    for (int i = 1; i < maxn; ++i)
    {
        p[i] = p[i - 1] * base[0] % mod;
        q[i] = q[i - 1] * base[1] % mod;

        pinv[i] = pinv[i - 1] * binv[0] % mod;
        qinv[i] = qinv[i - 1] * binv[1] % mod;
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        uint64 n, m;
        std::cin >> n >> m;

        std::vector map(n + 1, std::vector<char>(m + 1));

        std::vector h(n + 1, std::vector<uint64>(m + 1));
        std::vector r(n + 2, std::vector<uint64>(m + 2));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                std::cin >> map[i][j];
                h[i][j] = (h[i - 1][j] + h[i][j - 1] + mod - h[i - 1][j - 1] + uint64(map[i][j]) * p[i - 1] % mod * q[j - 1] % mod) % mod;
            }
        }
        
        for (int i = n; i >= 1; --i)
        {
            for (int j = m; j >= 1; --j)
            {
                r[i][j] = (r[i + 1][j] + r[i][j + 1] + mod - r[i + 1][j + 1] + uint64(map[i][j]) * p[n - i] % mod * q[m - j] % mod) % mod;
            }
        }

        auto check = [&](const std::pair<int, int>& s, const std::pair<int, int>& t) -> bool
        {
            return
                (mod + mod + h[t.first][t.second] - h[s.first - 1][t.second] - h[t.first][s.second - 1] + h[s.first - 1][s.second - 1]) % mod *
                    (pinv[s.first - 1] * qinv[s.second - 1] % mod) % mod ==
                (mod + mod + r[s.first][s.second] - r[t.first + 1][s.second] - r[s.first][t.second + 1] + r[t.first + 1][t.second + 1]) % mod *
                    (pinv[n - t.first] * qinv[m - t.second] % mod) % mod;
        };

        uint64 ans = std::numeric_limits<uint64>::max();

        for (uint64 i = 1; i <= n; ++i)
        {
            for (uint64 j = 1; j <= m; ++j)
            {
                if (check({1, 1}, {i, j}))
                {
                    ans = std::min(ans, n * m - i * j + (n - i) * (m - j) * 2);
                }

                if (check({1, j}, {i, m}))
                {
                    ans = std::min(ans, n * m - i * (m - j + 1) + (n - i) * (j - 1) * 2);
                }

                if (check({i, 1}, {n, j}))
                {
                    ans = std::min(ans, n * m - (n - i + 1) * j + (i - 1) * (m - j) * 2);
                }

                if (check({i, j}, {n, m}))
                {
                    ans = std::min(ans, n * m - (n - i + 1) * (m - j + 1) + (i - 1) * (j - 1) * 2);
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}