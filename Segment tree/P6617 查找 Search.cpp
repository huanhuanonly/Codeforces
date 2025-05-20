/**
 * => P6617 查找 Search ( @c 省选/NOI- )
 * 
 * -> https://www.luogu.com.cn/problem/P6617
 * 
 * Submissions ~> https://www.luogu.com.cn/record/214711134 By huanhuanonly
 * 
 * @b Segment-tree to find the maximum value of interval
 * 
 * ----April 22, 2025 [17h:22m:58s]----
*/

/// @brief This is an @c interesting problem!

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

class SegmentTree
{
public:

    std::vector<int> tree;

    explicit SegmentTree(int n) : tree(n << 2) { }

    static int ls(int p) { return p << 1; }
    static int rs(int p) { return p << 1 | 1; }

    void push_up(int p)
    {
        tree[p] = std::max(tree[ls(p)], tree[rs(p)]);
    }

    void set_value(int p, int l, int r, int pos, int value)
    {
        if (l == r)
        {
            tree[p] = value;
            return;
        }

        int mid = l + r >> 1;

        if (pos <= mid)
            set_value(ls(p), l, mid, pos, value);
        else
            set_value(rs(p), mid + 1, r, pos, value);

        push_up(p);
    }

    int max_element(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            return tree[p];
        }

        int mid = l + r >> 1;
        
        int res = 0;

        if (x <= mid)
            res = max_element(ls(p), l, mid, x, y);
        if (y > mid)
            res = std::max(res, max_element(rs(p), mid + 1, r, x, y));

        return res;
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m, w;
    std::cin >> n >> m >> w;

    std::map<int, std::set<int>> mp;

    std::vector<int> a(n + 1);
    std::vector<std::pair<int, int>> log(n + 1);
    
    SegmentTree seg(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];

        mp[a[i]].insert(i);
    }

    auto connect = [&](int x, int y) -> void
    {
        seg.set_value(1, 1, n, y, x);

        log[x].second = y;
        log[y].first = x;
    };
    
    auto disconnect = [&](int x, int y) -> void
    {
        if (x and y)
        {
            seg.set_value(1, 1, n, y, 0);
            log[x].second = log[y].first = 0;
        }
    };


    for (int i = 1; i <= n; ++i)
    {
        if (auto fit = mp.find(w - a[i]); fit != mp.end())
        {
            auto& st = fit->second;

            if (auto it = st.upper_bound(i); it != st.end())
            {
                if (auto next_it = std::next(mp[a[i]].find(i)); next_it == mp[a[i]].end() or *next_it >= *it)
                {
                    connect(i, *it);
                }
            }
        }
    }

    int cnt = 0;

    while (m--)
    {
        int opt;
        std::cin >> opt;

        if (opt == 1)
        {
            int i, val;
            std::cin >> i >> val;

            if (a[i] == val)
            {
                continue;
            }
            
            if (mp[a[i]].size() == 1)
                mp.erase(a[i]);
            else
                mp[a[i]].erase(i);

            if (auto [prev, next] = log[i]; true)
            {
                disconnect(prev, i);
                disconnect(i, next);

                if (auto mp_it = mp.find(a[i]); mp_it != mp.end())
                {
                    auto it = mp[a[i]].upper_bound(i);

                    if (prev != 0 and it != mp[a[i]].end() and log[*it].first == 0)
                    {
                        connect(prev, *it);
                    }
    
                    if (next != 0 and it != mp[a[i]].begin() and log[*--it].second == 0)
                    {
                        connect(*it, next);
                    }
                }
            }

            a[i] = val;
            mp[a[i]].insert(i);

            if (a[i] == w - a[i])
            {
                auto& st = mp[w - a[i]];

                if (st.size() >= 2)
                {
                    auto it = st.find(i);
                    
                    if (auto next_it = std::next(it); next_it != st.end() and it != st.begin())
                    {
                        auto prev_it = std::prev(it);

                        disconnect(*prev_it, *next_it);
                        connect(*prev_it, *it);
                        connect(*it, *next_it);
                    }
                    else if (next_it != st.end())
                    {
                        connect(*it, *next_it);
                    }
                    else
                    {
                        connect(*std::prev(it), *it);
                    }
                }
            }
            else if (auto mp_fit = mp.find(w - a[i]); mp_fit != mp.end())
            {
                auto& st = mp_fit->second;
                auto fit = st.upper_bound(i);

                if (fit != st.end() and log[*fit].first < i)
                {
                    disconnect(log[*fit].first, *fit);
                    connect(i, *fit);
                }

                if (fit != st.begin())
                {
                    --fit;

                    if (log[*fit].second == 0 or log[*fit].second > i)
                    {
                        disconnect(*fit, log[*fit].second);
                        connect(*fit, i);
                    }
                }
            }
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            l ^= cnt, r ^= cnt;

            if (auto res = seg.max_element(1, 1, n, l, r); res >= l)
            {
                ++cnt;
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
        }
    }

    return 0;
}