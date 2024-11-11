/**
 * 2024 China Collegiate Programming Contest (CCPC) Female Onsite (2024年中国大学生程序设计竞赛女生专场)
 * 
 * => K. Xiao Kai's Dream of Provincial Scholarship
 * 
 * -> https://codeforces.com/gym/105487/problem/K
 * 
 * Submissions ~> https://codeforces.com/gym/105487/submission/290870977 By huanhuanonly
 * 
 * Submitted during the competition, nothing changed
 * https://pintia.cn/rankings/1851178571429322752?footer=false
 * 
 * @b Implementation
 * 
 * ----November 3, 2024 [13h:55m:01s]----
*/

#include <bits/stdc++.h>

using uint64 = unsigned long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    int n;
    std::cin >> n;

    struct Data
    {
        std::string name;
        int aa, ab, ac;
        int ba, bb, bc;
        int jiang;
    };

    std::vector<Data*> v(n);

    std::vector<int*> zy1, zy2;

    Data* me;

    for (int i = 0; i < n; ++i)
    {
        v[i] = new Data;

        std::cin >> v[i]->name;
        std::cin >> v[i]->aa >> v[i]->ab >> v[i]->ac;
        std::cin >> v[i]->ba >> v[i]->bb >> v[i]->bc;

        zy1.push_back(&v[i]->aa);
        zy2.push_back(&v[i]->ba);

        if (v[i]->name == "crazyzhk")
            me = v[i];
    }

    auto intcmp = [](int* lv, int* rv) -> bool
    {
        return *lv > *rv;
    };

    int m, one, two;
    std::cin >> m >> one >> two;

    auto check = [&](int add_a, int add_b) -> bool
    {
        me->aa += add_a;
        me->ba += add_b;

        std::sort(zy1.begin(), zy1.end(), intcmp);
        std::sort(zy2.begin(), zy2.end(), intcmp);

        for (int i = 0; i < n; ++i)
        {
            v[i]->jiang = 0;
        }

        int sa = 0, sb = 0, sc = 0;

        std::sort(v.begin(), v.end(), [](const Data* lv, const Data* rv) -> bool
        {
            int sum_a = lv->aa + lv->ab + lv->ac;
            int sum_b = rv->aa + rv->ab + rv->ac;

            if (sum_a != sum_b)
                return sum_a > sum_b;
            
            if (lv->aa != rv->aa)
                return lv->aa > rv->aa;
            
            return lv->name < rv->name;
        });

        for (int i = 0; i < n; ++i)
        {
            if (std::lower_bound(zy1.begin(), zy1.end(), &v[i]->aa, intcmp) - zy1.begin() + 1 <= int((long double)(n) * 0.25) and
                sa + 1 <= int((long double)(n) * 0.15))
            {
                ++sa;
                v[i]->jiang += 15;
            }
            else if (std::lower_bound(zy1.begin(), zy1.end(), &v[i]->aa, intcmp) - zy1.begin() + 1 <= int((long double)(n) * 0.45) and
                sb + 1 <= int((long double)(n) * 0.25))
            {
                ++sb;
                v[i]->jiang += 10;
            }
            else if (std::lower_bound(zy1.begin(), zy1.end(), &v[i]->aa, intcmp) - zy1.begin() + 1 <= int((long double)(n) * 0.75) and
                sc + 1 <= int((long double)(n) * 0.35))
            {
                ++sc;
                v[i]->jiang += 5;
            }
        }

        sa = 0, sb = 0, sc = 0;

        std::sort(v.begin(), v.end(), [](const Data* lv, const Data* rv) -> bool
        {
            int sum_a = lv->ba + lv->bb + lv->bc;
            int sum_b = rv->ba + rv->bb + rv->bc;

            if (sum_a != sum_b)
                return sum_a > sum_b;
            
            if (lv->ba != rv->ba)
                return lv->ba > rv->ba;
            
            return lv->name < rv->name;
        });

        for (int i = 0; i < n; ++i)
        {
            if (std::lower_bound(zy2.begin(), zy2.end(), &v[i]->ba, intcmp) - zy2.begin() + 1 <= int((long double)(n) * 0.25) and
                sa + 1 <= int((long double)(n) * 0.15))
            {
                ++sa;
                v[i]->jiang += 15;
            }
            else if (std::lower_bound(zy2.begin(), zy2.end(), &v[i]->ba, intcmp) - zy2.begin() + 1 <= int((long double)(n) * 0.45) and
                sb + 1 <= int((long double)(n) * 0.25))
            {
                ++sb;
                v[i]->jiang += 10;
            }
            else if (std::lower_bound(zy2.begin(), zy2.end(), &v[i]->ba, intcmp) - zy2.begin() + 1 <= int((long double)(n) * 0.75) and
                sc + 1 <= int((long double)(n) * 0.35))
            {
                ++sc;
                v[i]->jiang += 5;
            }
        }

        std::sort(v.begin(), v.end(), [](const Data* lv, const Data* rv) -> bool
        {
            if (lv->jiang != rv->jiang)
                return lv->jiang > rv->jiang;
            
            int sum_a = lv->aa + lv->ab + lv->ac + lv->ba + lv->bb + lv->bc;
            int sum_b = rv->aa + rv->ab + rv->ac + rv->ba + rv->bb + rv->bc;

            if (sum_a != sum_b)
                return sum_a > sum_b;
            
            if (lv->aa + lv->ba != rv->aa + rv->ba)
                return lv->aa + lv->ba > rv->aa + rv->ba;
            
            return lv->name < rv->name;
        });

        bool found = false;

        for (int i = 0; i < m; ++i)
        {
            if (v[i]->name == "crazyzhk")
            {
                found = true;
                break;
            }
        }

        me->aa -= add_a;
        me->ba -= add_b;

        return found;
    };

    int ans = INT_MAX;

    // std::cout << check(26, 25);

    // return 0;

    if (m == 0)
    {
        std::cout << "Surely next time";
        return 0;
    }
    else if (m == n)
    {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i <= 100 - me->aa; ++i)
    {
        for (int j = 0; j <= 100 - me->ba; ++j)
        {
            if (check(i, j))
            {
                ans = std::min(ans, i * one + j * two);
            }
        }
    }

    if (ans != INT_MAX)
        std::cout << ans;
    else
        std::cout << "Surely next time";

    return 0;
}