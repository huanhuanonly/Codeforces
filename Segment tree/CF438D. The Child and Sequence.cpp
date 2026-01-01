/**
 * Codeforces Round 250 (Div. 1)
 * 
 * => D. The Child and Sequence ( @c 2300 )
 * 
 * -> https://codeforces.com/contest/438/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/438/submission/343466844 By huanhuanonly
 * 
 * @b Segment-tree
 * 
 * ----October 13, 2025 [13h:21m:26s]----
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
template<typename _ValueType, typename _MergeFunc = std::plus<_ValueType>>
class SegmentTree
{
public:

    using value_type = _ValueType;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = int;

    constexpr explicit SegmentTree(size_type __n = 0)
        : tree(nodes_count(__n))
    { }

    constexpr SegmentTree(size_type __n, _MergeFunc __merge)
        : tree(nodes_count(__n)), merge(__merge)
    { }

    constexpr SegmentTree(size_type __n, const value_type& __value)
        : SegmentTree(__n)
    { set(__value); }

    constexpr SegmentTree(size_type __n, const value_type& __value, _MergeFunc __merge)
        : tree(nodes_count(__n)), merge(__merge)
    { set(__value); }

    template<typename _Container, typename = std::void_t<decltype(std::declval<_Container>().size()), decltype(std::declval<_Container>().begin())>>
    constexpr SegmentTree(const _Container& __c)
        : SegmentTree(static_cast<size_type>(std::size(__c)))
    { build(std::begin(__c)); }

    template<typename _Container, typename = std::void_t<decltype(std::declval<_Container>().size()), decltype(std::declval<_Container>().begin())>>
    constexpr SegmentTree(const _Container& __c, _MergeFunc __merge)
        : tree(nodes_count(static_cast<size_type>(std::size(__c)))), merge(__merge)
    { build(std::begin(__c)); }

    template<typename _ForwardIterator>
    constexpr SegmentTree(_ForwardIterator __first, _ForwardIterator __last)
        : SegmentTree(static_cast<size_type>(std::distance(__first, __last)))
    { build(__first, __last); }

    template<typename _ForwardIterator>
    constexpr SegmentTree(_ForwardIterator __first, _ForwardIterator __last, _MergeFunc __merge)
        : tree(nodes_count(static_cast<size_type>(std::distance(__first, __last)))), merge(__merge)
    { build(__first, __last); }

    [[nodiscard]] static constexpr size_type nodes_count(size_type __n) noexcept
    { return __n << 2; }

    [[nodiscard]] constexpr size_type nodes_count() const noexcept
    { return tree.size(); }

    [[nodiscard]] constexpr size_type size() const noexcept
    { return static_cast<size_type>(tree.size()) >> 2; }

    constexpr void resize(size_type __n)
    { tree.resize(nodes_count(__n)); }

    
    template<typename _Callback>
    constexpr void for_each(int __l, int __r, _Callback __func)
    { _M_for_each(1, 1, size(), __l + 1, __r + 1, __func, [](const value_type&) -> bool { return true; }); }
    
    template<typename _Callback, typename _CheckFunc>
    constexpr void for_each(int __l, int __r, _Callback __func, _CheckFunc __check)
    { _M_for_each(1, 1, size(), __l + 1, __r + 1, __func, __check); }
    
    template<typename _Callback>
    constexpr void for_each(_Callback __func)
    { for_each(0, size() - 1, __func); }
    
    template<typename _Callback, typename _CheckFunc>
    constexpr void for_each(_Callback __func, _CheckFunc __check)
    { for_each(0, size() - 1, __func, __check); }


    template<typename _ForwardIterator>
    constexpr void build(_ForwardIterator __first)
    { build(0, size() - 1, __first); }

    template<typename _ForwardIterator>
    constexpr void build(int __l, int __r, _ForwardIterator __first)
    { for_each(__l, __r, [&](value_type& __v) -> bool { __v = *__first; ++__first; return true; }); }

    template<typename _ForwardIterator>
    constexpr void build(_ForwardIterator __first, _ForwardIterator __last)
    { build(0, __first, __last); }
    
    template<typename _ForwardIterator>
    constexpr void build(int __l, _ForwardIterator __first, _ForwardIterator __last)
    { if (__first != __last) { for_each(__l, size() - 1, [&](value_type& __v) -> bool { __v = *__first; return ++__first != __last; }); } }


    template<typename _ForwardIterator>
    constexpr void flatten(_ForwardIterator __first, size_type __n = std::numeric_limits<size_type>::max())
    { if (__n) { for_each(0, __n - 1, [&](const value_type& __v) -> bool { *__first = __v; ++__first; return true; }); } }
    
    template<typename _ForwardIterator>
    constexpr void flatten(int __l, int __r, _ForwardIterator __first)
    { for_each(__l, __r, [&](const value_type& __v) -> bool { *__first = __v; ++__first; return true; }); }

    template<typename _ForwardIterator>
    constexpr void flatten(_ForwardIterator __first, _ForwardIterator __last)
    { flatten(0, __first, __last); }
    
    template<typename _ForwardIterator>
    constexpr void flatten(int __l, _ForwardIterator __first, _ForwardIterator __last)
    { if (__first != __last) { for_each(__l, size() - 1, [&](const value_type& __v) -> bool { *__first = __v; return ++__first != __last; }); } }


    [[nodiscard]] constexpr value_type reduce(int __l, int __r)
    { return _M_reduce(1, 1, size(), __l + 1, __r + 1); }

    [[nodiscard]] constexpr value_type reduce()
    { return reduce(0, size() - 1); }

    [[nodiscard]] constexpr const_reference at(int __p)
    { return _M_at(1, 1, size(), __p + 1); }

    [[nodiscard]] constexpr const_reference operator[](int __p)
    { return at(__p); }

    [[nodiscard]] constexpr value_type operator[](const std::pair<int, int>& __p)
    { return reduce(__p.first, __p.second); }

    template<typename _Tp = value_type>
    constexpr void set(const _Tp& __value)
    { set(0, size() - 1, __value); }

    template<typename _Tp, typename _BinaryOperation>
    constexpr void set(const _Tp& __value, _BinaryOperation __binary_op)
    { set(0, size() - 1, __value, __binary_op); }
    
    template<typename _Tp = value_type>
    constexpr void set(int __p, const _Tp& __value)
    { set(__p, __p, __value); }

    template<typename _Tp, typename _BinaryOperation>
    constexpr void set(int __p, const _Tp& __value, _BinaryOperation __binary_op)
    { set(__p, __p, __value, __binary_op); }
    
    template<typename _Tp = value_type>
    constexpr void set(int __l, int __r, const _Tp& __value)
    { for_each(__l, __r, [&](value_type& __v) -> bool { __v = __value; return true; }); }

    template<typename _Tp, typename _BinaryOperation>
    constexpr void set(int __l, int __r, const _Tp& __value, _BinaryOperation __binary_op)
    { for_each(__l, __r, [&](value_type& __v) -> bool { __v = __binary_op(__v, __value); return true; }); }


    constexpr void reset()
    { std::fill(tree.begin(), tree.end(), value_type{}); }

protected:

    [[nodiscard]] static constexpr int ls(int p) noexcept
    { return p << 1; }

    [[nodiscard]] static constexpr int rs(int p) noexcept
    { return p << 1 | 1; }

    constexpr void push_up(int p)
    { tree[p] = merge(tree[ls(p)], tree[rs(p)]); }

    virtual void push_down(int p, int l, int r)
    { }

    template<typename _Callback, typename _CheckFunc>
    constexpr bool _M_for_each(int p, int l, int r, int x, int y, _Callback&& __func, _CheckFunc&& __check)
    {
        if (not __check(tree[p]))
        {
            return true;
        }
        else if (l == r)
        {
            return __func(tree[p]);
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        bool continues = true;

        if (x <= mid)
        {
            continues = _M_for_each(ls(p), l, mid, x, y, __func, __check);
        }

        if (y > mid and continues)
        {
            continues = _M_for_each(rs(p), mid + 1, r, x, y, __func, __check);
        }

        push_up(p);

        return continues;
    }

    [[nodiscard]] constexpr value_type _M_reduce(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            return tree[p];
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        if (x <= mid and y > mid)
        {
            return merge(_M_reduce(ls(p), l, mid, x, y), _M_reduce(rs(p), mid + 1, r, x, y));
        }
        else if (x <= mid)
        {
            return _M_reduce(ls(p), l, mid, x, y);
        }
        else
        {
            return _M_reduce(rs(p), mid + 1, r, x, y);
        }
    }

    [[nodiscard]] constexpr const_reference _M_at(int p, int l, int r, int i)
    {
        if (l == r)
        {
            return tree[p];
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        if (i <= mid)
        {
            return _M_at(ls(p), l, mid, i);
        }
        else
        {
            return _M_at(rs(p), mid + 1, r, i);
        }
    }

    std::vector<value_type> tree;
    _MergeFunc merge{};
};

template<typename _Container>
SegmentTree(const _Container&) -> SegmentTree<typename _Container::value_type>;

template<typename _Container, typename _MergeFunc>
SegmentTree(const _Container&, _MergeFunc) -> SegmentTree<typename _Container::value_type, _MergeFunc>;

template<typename _ForwardIterator>
SegmentTree(_ForwardIterator, _ForwardIterator) -> SegmentTree<decltype(*std::declval<_ForwardIterator>())>;

template<typename _ForwardIterator, typename _MergeFunc>
SegmentTree(_ForwardIterator, _ForwardIterator, _MergeFunc) -> SegmentTree<decltype(*std::declval<_ForwardIterator>()), _MergeFunc>;
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

    std::vector<uint64> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    struct node
    {
        uint64 sum, max;

        node operator+(const node& other) const noexcept
        {
            return {sum + other.sum, std::max(max, other.max)};
        }
    };

    SegmentTree<node> seg(n + 1);

    seg.for_each([&v, i = 0](node& nd) mutable -> bool
    {
        nd.sum = nd.max = v[i++];
        return true;
    });

    while (m--)
    {
        int opt;
        std::cin >> opt;

        if (opt == 1)
        {
            int l, r;
            std::cin >> l >> r;

            std::cout << seg.reduce(l, r).sum << '\n';
        }
        else if (opt == 2)
        {
            int l, r;
            uint64 x;

            std::cin >> l >> r >> x;

            seg.for_each(l, r, [x](node& nd) -> bool
            {
                nd.sum %= x;
                nd.max %= x;

                return true;
            },
            [x](const node& nd) -> bool
            {
                return nd.max >= x;
            });
        }
        else
        {
            int k;
            uint64 x;

            std::cin >> k >> x;

            seg.set(k, node{x, x});
        }
    }

    return 0;
}