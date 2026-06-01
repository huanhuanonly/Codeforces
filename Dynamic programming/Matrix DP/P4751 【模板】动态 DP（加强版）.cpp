/**
 * => P4751 【模板】动态 DP（加强版） ( @c 省选/NOI- )
 *
 * -> https://www.luogu.com.cn/problem/P4751
 *
 * Submissions ~> https://www.luogu.com.cn/record/276953521 By huanhuanonly
 *
 * @b Matrix-DP ( @a semiring-matrix-multiplication @a (max,plus) )
 * @b Dynamic-DP
 * @b Tree-DP
 * @b Segment-tree
 * @b Heavy-Light-decomposition on @a Trees
 *
 * ----May 07, 2026 [09h:10m:19s]----
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
    inline namespace data_structure
{
template<typename _ValueType, typename _MergeFunc = std::plus<_ValueType>>
class SegmentTree
{
public:

    using container_type = std::vector<std::conditional_t<std::is_same_v<_ValueType, bool>, std::uint8_t, _ValueType>>;

    using value_type = container_type::value_type;
    using reference = container_type::reference;
    using const_reference = container_type::const_reference;
    using size_type = std::size_t;

    constexpr explicit
    SegmentTree(size_type __n = 0, _MergeFunc __merge = {}) noexcept
        : tree(nodes_count(__n)), merge(__merge)
    { }

    template<std::input_iterator _Iter, std::sentinel_for<_Iter> _Sent, typename _Proj = std::identity>
    constexpr
    SegmentTree(_Iter __first, _Sent __last, _Proj __proj = {}, _MergeFunc __merge = {}) noexcept
        : tree(nodes_count(static_cast<size_type>(std::ranges::distance(__first, __last)))), merge(__merge)
    { build(__first, __last, __proj); }

    template<std::ranges::input_range _Range, typename _Proj = std::identity>
    constexpr
    SegmentTree(_Range&& __r, _Proj __proj = {}, _MergeFunc __merge = {}) noexcept
        : SegmentTree(std::ranges::begin(__r), std::ranges::end(__r), __proj, __merge)
    { }

    constexpr
    SegmentTree(std::initializer_list<_ValueType> __list) noexcept
        : SegmentTree(__list.begin(), __list.end())
    { }


    [[nodiscard]] static constexpr size_type
    nodes_count(size_type __n) noexcept
    { return __n << 2; }

    [[nodiscard]] constexpr size_type
    nodes_count() const noexcept
    { return tree.size(); }

    [[nodiscard]] constexpr size_type
    size() const noexcept
    { return static_cast<size_type>(tree.size()) >> 2; }

    [[nodiscard]] constexpr bool
    empty() const noexcept
    { return size() == 0; }

    constexpr void
    resize(size_type __n)
    { tree.resize(nodes_count(__n)); }


    template<typename _Callback>
    requires std::invocable<_Callback, reference>
    constexpr void
    for_each(size_type __l, size_type __r, _Callback __func)
    { _M_for_each(1, 1, size(), __l + 1, __r + 1, __func); }

    template<typename _Callback>
    requires std::invocable<_Callback, reference>
    constexpr void
    for_each(_Callback __func)
    { empty() ? void() : for_each(0, size() - 1, __func); }

    template<typename _Callback>
    requires std::invocable<_Callback, reference>
    constexpr void
    for_each_segment(size_type __l, size_type __r, _Callback __func)
    { _M_for_each_segment(1, 1, size(), __l + 1, __r + 1, __func); }

    template<typename _Callback>
    requires std::invocable<_Callback, reference>
    constexpr void
    for_each_segment(_Callback __func)
    { empty() ? void() : for_each_segment(0, size() - 1, __func); }


    template<std::input_iterator _Iter, std::sentinel_for<_Iter> _Sent, typename _Proj = std::identity>
    requires std::assignable_from<value_type&, std::invoke_result_t<_Proj, std::iter_reference_t<_Iter>>>
    constexpr void
    build(size_type __l, size_type __r, _Iter __first, _Sent __last, _Proj __proj = {})
    {
        if (__first != __last)
        {
            for_each(__l, __r, [&](reference __ref) -> bool
            {
                __ref = std::invoke(__proj, *__first);
                return ++__first != __last;
            });
        }
    }

    template<std::ranges::input_range _Range, typename _Proj = std::identity>
    requires std::assignable_from<reference, std::invoke_result_t<_Proj, std::ranges::range_reference_t<_Range>>>
    constexpr void
    build(size_type __l, size_type __r, _Range&& __range, _Proj __proj = {})
    { build(__l, __r, std::ranges::begin(__range), std::ranges::end(__range), __proj); }

    template<std::input_iterator _Iter, std::sentinel_for<_Iter> _Sent, typename _Proj = std::identity>
    requires std::assignable_from<reference, std::invoke_result_t<_Proj, std::iter_reference_t<_Iter>>>
    constexpr void
    build(_Iter __first, _Sent __last, _Proj __proj = {})
    { empty() ? void() : build(0, size() - 1, __first, __last, __proj); }

    template<std::ranges::input_range _Range, typename _Proj = std::identity>
    requires std::assignable_from<reference, std::invoke_result_t<_Proj, std::ranges::range_reference_t<_Range>>>
    constexpr void
    build(_Range&& __range, _Proj __proj = {})
    { build(std::ranges::begin(__range), std::ranges::end(__range), __proj); }


    template<typename _Iter, typename _Proj = std::identity>
    requires std::output_iterator<_Iter, std::invoke_result_t<_Proj, const_reference>>
    constexpr void
    flatten(size_type __l, size_type __r, _Iter __first, _Proj __proj = {})
    { for_each(__l, __r, [&](const_reference __ref) -> bool { *__first = std::invoke(__proj, __ref); ++__first; return true; }); }


    [[nodiscard]] constexpr value_type
    reduce(size_type __l, size_type __r)
    { return _M_reduce(1, 1, size(), __l + 1, __r + 1); }

    [[nodiscard]] constexpr value_type
    reduce()
    { return empty() ? value_type{} : reduce(0, size() - 1); }

    [[nodiscard]] constexpr const_reference
    at(size_type __p)
    { return _M_at(1, 1, size(), __p + 1); }

    [[nodiscard]] constexpr const_reference
    operator[](size_type __p)
    { return at(__p); }

    [[nodiscard]] constexpr value_type
    operator[](const std::pair<size_type, size_type>& __p)
    { return reduce(__p.first, __p.second); }

    struct recursion_info_probe
    {
        size_type l, r;

        [[nodiscard]] constexpr bool
        is_leaf() const noexcept;

        [[nodiscard]] constexpr size_type
        size() const noexcept;

        [[nodiscard]] constexpr reference
        left_value() const noexcept;

        [[nodiscard]] constexpr reference
        right_value() const noexcept;

        struct return_placeholder
        {
            template<typename _Tp>
            constexpr operator _Tp() const noexcept;
        };

        template<typename... _Args>
        [[nodiscard]] constexpr return_placeholder
        to_left(_Args&&...) const noexcept;

        template<typename... _Args>
        [[nodiscard]] constexpr return_placeholder
        to_right(_Args&&...) const noexcept;
    };

    template<typename _Func, typename _Func1, typename _Func2, typename... _Args>
    struct recursion_info
    {
    private: size_type p;
    public:  size_type l, r;

    private:

        struct callbacks
        {
            _Func  func;
            _Func1 ln_value;
            _Func2 rn_value;
        };

        const callbacks& cb_refs;

        constexpr
        recursion_info(size_type p, size_type l, size_type r, const callbacks& cb_refs) noexcept
            : p(p), l(l), r(r), cb_refs(cb_refs)
        { }

    public:

        friend class SegmentTree;

        [[nodiscard]] constexpr bool
        is_leaf() const noexcept
        { return l == r; }

        [[nodiscard]] constexpr size_type
        size() const noexcept
        { return r - l + 1; }

        [[nodiscard]] constexpr reference
        left_value() const noexcept
        { return cb_refs.ln_value(*this); }

        [[nodiscard]] constexpr reference
        right_value() const noexcept
        { return cb_refs.rn_value(*this); }

        constexpr decltype(auto)
        to_left(_Args&&... __args) const noexcept
        {
            const size_type mid = (l + r) >> 1;
            return cb_refs.func(recursion_info(ls(p), l, mid, cb_refs), std::forward<_Args>(__args)...);
        }

        constexpr decltype(auto)
        to_right(_Args&&... __args) const noexcept
        {
            const size_type mid = (l + r) >> 1;
            return cb_refs.func(recursion_info(rs(p), mid + 1, r, cb_refs), std::forward<_Args>(__args)...);
        }
    };

    template<typename _Callback, typename... _Args>
    constexpr decltype(auto)
    recurse(_Callback __callback, _Args&&... __args)
    {
        using return_value_t = std::remove_cvref_t<std::invoke_result_t<_Callback, recursion_info_probe, reference, _Args...>>;

        auto func = [this, &__callback](const auto& info, _Args&&... args) -> return_value_t
        {
            if constexpr (std::is_void_v<return_value_t>)
            {
                push_down(info.p, info.l, info.r);
                __callback(info, tree[info.p], std::forward<_Args>(args)...);
                push_up(info.p);
            }
            else
            {
                push_down(info.p, info.l, info.r);
                auto&& ret = __callback(info, tree[info.p], std::forward<_Args>(args)...);
                push_up(info.p);
                return ret;
            }
        };

        auto ln_value = [this](const auto& info) -> reference
        {
            const size_type mid = (info.l + info.r) >> 1;
            push_down(ls(info.p), info.l, mid);
            return tree[ls(info.p)];
        };

        auto rn_value = [this](const auto& info) -> reference
        {
            const size_type mid = (info.l + info.r) >> 1;
            push_down(rs(info.p), mid + 1, info.r);
            return tree[rs(info.p)];
        };

        recursion_info<decltype(func), decltype(ln_value), decltype(rn_value), _Args...> info(
            1, 0, size() - 1, {func, ln_value, rn_value});

        return func(info, std::forward<_Args>(__args)...);
    }


    [[nodiscard]] constexpr const_reference
    front()
    { return at(0); }

    [[nodiscard]] constexpr const_reference
    back()
    { return at(size() - 1); }


    template<typename _Tp, typename _Proj = std::identity>
    requires std::assignable_from<reference, std::invoke_result_t<_Proj, const _Tp&>>
    constexpr void
    set(size_type __l, size_type __r, const _Tp& __value, _Proj __proj = {})
    { for_each(__l, __r, [&](reference __ref) -> bool { __ref = std::invoke(__proj, __value); return true; }); }

    template<typename _Tp, typename _Proj = std::identity>
    requires std::assignable_from<reference, std::invoke_result_t<_Proj, const _Tp&>>
    constexpr void
    set(size_type __p, const _Tp& __value, _Proj __proj = {})
    { set(__p, __p, __value, __proj); }

    template<typename _Tp, typename _Proj = std::identity>
    requires std::assignable_from<reference, std::invoke_result_t<_Proj, const _Tp&>>
    constexpr void
    fill(const _Tp& __value, _Proj __proj = {})
    { empty() ? void() : set(0, size() - 1, __value, __proj); }

    constexpr void
    reset()
    { std::ranges::fill(tree, value_type{}); }

protected:

    [[nodiscard]] static constexpr size_type
    ls(size_type __p) noexcept
    { return __p << 1; }

    [[nodiscard]] static constexpr size_type
    rs(size_type __p) noexcept
    { return __p << 1 | 1; }

    constexpr void
    push_up(size_type __p)
    { tree[__p] = merge(tree[ls(__p)], tree[rs(__p)]); }

    virtual void
    push_down([[maybe_unused]] size_type __p, [[maybe_unused]] size_type __l, [[maybe_unused]] size_type __r)
    { }

private:

    template<typename _Callback>
    requires std::invocable<_Callback, reference>
    constexpr bool
    _M_for_each(size_type __p, size_type __l, size_type __r, size_type __x, size_type __y, _Callback&& __func)
    {
        if (__l == __r)
        {
            return __func(tree[__p]);
        }

        push_down(__p, __l, __r);

        const size_type mid = (__l + __r) >> 1;
        bool continues = true;

        if (__x <= mid)
        {
            continues = _M_for_each(ls(__p), __l, mid, __x, __y, std::forward<_Callback>(__func));
        }

        if (__y > mid and continues)
        {
            continues = _M_for_each(rs(__p), mid + 1, __r, __x, __y, std::forward<_Callback>(__func));
        }

        push_up(__p);

        return continues;
    }

    template<typename _Callback>
    requires std::invocable<_Callback, reference>
    constexpr bool
    _M_for_each_segment(size_type __p, size_type __l, size_type __r, size_type __x, size_type __y, _Callback&& __func)
    {
        if (__x <= __l and __r <= __y)
        {
            return __func(tree[__p]);
        }

        push_down(__p, __l, __r);

        const size_type mid = (__l + __r) >> 1;
        bool continues = true;

        if (__x <= mid)
        {
            continues = _M_for_each_segment(ls(__p), __l, mid, __x, __y, std::forward<_Callback>(__func));
        }

        if (__y > mid and continues)
        {
            continues = _M_for_each_segment(rs(__p), mid + 1, __r, __x, __y, std::forward<_Callback>(__func));
        }

        return continues;
    }

    [[nodiscard]] constexpr value_type
    _M_reduce(size_type __p, size_type __l, size_type __r, size_type __x, size_type __y)
    {
        if (__x <= __l and __r <= __y)
        {
            return tree[__p];
        }

        push_down(__p, __l, __r);

        const size_type mid = (__l + __r) >> 1;

        if (__x <= mid and __y > mid)
        {
            return merge(_M_reduce(ls(__p), __l, mid, __x, __y), _M_reduce(rs(__p), mid + 1, __r, __x, __y));
        }
        else if (__x <= mid)
        {
            return _M_reduce(ls(__p), __l, mid, __x, __y);
        }
        else
        {
            return _M_reduce(rs(__p), mid + 1, __r, __x, __y);
        }
    }

    [[nodiscard]] constexpr const_reference
    _M_at(size_type __p, size_type __l, size_type __r, size_type __i)
    {
        if (__l == __r)
        {
            return tree[__p];
        }

        push_down(__p, __l, __r);

        const size_type mid = (__l + __r) >> 1;

        if (__i <= mid)
        {
            return _M_at(ls(__p), __l, mid, __i);
        }
        else
        {
            return _M_at(rs(__p), mid + 1, __r, __i);
        }
    }

protected:

    container_type tree;
    _MergeFunc merge;
};

template<std::input_iterator _Iter, std::sentinel_for<_Iter> _Sent, typename _Proj = std::identity, typename _MergeFunc = std::plus<>>
SegmentTree(_Iter, _Sent, _Proj = {}, _MergeFunc = {}) -> SegmentTree<std::remove_reference_t<std::invoke_result_t<_Proj, std::iter_value_t<_Iter>>>, _MergeFunc>;

template<std::ranges::input_range _Range, typename _Proj = std::identity, typename _MergeFunc = std::plus<>>
SegmentTree(_Range&&, _Proj = {}, _MergeFunc = {}) -> SegmentTree<std::remove_reference_t<std::invoke_result_t<_Proj, std::ranges::range_value_t<_Range>>>, _MergeFunc>;
}} // namespace huanhuanonly::data_structure

inline namespace huanhuanonly {
    inline namespace math
{
template<typename _Tp, int _Ln, int _Cn, typename _DefaultVal = _Tp>
class Matrix
{
    static_assert(_Ln > 0 and _Cn > 0);

public:

    using value_type = _Tp;
    using reference = _Tp&;
    using const_reference = const _Tp&;
    using size_type = int;

    using container_type = std::array<std::array<value_type, _Cn>, _Ln>;

    constexpr
    Matrix() noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = default_value();
            }
        }
    }

    constexpr
    Matrix(const value_type& __value) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                if (i != j) [[likely]]
                {
                    _M_m[i][j] = default_value();
                }
                else [[unlikely]]
                {
                    _M_m[i][j] = __value;
                }
            }
        }
    }

    constexpr
    Matrix(std::initializer_list<std::initializer_list<_Tp>> __init) noexcept
    {
        assert(static_cast<std::size_t>(row()) == __init.size());

        auto lit = _M_m.begin();
        auto rit = __init.begin();

        for (; lit != _M_m.end(); ++lit, ++rit)
        {
            assert(static_cast<std::size_t>(column()) == rit->size());

            auto lit2 = lit->begin();
            auto rit2 = rit->begin();

            for (; lit2 != lit->end(); ++lit2, ++rit2)
            {
                *lit2 = *rit2;
            }
        }
    }

    template<std::convertible_to<_Tp> _Tp2, typename _DefaultVal2>
    constexpr
    Matrix(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __other) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = __other._M_m[i][j];
            }
        }
    }

    template<std::convertible_to<_Tp> _Tp2, typename _DefaultVal2>
    constexpr Matrix&
    operator=(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __other) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = __other._M_m[i][j];
            }
        }

        return *this;
    }

    template<std::convertible_to<_Tp> _Tp2, typename _DefaultVal2>
    constexpr
    Matrix(Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>&& __other) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = std::move(__other._M_m[i][j]);
            }
        }
    }

    template<std::convertible_to<_Tp> _Tp2, typename _DefaultVal2>
    constexpr Matrix&
    operator=(Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>&& __other) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = std::move(__other._M_m[i][j]);
            }
        }

        return *this;
    }
    static constexpr struct uninitialized_t { } uninitialized{};

    constexpr explicit
    Matrix(uninitialized_t) noexcept
    { }

    [[nodiscard]] static constexpr size_type
    row() noexcept
    { return _Ln; }

    [[nodiscard]] static constexpr size_type
    column() noexcept
    { return _Cn; }

    [[nodiscard]] static constexpr value_type
    default_value() noexcept
    { return static_cast<value_type>(_DefaultVal{}); }

    [[nodiscard]] constexpr container_type&
    data() noexcept
    { return _M_m; }

    [[nodiscard]] constexpr const container_type&
    data() const noexcept
    { return _M_m; }

    [[nodiscard]] constexpr reference
    at(size_type __i, size_type __j) noexcept
    { return _M_m[__i][__j]; }

    [[nodiscard]] constexpr const_reference
    at(size_type __i, size_type __j) const noexcept
    { return _M_m[__i][__j]; }

    [[nodiscard]] constexpr decltype(auto)
    operator[](size_type __i) noexcept
    { return _M_m[__i]; }

    [[nodiscard]] constexpr decltype(auto)
    operator[](size_type __i) const noexcept
    { return _M_m[__i]; }

    constexpr void
    fill(const value_type& __value) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = __value;
            }
        }
    }

    template<typename, size_type, size_type, typename>
    friend class Matrix;

    template<typename _UnaryOperation>
    requires requires(_UnaryOperation __op, _Tp __x) { __op(__x); }
    [[nodiscard]] constexpr auto
    elementwise_transform(_UnaryOperation __unary_op = {}) const noexcept
    {
        using unary_operation_result_t = std::remove_cvref_t<std::invoke_result_t<_UnaryOperation, _Tp>>;

        Matrix<unary_operation_result_t, _Ln, _Cn, _DefaultVal> result(uninitialized);

        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                result._M_m[i][j] = __unary_op(_M_m[i][j]);
            }
        }

        return result;
    }

    template<typename _UnaryOperation>
    requires requires(_UnaryOperation __op, _Tp __x) { { __op(__x) } -> std::convertible_to<_Tp>; }
    [[nodiscard]] constexpr Matrix&
    elementwise_transform_inplace(_UnaryOperation __unary_op = {}) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = __unary_op(_M_m[i][j]);
            }
        }

        return *this;
    }

    template<typename _BinaryOperation, typename _Tp2, typename _DefaultVal2>
    requires requires(_BinaryOperation __op, _Tp __lhs, _Tp2 __rhs) { __op(__lhs, __rhs); }
    [[nodiscard]] constexpr auto
    elementwise_transform(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __rhs, _BinaryOperation __binary_op = {}) const noexcept
    {
        using binary_operation_result_t = std::remove_cvref_t<std::invoke_result_t<_BinaryOperation, _Tp, _Tp2>>;
        using default_value_t =
            std::conditional_t<
                std::is_same_v<binary_operation_result_t, _Tp>,
                _DefaultVal,
                std::conditional_t<
                    std::is_same_v<binary_operation_result_t, _Tp2>,
                    _DefaultVal2,
                    binary_operation_result_t>>;

        Matrix<binary_operation_result_t, _Ln, _Cn, default_value_t> result(uninitialized);

        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                result._M_m[i][j] = __binary_op(_M_m[i][j], __rhs._M_m[i][j]);
            }
        }

        return result;
    }

    template<typename _BinaryOperation, typename _Tp2, typename _DefaultVal2>
    requires requires(_BinaryOperation __op, _Tp __lhs, _Tp2 __rhs) { { __op(__lhs, __rhs) } -> std::convertible_to<_Tp>; }
    constexpr Matrix&
    elementwise_transform_inplace(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __rhs, _BinaryOperation __binary_op = {}) noexcept
    {
        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type j = 0; j < column(); ++j)
            {
                _M_m[i][j] = __binary_op(_M_m[i][j], __rhs._M_m[i][j]);
            }
        }

        return *this;
    }

    template<typename _Tp2, typename _DefaultVal2>
    [[nodiscard]] constexpr auto
    operator+(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __rhs) const noexcept
    { return elementwise_transform(__rhs, std::plus{}); }

    template<typename _Tp2, typename _DefaultVal2>
    [[nodiscard]] constexpr auto
    operator-(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __rhs) const noexcept
    { return elementwise_transform(__rhs, std::minus{}); }

    template<typename _Tp2, typename _DefaultVal2>
    constexpr Matrix&
    operator+=(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __rhs) noexcept
    { return elementwise_transform_inplace(__rhs, std::plus{}); }

    template<typename _Tp2, typename _DefaultVal2>
    constexpr Matrix&
    operator-=(const Matrix<_Tp2, _Ln, _Cn, _DefaultVal2>& __rhs) noexcept
    { return elementwise_transform_inplace(__rhs, std::minus{}); }

    template<typename _BinaryOperation1, typename _BinaryOperation2, typename _Tp2, size_type _Cn2, typename _DefaultVal2>
    requires requires(_BinaryOperation2 __op2, _Tp __lhs, _Tp2 __rhs) { __op2(__lhs, __rhs); }
    [[nodiscard]] constexpr auto
    semiring_multiply(const Matrix<_Tp2, _Cn, _Cn2, _DefaultVal2>& __rhs, _BinaryOperation1 __binary_op1 = {}, _BinaryOperation2 __binary_op2 = {}) const noexcept
    {
        using binary_operation2_result_t = std::remove_cvref_t<std::invoke_result_t<_BinaryOperation2, _Tp, _Tp2>>;
        using binary_operation1_result_t = std::remove_cvref_t<std::invoke_result_t<_BinaryOperation1, binary_operation2_result_t, binary_operation2_result_t>>;

        static_assert(std::invocable<_BinaryOperation1, binary_operation2_result_t, binary_operation2_result_t>);
        static_assert(std::convertible_to<binary_operation1_result_t, binary_operation2_result_t>);

        using default_value_t = std::conditional_t<
            std::is_same_v<binary_operation2_result_t, _Tp>,
            _DefaultVal,
            std::conditional_t<
                std::is_same_v<binary_operation2_result_t, _Tp2>,
                _DefaultVal2,
                binary_operation2_result_t>>;

        Matrix<binary_operation2_result_t, _Ln, _Cn2, default_value_t> result{};

        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type k = 0; k < column(); ++k)
            {
                for (size_type j = 0; j < __rhs.column(); ++j)
                {
                    result._M_m[i][j] = __binary_op1(result._M_m[i][j], __binary_op2(_M_m[i][k], __rhs._M_m[k][j]));
                }
            }
        }

        return result;
    }

    template<typename _BinaryOperation1, typename _BinaryOperation2, typename _Tp2, typename _DefaultVal2>
    requires requires(_BinaryOperation2 __op2, _Tp __lhs, _Tp2 __rhs) { { __op2(__lhs, __rhs) } -> std::convertible_to<_Tp>; }
    constexpr Matrix&
    semiring_multiply_inplace(const Matrix<_Tp2, _Cn, _Cn, _DefaultVal2>& __rhs, _BinaryOperation1 __binary_op1 = {}, _BinaryOperation2 __binary_op2 = {}) noexcept
    {
        static_assert(requires(_BinaryOperation1 __op1, _Tp __x) { { __op1(__x, __x) } -> std::convertible_to<_Tp>; });

        Matrix result{};

        for (size_type i = 0; i < row(); ++i)
        {
            for (size_type k = 0; k < column(); ++k)
            {
                for (size_type j = 0; j < __rhs.column(); ++j)
                {
                    result._M_m[i][j] = __binary_op1(result._M_m[i][j], __binary_op2(_M_m[i][k], __rhs._M_m[k][j]));
                }
            }
        }

        return *this = std::move(result);
    }

    template<typename _Tp2, size_type _Cn2, typename _DefaultVal2>
    [[nodiscard]] constexpr auto
    operator*(const Matrix<_Tp2, _Cn, _Cn2, _DefaultVal2>& __rhs) const noexcept
    { return semiring_multiply(__rhs, std::plus{}, std::multiplies{}); }

    template<typename _Tp2, typename _DefaultVal2>
    constexpr Matrix&
    operator*=(const Matrix<_Tp2, _Cn, _Cn, _DefaultVal2>& __rhs) noexcept
    { return semiring_multiply_inplace(__rhs, std::plus{}, std::multiplies{}); }

private:

    container_type _M_m;
};
}} // namespace huanhuanonly::math

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;

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

    struct node
    {
        int size;
        int head;
        int wson;
        int fa;
    };

    std::vector<node> tree(n + 1);

    std::vector<int> cnt(n + 1);
    std::vector<int> pos(n + 1);

    auto build = [&](const auto& self, int u) -> void
    {
        tree[u].size = 1;

        for (const auto& v : e[u])
        {
            if (v != tree[u].fa)
            {
                tree[v].fa = u;
                self(self, v);
                tree[u].size += tree[v].size;

                if (tree[v].size > tree[tree[u].wson].size)
                {
                    tree[u].wson = v;
                }
            }
        }
    };

    auto decompose = [&](const auto& self, int u, int head) -> void
    {
        tree[u].head = head;

        pos[u] = cnt[head];
        ++cnt[head];

        if (tree[u].wson)
        {
            self(self, tree[u].wson, head);

            for (const auto& v : e[u])
            {
                if (v != tree[u].fa and v != tree[u].wson)
                {
                    self(self, v, v);
                }
            }
        }
    };

    build(build, 1);
    decompose(decompose, 1, 1);

    constexpr auto inf = std::numeric_limits<int>::max() / 2;

    struct neg_inf_t
    {
        constexpr operator int() const noexcept
        { return -inf; }
    };

    using matrix22 = Matrix<int, 2, 2, neg_inf_t>;

    std::vector<std::array<int, 2>> f(n + 1), g(n + 1);

    std::vector<SegmentTree<matrix22, decltype([](const matrix22& lhs, const matrix22& rhs) {
            return rhs.semiring_multiply(lhs, std::ranges::max, std::plus{});
    })>> segs(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        segs[i].resize(cnt[i]);
    }

    auto dfs = [&](const auto& self, int u) -> void
    {
        f[u][0] = 0;
        f[u][1] = w[u];

        if (tree[u].wson)
        {
            for (const auto& v : e[u])
            {
                if (v != tree[u].fa)
                {
                    self(self, v);

                    f[u][0] += std::max(f[v][0], f[v][1]);
                    f[u][1] += f[v][0];
                }
            }

            g[u][0] = f[u][0] - std::max(f[tree[u].wson][0], f[tree[u].wson][1]);
            g[u][1] = f[u][1] - f[tree[u].wson][0];
        }
        else
        {
            g[u] = f[u];
        }

        segs[tree[u].head].set(pos[u], matrix22{{g[u][0], g[u][1]}, {g[u][0], -inf}});
    };

    dfs(dfs, 1);

    auto head_dp = [&](int head) -> std::array<int, 2>
    {
        const auto& m = segs[tree[head].head].reduce();
        return {m.at(0, 0), m.at(0, 1)};
    };

    int lastans = 0;

    while (m--)
    {
        int u, x;
        std::cin >> u >> x;

        u ^= lastans;

        g[u][1] += x - w[u];
        w[u] = x;

        for (; u; u = tree[tree[u].head].fa)
        {
            const auto oldm = head_dp(tree[u].head);

            segs[tree[u].head].set(pos[u], matrix22{{g[u][0], g[u][1]}, {g[u][0], -inf}});

            const auto newm = head_dp(tree[u].head);

            if (const int fa = tree[tree[u].head].fa)
            {
                g[fa][0] += std::max(newm[0], newm[1]) - std::max(oldm[0], oldm[1]);
                g[fa][1] += newm[0] - oldm[0];
            }
        }

        const auto m = head_dp(1);
        std::cout << (lastans = std::max(m[0], m[1])) << '\n';
    }

    return 0;
}