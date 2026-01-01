/**
 * Codeforces Round 874 (Div. 3)
 * 
 * => E. Round Dance ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1833/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1833/submission/250576485 By huanhuanonly
 * 
 * @b Disjoint-set and @b Graphs
 * 
 * ----March 11, 2024 [11h:36m:16s]----
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

class DisjointSet
{
public:
	std::vector<int> tree;

	explicit DisjointSet(std::size_t n)
		: tree(n + 1)
	{
		std::iota(tree.begin(), tree.end(), 0);
	}

	int find(int p)
	{
		return tree[p] == p ? p : tree[p] = find(tree[p]);
	}

	void merge(int x, int y)
	{
		tree[find(y)] = find(x);
	}
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
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

		int mx = 0, mn = 0;

		std::vector<bool> vis(n + 1);

		std::function<bool(int)> dfs = [&](int p) -> bool
		{
			for (int i = 1, x = p; ; ++i)
			{
				x = v[x];

				if (vis[x])
				{
					return x == p and i > 2;
				}

				vis[x] = true;
			}
		};

		bool found = false;
		for (int i = 1; i <= n; ++i)
		{
			if (vis[i] == false)
			{
				vis[i] = true;
				if (dfs(i))
					++mn;
				else
					found = true;
			}
		}

		DisjointSet ds(n);

		for (int i = 1; i <= n; ++i)
		{
			if (ds.find(i) != ds.find(v[i]))
				ds.merge(i, v[i]);
			else
				++mx;
		}

		std::cout << std::max(mn + found, 1) << ' ' << mx << '\n';
	}

    return 0;
}