/**
 * 牛客周赛 Round 143
 *
 * => F-小红的网格路径 II ( @c 2000 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134529/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83551694 By huanhuanonly
 *
 * @b DP with @b Dynamic-segment-tree
 *
 * ----May 11, 2026 [00h:30m:22s]----
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

class LazySegmentTree
{
public:

    LazySegmentTree() : tree(2)
    { }

    int $(int& u)
    {
        return u ? u : (u = tree.size(), tree.emplace_back(), tree.size() - 1);
    }

    void push_up(int u)
    {
        tree[u].value = tree[tree[u].ls].value + tree[tree[u].rs].value;
    }

    void add_lazy(int u, int l, int r, uint64 value)
    {
        tree[u].value = value * (r - l + 1);
        tree[u].lazy = value;
    }

    void push_down(int u, int l, int r)
    {
        if (tree[u].lazy)
        {
            const int mid = l + r >> 1;
            add_lazy($(tree[u].ls), l, mid, *tree[u].lazy);
            add_lazy($(tree[u].rs), mid + 1, r, *tree[u].lazy);
            tree[u].lazy = std::nullopt;
        }
    }

    uint64 reduce(int u, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            return tree[u].value;
        }

        push_down(u, l, r);

        const int mid = l + r >> 1;

        uint64 sum = 0;

        if (x <= mid)
        {
            sum = reduce($(tree[u].ls), l, mid, x, y);
        }

        if (y > mid)
        {
            sum += reduce($(tree[u].rs), mid + 1, r, x, y);
        }

        return sum;
    }

    void range_assign(int u, int l, int r, int x, int y, uint64 value)
    {
        if (x <= l and r <= y)
        {
            add_lazy(u, l, r, value);
            return;
        }

        push_down(u, l, r);

        const int mid = l + r >> 1;

        if (x <= mid)
        {
            range_assign($(tree[u].ls), l, mid, x, y, value);
        }

        if (y > mid)
        {
            range_assign($(tree[u].rs), mid + 1, r, x, y, value);
        }

        push_up(u);
    }

private:

    struct node
    {
        int ls = 0, rs = 0;
        uint64 value = 0;
        std::optional<uint64> lazy;
    };

    std::vector<node> tree;
};

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

    uint64 n, m, k;
    std::cin >> n >> m >> k;

    constexpr uint64 mod = 1e9 + 7;

    std::vector<std::pair<uint64, uint64>> v(k + 2);
    v[k + 1].second = m;

    for (uint64 i = 1; i <= k; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
    }

    std::ranges::sort(v | std::views::drop(1) | std::views::take(k), {}, &std::pair<uint64, uint64>::second);

    LazySegmentTree dp;
    dp.range_assign(1, 1, n, 1, 1, 1);

    for (uint64 i = 1; i <= k + 1; ++i)
    {
        if (v[i].second == v[i - 1].second)
        {
            continue;
        }

        if (v[i].second - v[i - 1].second >= 2)
        {
            dp.range_assign(1, 1, n, 1, n, dp.reduce(1, 1, n, 1, n) % mod * binary_exponentiation(n, v[i].second - v[i - 1].second - 2, mod) % mod);
        }

        if (const auto x = v[i].first)
        {
            dp.range_assign(1, 1, n, x, x, 0);

            if (x - 1 >= 1)
            {
                dp.range_assign(1, 1, n, 1, x - 1, dp.reduce(1, 1, n, 1, x - 1) % mod);
            }

            if (x + 1 <= n)
            {
                dp.range_assign(1, 1, n, x + 1, n, dp.reduce(1, 1, n, x + 1, n) % mod);
            }
        }
        else
        {
            dp.range_assign(1, 1, n, 1, n, dp.reduce(1, 1, n, x, n) % mod);
        }
    }

    std::cout << dp.reduce(1, 1, n, n, n) % mod << '\n';

    return 0;
}