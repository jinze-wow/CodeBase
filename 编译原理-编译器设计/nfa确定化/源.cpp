/*1.１明确NFA的定义
一个非确定的有穷自动机(NFA)M是一个五元式：

M=(S,∑,δ,S0,F)
S是一个有限集，它额每个元素称为一个状态。
∑是一个有穷字母表，它的每个元素称为一个输入字符
δ是一个从S×∑∗至S子集额单值映射。即：δ:S×∑∗→2⋅S
S0⊆S,是一个非空的初态集
F⊂ S , 是一个终态集(可空)

1.2 定义运算
定义对状态集合I的几个有关运算：

状态集合I的ε-闭包，表示为ε-closure(I)，定义为一状态集，是状态集I中的任何状态s经任意条ε弧而能到达的状态的集合。状态集合I的任何状态s都属于ε-closure(I)。
状态集合I的a弧转换，表示为move(I,a)定义为状态集合J，其中J是所有那些可从I的某一状态经过一条a弧而到达的状态的全体。
定义Ia = ε-closure(move(I,a))
1.3 算法描述
每次从队头取出一个集合，(开始队列内只有初态集合I的ε-闭包(I) )，然后得到它对于任意一个字符a的Ia=ε−closure(move(I,a))
然后如果当前状态之前没有出现过，那么当前状态作为一个新的状态I,放入队列。
一直做如上操作，直到队列为空*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#define MAX 500
#define M 1000007

using namespace std;

struct Set
{
    set<int> elements;
    int state;
}I[MAX];

vector<int> e[MAX];
vector<int> edge[MAX];
vector<int> val1[MAX];
vector<int> val2[MAX];
vector<int> hash2[M];
vector<int> types;
int vis[MAX][MAX];
int cntp, cnts, start, finish, used[MAX];

void _clear();
void clear();
void _add(int u, int v, int x);
void add(int u, int v, int x);
void dfs(set<int>& elements, int u, int d, int flag);
void ensure();
void minimize();
int get_hash(set<int>& item);

//#define DEBUG

int main()
{
    int m;
    puts("给出NFA的边的条数:");
    while (~scanf_s("%d", &m))
    {
        _clear();
        clear();
        puts("给出NFA的始态和终态:");
        scanf_s("%d%d", &start, &finish);
        puts("给出所有的边，每行一条:");
        for (int i = 0; i < m; i++)
        {
            int u, v, x;
            scanf_s("%d%d%d", &u, &v, &x);
            _add(u, v, x);
        }
#ifdef DEBUG
        set<int> temp;
        int num[] = { 2,3,6,7,8 };
        //for ( int i = 2 ; i < 6 ; i++ )
        //    dfs ( temp , i , 0 , 2 );
        for (int i = 0; i < 5; i++)
            dfs(temp, num[i], 0, 1);
        set<int>::iterator it = temp.begin();
        for (; it != temp.end(); it++)
            printf("%d ", *it);
        puts("");
#else 
        ensure();
        puts("计算结果如下:");
        printf("%d\n", cnts);
        for (int i = 0; i < cnts; i++)
            for (int j = 0; j < edge[i].size(); j++)
                printf("edges : %d %d %d\n", i, edge[i][j], val2[i][j]);
        puts("\n给出DFA的边的条数:");
#endif
    }
}

void _clear()
{
    for (int i = 0; i < MAX; i++)
    {
        e[i].clear();
        val1[i].clear();
    }
    types.clear();
    memset(used, 0, sizeof(used));
}

void clear()
{
    for (int i = 0; i < MAX; i++)
    {
        edge[i].clear();
        val2[i].clear();
    }
}

void _add(int u, int v, int x)
{
    e[u].push_back(v);
    val1[u].push_back(x);
    if (!used[x])
    {
        types.push_back(x);
        used[x] = types.size();
    }
}

int get_hash(set<int>& item)
{
    int sum = 0;
    set<int>::iterator it = item.begin(), it1, it2;
    for (; it != item.end(); it++)
    {
        sum += (*it) * (*it) % M;
        sum %= M;
    }
    for (int i = 0; i < hash2[sum].size(); i++)
    {
        int x = hash2[sum][i];
        set<int>& temp = I[x].elements;
        it = temp.begin();
        bool flag = true;
        if (temp.size() != item.size()) continue;
        for (it1 = temp.begin(), it2 = item.begin(); it2 != item.end(); it1++, it2++)
            if (*it1 != *it2)
            {
                flag = false;
                break;
            }
        if (flag) return x;
    }
    return -1;
}

int  make_hash(set<int>& item)
{
    int sum = 0;
    set<int>::iterator it = item.begin();
    for (; it != item.end(); it++)
    {
        sum += (*it) * (*it) % M;
        sum %= M;
    }
    hash2[sum].push_back(cnts);
    return cnts++;
}

void add(int u, int v, int x)
{
    edge[u].push_back(v);
    val2[u].push_back(x);
}

void dfs(set<int>& elements, int u, int d, int flag)
{
    if (vis[u][d]) return;
    vis[u][d] = 1;
    if (d == 1) elements.insert(u);
    if (d == 2) return;
    int len = e[u].size();
    for (int i = 0; i < len; i++)
    {
        int v = e[u][i], dd;
        int x = val1[u][i];
        if (x == flag) dd = d + 1;
        else if (x == 0) dd = d;
        else continue;
        dfs(elements, v, dd, flag);
    }
}

void ensure()
{
    I[0].elements.insert(start);
    cnts = 1;
    for (int i = 0; i < cnts; i++)
    {
        set<int>& cur = I[i].elements;
        for (int j = 0; j < types.size(); j++)
        {
            if (types[j] == 0) continue;
            memset(vis, 0, sizeof(vis));
            set<int>& temp = I[cnts].elements;
            temp.clear();
            set<int>::iterator it = cur.begin();
            for (; it != cur.end(); it++)
                dfs(temp, *it, 0, types[j]);
            if (temp.empty()) continue;
            int x = get_hash(temp);
            if (x == -1)
                x = make_hash(temp);
            add(i, x, types[j]);
        }
        set<int>::iterator it = cur.begin();
        printf("I%d :", i);
        for (; it != cur.end(); it++)
            printf("%d ", *it);
        puts("");
    }
}