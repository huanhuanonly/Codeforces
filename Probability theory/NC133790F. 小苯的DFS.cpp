/**
 * 牛客周赛 Round 142
 *
 * => F-小苯的DFS ( @c 1900 )
 *
 * -> https://ac.nowcoder.com/acm/contest/133790/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83493036 By huanhuanonly
 *
 * @b Probability-theory
 * @b Dfs on @a Trees
 *
 * ----May 06, 2026 [09h:44m:31s]----
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
template<
    typename _Tp, std::unsigned_integral _Up, typename _Mp,
    typename _MulOp = std::multiplies<_Tp>, typename _ModOp = std::modulus<void>>
requires
    requires(_MulOp __op, _Tp __x) { { __op(__x, __x) } -> std::convertible_to<_Tp>; } and
    requires(_ModOp __op, _Tp __lhs, _Mp __rhs) { { __op(__lhs, __rhs) } -> std::convertible_to<_Tp>; }
[[nodiscard]] constexpr _Tp
binary_exponentiation(_Tp __lhs, _Up __rhs, _Mp __mod, _MulOp __mul_op = {}, _ModOp __mod_op = {})
{
    auto result = static_cast<_Tp>(1);

    for (__lhs = __mod_op(__lhs, __mod); __rhs; __lhs = __mod_op(__mul_op(__lhs, __lhs), __mod), __rhs >>= 1)
    {
        if (__rhs & 1)
        {
            result = __mod_op(__mul_op(result, __lhs), __mod);
        }
    }

    return result;
}

template<typename _Tp, std::unsigned_integral _Up, typename _MulOp = std::multiplies<_Tp>>
requires requires(_MulOp __op, _Tp __x) { { __op(__x, __x) } -> std::convertible_to<_Tp>; }
[[nodiscard]] constexpr _Tp
binary_exponentiation(_Tp __lhs, _Up __rhs, _MulOp __mul_op = {})
{
    auto result = static_cast<_Tp>(1);

    for (; __rhs; __lhs = __mul_op(__lhs, __lhs), __rhs >>= 1)
    {
        if (__rhs & 1)
        {
            result = __mul_op(result, __lhs);
        }
    }

    return result;
}
}} // namespace huanhuanonly::math

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
        int n;
        std::cin >> n;

        std::vector<int> w(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> w[i];
        }

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        constexpr uint64 mod = 998244353;

        struct node
        {
            int min, max;
            uint64 p;
        };

        std::vector<node> tree(n + 1);

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            tree[u] = {w[u], w[u], 1};

            std::vector<node> list;

            for (const auto& v : e[u])
            {
                if (v != fa)
                {
                    self(self, v, u);

                    tree[u].min = std::min(tree[u].min, tree[v].min);
                    tree[u].max = std::max(tree[u].max, tree[v].max);
                    list.push_back(tree[v]);
                }
            }

            if (tree[u].min < w[u])
            {
                tree[u].p = 0;
                return;
            }

            if (list.empty())
            {
                return;
            }

            std::ranges::sort(list, {}, [](const node& i) { return std::make_pair(i.min, i.max); });

            for (uint64 i = 1; i < list.size(); ++i)
            {
                if (list[i - 1].max > list[i].min)
                {
                    tree[u].p = 0;
                    return;
                }
            }

            for (uint64 i = 0; i < list.size(); )
            {
                uint64 cnt = 1;

                if (list[i].min == list[i].max)
                {
                    for (; i + cnt < list.size() and list[i + cnt].min == list[i].min and list[i + cnt].max == list[i].max; ++cnt);
                }

                for (; cnt; --cnt, ++i)
                {
                    tree[u].p *= cnt * binary_exponentiation(list.size() - i, mod - 2, mod) % mod * list[i].p % mod;
                    tree[u].p %= mod;
                }
            }
        };

        dfs(dfs, 1, 0);

        std::cout << tree[1].p << '\n';
    }

    return 0;
}
