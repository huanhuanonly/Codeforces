/**
 * Codeforces Round 909 (Div. 3)
 * 
 * => F. Alex's whims ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1899/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/1899/submission/233906290 By huanhuanonly
 * 
 * @b Constructive and @b Trees
 * 
 * ----November 23, 2023 [19h:29m:33s]----
*/

#include <bits/stdc++.h>

using uint = unsigned;
using llong = long long;
using ullong = unsigned long long;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, q;
        std::cin >> n >> q;

        std::pair<std::list<int>, std::list<int>> tree{{ 1, 2 }, { 2 }};

        for (int i = 3; i <= n; ++i)
        {
            tree.first.push_back(i);
        }

        for (int i = 2; i <= n; ++i)
        {
            std::cout << i - 1 << ' ' << i << '\n';
        }

        int d;
        for (int i = 0; i < q; ++i)
        {
            std::cin >> d;

            if (tree.first.size() - 1 == d or tree.second.size() == d
                or (tree.second.size() > 1 and tree.first.size() - 2 + tree.second.size() - 1 == d))
            {
                std::cout << "-1 -1 -1\n";
                continue;
            }

            if (tree.first.size() - 1 > d)
            {
                auto it = std::next(tree.first.begin(), d + 1);
                std::cout << *it << ' ' << *std::prev(it) << ' ' << tree.second.back() << '\n';

                tree.second.splice(tree.second.end(), tree.first, it, tree.first.end());
            }
            else
            {
                auto it = std::prev(tree.second.end(), d - (tree.first.size() - 1));
                std::cout << *it << ' ' << *std::prev(it) << ' ' << tree.first.back() << '\n';

                tree.first.splice(tree.first.end(), tree.second, it, tree.second.end());
            }
        }
    }

    return 0;
}