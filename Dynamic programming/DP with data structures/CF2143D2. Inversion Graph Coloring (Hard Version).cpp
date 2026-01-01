/**
 * Codeforces Round 1051 (Div. 2)
 * 
 * => D2. Inversion Graph Coloring (Hard Version) ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2143/problem/D2
 * 
 * Submissions ~> https://codeforces.com/contest/2143/submission/339822218 By huanhuanonly
 * 
 * @b DP with @b Binary-indexed-tree
 * 
 * ----September 22, 2025 [11h:18m:55s]----
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

inline namespace huanhuanonly
{
template<typename _Tp, _Tp _Modulus>
class StaticModular
{
public:

    using value_type = _Tp;
    using reference = _Tp&;
    using const_reference = const _Tp&;

    constexpr StaticModular(value_type __value = {}) noexcept
        : _M_value(residue(__value))
    { }

    constexpr value_type value() const noexcept
    { return _M_value; }

    static constexpr value_type modulus() noexcept
    { return _Modulus; }

    template<typename _Ty>
    static constexpr _Ty residue(_Ty __x) noexcept
    {
        if constexpr (std::is_unsigned_v<_Ty>)
        {
            return __x % modulus();
        }
        else
        {
            return (__x % modulus() + modulus()) % modulus();
        }
    }

    template<typename _Ty>
    constexpr StaticModular power(_Ty __x) const noexcept
    {
        StaticModular result(static_cast<value_type>(1));
        auto t = *this;

        for (; __x; t *= t, __x >>= 1)
        {
            (__x & 1) ? void(result *= t) : void();
        }

        return result;
    }

    constexpr StaticModular inverse() const noexcept
    {
        if constexpr (std::is_integral_v<value_type>)
        {
            assert(std::gcd(_M_value, modulus()) == 1);
        }

        auto extended_euclid = [&](const auto& self, auto a, decltype(a) b) -> std::array<decltype(a), 2>
        {
            if (b == 0)
            {
                return {1, 0};
            }

            auto [x, y] = self(self, b, a % b);
            return {{y, x - a / b * y}};
        };

        if constexpr (std::is_signed_v<value_type>)
        {
            return static_cast<value_type>(residue(extended_euclid(extended_euclid, _M_value, modulus())[0]));
        }
        else if constexpr (std::is_unsigned_v<value_type>)
        {
            return static_cast<value_type>(residue(extended_euclid(extended_euclid, std::make_signed_t<value_type>(_M_value), std::make_signed_t<value_type>(modulus()))[0]));
        }
        else
        {
            return static_cast<value_type>(residue(extended_euclid(extended_euclid, __int128_t(_M_value), __int128_t(modulus()))[0]));
        }
    }

    template<typename _Ty>
    constexpr _Ty cast() const noexcept
    { return static_cast<_Ty>(_M_value); }


    constexpr StaticModular& operator=(value_type __value) noexcept
    { _M_value = residue(__value); return *this; }

    constexpr operator value_type() const noexcept
    { return _M_value; }

    constexpr std::strong_ordering operator<=>(value_type __x) const noexcept
    { return _M_value <=> __x; }

    constexpr std::strong_ordering operator<=>(StaticModular __other) const noexcept
    { return _M_value <=> __other._M_value; }

    constexpr reference operator*() noexcept
    { return _M_value; }
    
    constexpr const_reference operator*() const noexcept
    { return _M_value; }

    constexpr bool operator!() const noexcept
    { return !_M_value; }

    constexpr StaticModular operator~() const noexcept
    { return ~_M_value; }

    constexpr StaticModular operator+() const noexcept
    { return +_M_value; }

    constexpr StaticModular operator-() const noexcept
    { return -_M_value; }

    constexpr StaticModular& operator++() noexcept
    { _M_value = residue(++_M_value); return *this; }

    constexpr StaticModular& operator--() noexcept
    { _M_value -= 1; return *this; }

    constexpr StaticModular operator++(int) noexcept
    { auto t = *this; ++*this; return t; }

    constexpr StaticModular operator--(int) noexcept
    { auto t = *this; --*this; return t; }

    constexpr StaticModular operator+(value_type __x) const noexcept
    { return _M_value + residue(__x); }

    constexpr StaticModular operator-(value_type __x) const noexcept
    { return _M_value + modulus() - residue(__x); }
    
    constexpr StaticModular operator*(value_type __x) const noexcept
    { auto t = *this; t *= __x; return t; }

    constexpr StaticModular operator/(value_type __x) const noexcept
    { return *this * StaticModular(__x).inverse(); }

    constexpr StaticModular operator%(value_type __x) const noexcept
    { return _M_value % __x; }

    constexpr StaticModular& operator+=(value_type __x) noexcept
    { return *this = *this + __x; }
    
    constexpr StaticModular& operator-=(value_type __x) noexcept
    { return *this = *this - __x; }

    constexpr StaticModular& operator*=(value_type __x) noexcept
    {
        if constexpr (std::numeric_limits<value_type>::max() / modulus() >= modulus())
        {
            _M_value = residue(_M_value * residue(__x));
            return *this;
        }
#ifdef __GNUC__
        else if constexpr (sizeof(value_type) <= 8U)
        {
            _M_value = static_cast<value_type>(residue(static_cast<__uint128_t>(_M_value) * residue(__x)));
            return *this;
        }
#endif
        else
        {
            __x = residue(__x);
    
            StaticModular result;
    
            for (; __x; *this += *this, __x >>= 1)
            {
                (__x & 1) ? void(result += *this) : void();
            }
    
            return *this = result;
        }
    }

    constexpr StaticModular& operator/=(value_type __x) noexcept
    { return *this = *this / __x; }

    constexpr StaticModular& operator%=(value_type __x) noexcept
    { return *this = *this % __x; }

    constexpr StaticModular operator<<(value_type __x) const noexcept
    { return *this * StaticModular(2).power(__x); }

    constexpr StaticModular operator>>(value_type __x) const noexcept
    { return *this / StaticModular(2).power(__x); }

    constexpr StaticModular& operator<<=(value_type __x) noexcept
    { return *this *= StaticModular(2).power(__x); }

    constexpr StaticModular& operator>>=(value_type __x) noexcept
    { return *this /= StaticModular(2).power(__x); }

    constexpr StaticModular operator^(value_type __x) const noexcept
    { return _M_value ^ __x; }

    constexpr StaticModular operator&(value_type __x) const noexcept
    { return _M_value & __x; }

    constexpr StaticModular operator|(value_type __x) const noexcept
    { return _M_value | __x; }

    constexpr StaticModular& operator^=(value_type __x) noexcept
    { return *this = *this ^ __x; }

    constexpr StaticModular& operator&=(value_type __x) noexcept
    { return *this = *this & __x; }

    constexpr StaticModular& operator|=(value_type __x) noexcept
    { return *this = *this | __x; }

    friend inline std::istream& operator>>(std::istream& __is, StaticModular& __that) noexcept
    { auto& result = __is >> __that._M_value; __that._M_value = __that.residue(__that._M_value); return result; }

    friend inline std::ostream& operator<<(std::ostream& __os, const StaticModular& __that) noexcept
    { return __os << __that._M_value; }

private:

    value_type _M_value;
};
}

inline namespace huanhuanonly
{
// Fenwick Tree
template<typename _Tp>
class BinaryIndexedTree
{
public:

    using value_type = _Tp;

    constexpr BinaryIndexedTree() noexcept = default;

    explicit constexpr BinaryIndexedTree(std::size_t __size) noexcept
        : _M_BITree(__size + 1)
    { }

    [[nodiscard]] static constexpr std::size_t lowbit(std::size_t __x) noexcept
    { return __x & -__x; }

    constexpr void add(std::size_t __i, value_type __value = 1)
    {
        for (++__i; __i < _M_BITree.size(); __i += lowbit(__i))
        {
            _M_BITree[__i] += __value;
        }
    }

    constexpr void subtract(std::size_t __i, value_type __value = 1)
    {
        for (++__i; __i < _M_BITree.size(); __i += lowbit(__i))
        {
            _M_BITree[__i] -= __value;
        }
    }

    [[nodiscard]] constexpr value_type sum(std::size_t __l)
    {
        value_type result{};

        for (++__l; __l; __l -= lowbit(__l))
        {
            result += _M_BITree[__l];
        }

        return result;
    }

    [[nodiscard]] constexpr value_type sum(std::size_t __l, std::size_t __r)
    { return __l ? sum(__r) - sum(__l - 1) : sum(__r); }

    [[nodiscard]] constexpr value_type get(std::size_t __i)
    { return sum(__i, __i); }

    constexpr value_type set(std::size_t __i, value_type __value)
    {
        value_type prev = get(__i);

        prev < __value ? add(__i, __value - prev) : subtract(__i, prev - __value);

        return prev;
    }

    constexpr void reset(std::size_t __size = static_cast<std::size_t>(-1))
    { __size == static_cast<std::size_t>(-1) ? std::ranges::fill(_M_BITree, value_type{}) : _M_BITree.assign(__size + 1, value_type{}); }

private:

    std::vector<value_type> _M_BITree;
};
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

        constexpr uint64 mod = 1e9 + 7;

        using mint64 = StaticModular<uint64, mod>;

        std::vector row(n + 1, BinaryIndexedTree<mint64>(n + 1));
        std::vector col(n + 1, BinaryIndexedTree<mint64>(n + 1));

        row[0].set(0, 1);
        col[0].set(0, 1);

        for (int i = 1; i <= n; ++i)
        {
            struct item
            {
                int i, j;
                mint64 add;
            };

            std::vector<item> que;

            for (int smax = 0; smax <= v[i]; ++smax)
            {
                que.push_back(item{
                    .i = v[i],
                    .j = smax,
                    .add = col[smax].sum(smax, v[i])
                });
            }

            for (int fmax = v[i] + 1; fmax <= n; ++fmax)
            {
                que.push_back(item{
                    .i = fmax,
                    .j = v[i],
                    .add = row[fmax].sum(0, v[i])
                });
            }

            for (const auto& [i, j, add] : que)
            {
                row[i].add(j, add);
                col[j].add(i, add);
            }
        }

        mint64 sum = 0;

        for (int fmax = 0; fmax <= n; ++fmax)
        {
            sum += row[fmax].sum(0, n);
        }

        std::cout << sum << '\n';
    }

    return 0;
}