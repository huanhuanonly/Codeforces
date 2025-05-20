/**
 * The 2023 Guangdong Provincial Collegiate Programming Contest
 * 
 * => E. New but Nostalgic Problem
 * 
 * -> https://codeforces.com/gym/104369/problem/E
 * 
 * Submissions ~> https://codeforces.com/gym/104369/submission/319542953 By huanhuanonly
 * 
 * @b Trie
 * 
 * ----May 14, 2025 [19h:36m:04s]----
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

class Trie
{
public:

    struct node
    {
        int word[26];
        int cnt;
        int end;
    };

    std::vector<node> tree;

    Trie() : tree(1) { }

    void insert(const std::string& s)
    {
        int now = 0;
        ++tree[now].cnt;

        for (const char c : s)
        {
            if (tree[now].word[c - 'a'] == 0)
            {
                tree[now].word[c - 'a'] = tree.size();
                tree.push_back({});
            }

            now = tree[now].word[c - 'a'];
            ++tree[now].cnt;
        }

        ++tree[now].end;
    }

    std::string find(int k)
    {
        int now = 0;

        std::string path;

        while (true)
        {
            bool flag = true;
            int cnt = tree[now].end;
            for (int i = 0; i < 26; ++i)
            {
                if (tree[now].word[i])
                {
                    ++cnt;

                    flag = flag and tree[tree[now].word[i]].cnt == 1;
                }
            }

            if (flag or k <= cnt)
            {
                break;
            }

            for (int i = 0; i < 26; ++i)
            {
                if (tree[now].word[i])
                {
                    --cnt;

                    if (tree[tree[now].word[i]].cnt >= k - cnt)
                    {
                        if ((k -= cnt) == 1)
                        {
                            flag = true;
                            break;
                        }

                        now = tree[now].word[i];
                        path.push_back('a' + i);
                        break;
                    }

                    k -= tree[tree[now].word[i]].cnt;
                }
            }

            if (flag)
            {
                break;
            }
        }

        return path;
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, k;
        std::cin >> n >> k;

        Trie trie;

        std::string s;
        
        for (int i = 0; i < n; ++i)
        {
            std::cin >> s;

            trie.insert(s);
        }

        auto&& path = trie.find(k);

        if (path.empty())
            std::cout << "EMPTY\n";
        else
            std::cout << path << '\n';
    }

    return 0;
}