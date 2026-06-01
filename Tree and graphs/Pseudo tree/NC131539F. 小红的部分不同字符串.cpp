/**
 * 牛客周赛 Round 139
 *
 * => F-小红的部分不同字符串 ( @c 1800 )
 *
 * -> https://ac.nowcoder.com/acm/contest/131539/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83284769 By huanhuanonly
 *
 * @b Pseudo-tree and @b Combinatorics
 *
 * ----April 14, 2026 [20h:52m:38s]----
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

inline namespace huanhuanonly {
    inline namespace math
{
template<typename _Tp>
[[nodiscard]] constexpr _Tp binary_exponentiation(_Tp __lhs, _Tp __rhs, _Tp __mod)
{
    auto res = static_cast<_Tp>(1);

    for (__lhs %= __mod; __rhs; __lhs = (__lhs * __lhs) % __mod, __rhs >>= 1)
    {
        if (__rhs & 1)
        {
            res = (res * __lhs) % __mod;
        }
    }

    return res;
}
}} // namespace huanhuanonly::math

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        int u;
        std::cin >> u;

        e[u].push_back(i);
        e[i].push_back(u);
    }

    constexpr uint64 mod = 998244353;

    std::vector<bool> vis(n + 1);
    std::vector<bool> inp(n + 1);

    std::vector<int> stack;

    auto dfs = [&](const auto& self, int u, int fa) -> std::pair<int, int>
    {
        if (inp[u])
        {
            if (const auto fit = std::ranges::find(stack | std::views::reverse, u); fit != stack.rend())
            {
                return {0, fit - stack.rbegin() + 1};
            }
            else
            {
                return {0, 0};
            }
        }

        if (vis[u])
        {
            return {0, 0};
        }

        vis[u] = true;
        inp[u] = true;

        stack.push_back(u);

        int cnt = 1;
        int len = 2;

        for (const auto& i : e[u])
        {
            if (i != fa)
            {
                const auto& res = self(self, i, u);

                cnt += res.first;
                len = std::max(len, res.second);
            }
        }

        inp[u] = false;
        stack.pop_back();

        return {cnt, len};
    };

    uint64 ans = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (not vis[i])
        {
            const auto& res = dfs(dfs, i, 0);

            (ans *= (binary_exponentiation<uint64>(25, res.second, mod) + ((res.second & 1) ? mod - 25 : 25)) % mod) %= mod;
            (ans *= binary_exponentiation<uint64>(25, res.first - res.second, mod)) %= mod;
        }
    }

    std::cout << ans << '\n';

    return 0;
}