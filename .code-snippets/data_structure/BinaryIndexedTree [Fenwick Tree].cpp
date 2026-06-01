template<
    typename _Tp,
    typename _BinaryOperation = std::plus<_Tp>,
    typename _InverseBinaryOperation = std::minus<_Tp>>
class BinaryIndexedTree
{
public:

    using value_type = _Tp;
    using size_type = int;

    explicit constexpr
    BinaryIndexedTree(size_type __n = 0, value_type __identity = {}) noexcept
        : _M_BITree(__n + 1, __identity), _M_op{}, _M_inv_op{}
    { }

    constexpr
    BinaryIndexedTree(size_type __n, value_type __identity, _BinaryOperation __op, _InverseBinaryOperation __inv_op) noexcept
        : _M_BITree(__n + 1, __identity), _M_op(__op), _M_inv_op(__inv_op)
    { }

    [[nodiscard]] static constexpr size_type
    lowbit(size_type __x) noexcept
    { return __x & -__x; }

    constexpr void
    add(size_type __i, value_type __value) noexcept
    {
        for (++__i; __i < _M_BITree.size(); __i += lowbit(__i))
        {
            _M_BITree[__i] = _M_op(_M_BITree[__i], __value);
        }
    }

    constexpr void
    subtract(size_type __i, value_type __value) noexcept
    {
        for (++__i; __i < _M_BITree.size(); __i += lowbit(__i))
        {
            _M_BITree[__i] = _M_inv_op(_M_BITree[__i], __value);
        }
    }

    [[nodiscard]] constexpr value_type
    prefix_sum(size_type __r) const noexcept
    {
        value_type result = _M_BITree[++__r];

        for (__r -= lowbit(__r); __r; __r -= lowbit(__r))
        {
            result = _M_op(_M_BITree[__r], result);
        }

        return result;
    }

    [[nodiscard]] constexpr value_type
    sum(size_type __l, size_type __r) const noexcept
    { return __l ? _M_inv_op(prefix_sum(__r), prefix_sum(__l - 1)) : prefix_sum(__r); }

    [[nodiscard]] constexpr value_type
    sum() const noexcept
    { return sum(0, size() - 1); }

    [[nodiscard]] constexpr value_type
    get(size_type __i) const noexcept
    { return sum(__i, __i); }

    constexpr void
    set(size_type __i, value_type __value) noexcept
    { reset(__i), add(__i, __value); }

    constexpr void
    reset(size_type __i) noexcept
    { subtract(__i, get(__i)); }

    constexpr void
    reset() noexcept
    { for (size_type i = 0; i < size(); reset(i), ++i); }

    [[nodiscard]] constexpr size_type
    size() const noexcept
    { return static_cast<size_type>(_M_BITree.size()) - 1; }

    [[nodiscard]] constexpr bool
    empty() const noexcept
    { return size() == 0; }

    constexpr void
    resize(size_type __n) noexcept
    { _M_BITree.resize(__n + 1); }

private:

    std::vector<value_type> _M_BITree;

    _BinaryOperation _M_op;
    _InverseBinaryOperation _M_inv_op;
};