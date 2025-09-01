/**
 * AtCoder Beginner Contest 417
 * 
 * => F - Random Gathering ( @c 500 )
 * 
 * -> https://atcoder.jp/contests/abc417/tasks/abc417_f
 * 
 * Submissions ~> https://atcoder.jp/contests/abc417/submissions/68209574 By huanhuanonly
 * 
 * @b Probability-theory and @b Lazy-segment-tree
 * 
 * ----August 04, 2025 [13h:27m:28s]----
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
template<std::integral _Tp, _Tp _Modulus>
class Modular
{
public:

    using value_type = _Tp;
    using reference = _Tp&;
    using const_reference = const _Tp&;

    constexpr Modular(value_type __value = {}) noexcept
        : _M_value(residue(__value))
    { }

    constexpr value_type value() const noexcept
    { return _M_value; }

    static constexpr value_type modulus() noexcept
    { return _Modulus; }

    static constexpr value_type residue(value_type __x) noexcept
    {
        if constexpr (std::is_unsigned_v<value_type>)
        {
            return __x % modulus();
        }
        else
        {
            return (__x % modulus() + modulus()) % modulus();
        }
    }

    constexpr Modular power(value_type __x) const noexcept
    {
        Modular result(static_cast<value_type>(1));
        auto t = *this;

        for (; __x; t *= t, __x >>= 1)
        {
            (__x & 1) ? void(result *= t) : void();
        }

        return result;
    }

    constexpr Modular inverse() const noexcept
    {
        static_assert (modulus() > 2);
        return power(modulus() - 2);
    }

    template<typename _Ty>
    constexpr _Ty cast() const noexcept
    { return static_cast<_Ty>(_M_value); }


    constexpr Modular& operator=(value_type __value) noexcept
    { _M_value = residue(__value); return *this; }

    constexpr operator bool() const noexcept
    { return static_cast<bool>(_M_value); }

    constexpr operator value_type() const noexcept
    { return _M_value; }

    constexpr std::strong_ordering operator<=>(value_type __x) const noexcept
    { return _M_value <=> __x; }

    constexpr std::strong_ordering operator<=>(Modular __other) const noexcept
    { return _M_value <=> __other._M_value; }

    constexpr reference operator*() noexcept
    { return _M_value; }
    
    constexpr const_reference operator*() const noexcept
    { return _M_value; }

    constexpr bool operator!() const noexcept
    { return !_M_value; }

    constexpr Modular operator~() const noexcept
    { return ~_M_value; }

    constexpr Modular operator+() const noexcept
    { return +_M_value; }

    constexpr Modular operator-() const noexcept
    { return -_M_value; }

    constexpr Modular& operator++() noexcept
    { _M_value = residue(++_M_value); return *this; }

    constexpr Modular& operator--() noexcept
    { _M_value = residue(--_M_value); return *this; }

    constexpr Modular operator++(int) noexcept
    { auto t = *this; ++*this; return t; }

    constexpr Modular operator--(int) noexcept
    { auto t = *this; --*this; return t; }

    constexpr Modular operator+(value_type __x) const noexcept
    { return _M_value + residue(__x); }

    constexpr Modular operator-(value_type __x) const noexcept
    { return _M_value - residue(__x); }
    
    constexpr Modular operator*(value_type __x) const noexcept
    { auto t = *this; t *= __x; return t; }

    constexpr Modular operator/(value_type __x) const noexcept
    { return *this * Modular(__x).inverse(); }

    constexpr Modular operator%(value_type __x) const noexcept
    { return _M_value % __x; }

    constexpr Modular& operator+=(value_type __x) noexcept
    { return *this = *this + __x; }
    
    constexpr Modular& operator-=(value_type __x) noexcept
    { return *this = *this - __x; }

    constexpr Modular& operator*=(value_type __x) noexcept
    {
        if constexpr (std::numeric_limits<value_type>::max() / modulus() >= modulus())
        {
            _M_value = residue(_M_value * residue(__x));
            return *this;
        }
        else
        {
            __x = residue(__x);
    
            Modular result;
    
            for (; __x; *this += *this, __x >>= 1)
            {
                (__x & 1) ? void(result += *this) : void();
            }
    
            return *this = result;
        }
    }

    constexpr Modular& operator/=(value_type __x) noexcept
    { return *this = *this / __x; }

    constexpr Modular& operator%=(value_type __x) noexcept
    { return *this = *this % __x; }

    constexpr Modular operator<<(value_type __x) const noexcept
    { return *this * Modular(2).power(__x); }

    constexpr Modular operator>>(value_type __x) const noexcept
    { return *this / Modular(2).power(__x); }

    constexpr Modular& operator<<=(value_type __x) noexcept
    { return *this *= Modular(2).power(__x); }

    constexpr Modular& operator>>=(value_type __x) noexcept
    { return *this /= Modular(2).power(__x); }

    constexpr Modular operator^(value_type __x) const noexcept
    { return _M_value ^ __x; }

    constexpr Modular operator&(value_type __x) const noexcept
    { return _M_value & __x; }

    constexpr Modular operator|(value_type __x) const noexcept
    { return _M_value | __x; }

    constexpr Modular& operator^=(value_type __x) noexcept
    { return *this = *this ^ __x; }

    constexpr Modular& operator&=(value_type __x) noexcept
    { return *this = *this & __x; }

    constexpr Modular& operator|=(value_type __x) noexcept
    { return *this = *this | __x; }

    friend inline std::istream& operator>>(std::istream& __is, Modular& __that) noexcept
    { auto& result = __is >> __that._M_value; __that._M_value = __that.residue(__that._M_value); return result; }

    friend inline std::ostream& operator<<(std::ostream& __os, const Modular& __that) noexcept
    { return __os << __that._M_value; }

private:

    value_type _M_value;
};
}

inline namespace huanhuanonly
{
template<typename _ValueType>
class SegmentTree
{
public:

    using value_type = _ValueType;

    explicit SegmentTree(std::size_t __n)
            : tree(__n << 2)
    { }

    template<typename _MergeFunc>
    SegmentTree(std::size_t __n, _MergeFunc __func)
            : tree(__n << 2), merge(__func)
    { }

    SegmentTree(std::size_t __n, const value_type& __value)
            : tree(__n << 2, __value)
    { }

    template<typename _MergeFunc>
    SegmentTree(std::size_t __n, const value_type& __value, _MergeFunc __func)
            : tree(__n << 2, __value), merge(__func)
    { }

    template<typename _Container, typename = std::void_t<decltype(std::declval<_Container>().size()), decltype(std::declval<_Container>().begin())>>
    SegmentTree(const _Container& __c)
            : tree(std::size(__c) << 2)
    { build(std::begin(__c)); }

    template<typename _Container, typename _MergeFunc, typename = std::void_t<decltype(std::declval<_Container>().size()), decltype(std::declval<_Container>().begin())>>
    SegmentTree(const _Container& __c, _MergeFunc __func)
            : tree(std::size(__c) << 2), merge(__func)
    { build(std::begin(__c)); }


    constexpr int size() const noexcept
    { return static_cast<int>(tree.size()) >> 2; }
    
    template<typename _ForwardIterator>
    void build(_ForwardIterator __first)
    { _M_build(1, 1, static_cast<int>(size()), __first); }

    template<typename _ForwardIterator>
    void to_vector(_ForwardIterator __first)
    { _M_to_vector(1, 1, size(), __first); }

    value_type sum(int __l, int __r)
    { return _M_sum(1, 1, size(), __l + 1, __r + 1); }

    value_type sum(int __p)
    { return sum(__p, __p); }

    const value_type& at(int __p)
    { return _M_at(1, 1, size(), __p + 1); }

    const value_type& operator[](int __p)
    { return at(__p); }

    template<typename _Tp>
    void set(int __p, const _Tp& __value = value_type{})
    {
        _M_set(1, 1, size(), __p + 1, __value,
            [](const value_type& [[maybe_unused]] __self, const _Tp& __value) {
                return __value;
            });
    }

    template<typename _Tp, typename _BinaryOperation>
    void set(int __p, const _Tp& __value, _BinaryOperation __binary_op)
    { _M_set(1, 1, size(), __p + 1, __value, __binary_op); }

protected:

    static constexpr int ls(int p) noexcept
    { return p << 1; }

    static constexpr int rs(int p) noexcept
    { return p << 1 | 1; }

    void push_up(int p)
    { tree[p] = merge(tree[ls(p)], tree[rs(p)]); }

    virtual void push_down(int p, int l, int r)
    { }

    template<typename _ForwardIterator>
    void _M_build(int p, int l, int r, _ForwardIterator& it)
    {
        if (l == r)
        {
            tree[p] = *it;
            ++it;

            return;
        }

        int mid = l + r >> 1;

        _M_build(ls(p), l, mid, it);
        _M_build(rs(p), mid + 1, r, it);

        push_up(p);
    }

    template<typename _ForwardIterator>
    void _M_to_vector(int p, int l, int r, _ForwardIterator& it)
    {
        if (l == r)
        {
            *it = tree[p];
            ++it;

            return;
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        _M_to_vector(ls(p), l, mid, it);
        _M_to_vector(rs(p), mid + 1, r, it);
    }

    value_type _M_sum(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            return tree[p];
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        if (x <= mid and y > mid)
            return merge(_M_sum(ls(p), l, mid, x, y), _M_sum(rs(p), mid + 1, r, x, y));
        else if (x <= mid)
            return _M_sum(ls(p), l, mid, x, y);
        else
            return _M_sum(rs(p), mid + 1, r, x, y);
    }

    const value_type& _M_at(int p, int l, int r, int i)
    {
        if (l == r)
        {
            return tree[p];
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        if (i <= mid)
            return _M_at(ls(p), l, mid, i);
        else
            return _M_at(rs(p), mid + 1, r, i);
    }

    template<typename _Tp, typename _BinaryOperation>
    void _M_set(int p, int l, int r, int i, const _Tp& v, const _BinaryOperation& bop)
    {
        if (l == r)
        {
            tree[p] = bop(tree[p], v);
            return;
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        if (i <= mid)
            _M_set(ls(p), l, mid, i, v, bop);
        else
            _M_set(rs(p), mid + 1, r, i, v, bop);

        push_up(p);
    }

    std::vector<value_type> tree;
    std::function<value_type(const value_type&, const value_type&)> merge = std::plus();
};

template<typename _Tp>
SegmentTree(std::size_t, const _Tp&) -> SegmentTree<_Tp>;

template<typename _Container>
SegmentTree(const _Container&) -> SegmentTree<typename _Container::value_type>;
}

inline namespace huanhuanonly
{
template<typename _ValueType, typename _LazyType = _ValueType>
class LazySegmentTree : public SegmentTree<_ValueType>
{
public:
    using value_type = _ValueType;
    using lazy_type  = _LazyType;

    using SegmentTree<_ValueType>::ls;
    using SegmentTree<_ValueType>::rs;
    
    using SegmentTree<_ValueType>::size;

    using SegmentTree<_ValueType>::push_up;

    using SegmentTree<_ValueType>::tree;

    template<typename... _Args>
    explicit LazySegmentTree(_Args&&... __args)
        : SegmentTree<_ValueType>(std::forward<_Args>(__args)...)
        , lazy(tree.size())
    { }

    void set_interval(int __l, int __r, const value_type& __value)
    { _M_set_interval(1, 1, size(), __l + 1, __r + 1, __value); }
    
protected:
    
    void add_lazy(int p, int l, int r, const value_type& v)
    {
        lazy[p] = v;
        tree[p] = v * (r - l + 1);
    }

    void push_down(int p, int l, int r) override
    {
        if (lazy[p])
        {
            int mid = (l + r) >> 1;

            add_lazy(ls(p), l, mid, lazy[p]);
            add_lazy(rs(p), mid + 1, r, lazy[p]);
            
            lazy[p] = lazy_type{};
        }
    }

    void _M_set_interval(int p, int l, int r, int x, int y, const value_type& v)
    {
        if (x <= l and r <= y)
        {
            add_lazy(p, l, r, v);
            return;
        }

        push_down(p, l, r);

        int mid = (l + r) >> 1;

        if (x <= mid)
            _M_set_interval(ls(p), l, mid, x, y, v);
        if (y > mid)
            _M_set_interval(rs(p), mid + 1, r, x, y, v);
        
        push_up(p);
    }

protected:

    std::vector<lazy_type> lazy;
};

template<typename _Tp>
LazySegmentTree(std::size_t, const _Tp&) -> LazySegmentTree<_Tp>;

template<typename _Container>
LazySegmentTree(const _Container&) -> LazySegmentTree<typename _Container::value_type>;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;

    constexpr uint64 mod = 998244353;

    std::vector<Modular<uint64, mod>> v(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    LazySegmentTree seg(v);

    while (m--)
    {
        int l, r;
        std::cin >> l >> r;

        --l, --r;

        seg.set_interval(l, r, seg.sum(l, r) / (r - l + 1));
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << seg[i] << ' ';
    }

    return 0;
}